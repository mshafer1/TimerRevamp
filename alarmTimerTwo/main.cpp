#include"clock.h"
#include<iostream>
#include<fstream>
#include <time.h>       /* time_t, struct tm, time, localtime */
#include <stdio.h>      /* puts, printf */
#include<sstream>
using namespace std;

void executeCommand(const string& command)
{
	system(command.c_str());
}

void timer(const string& command)
{
	float minutes = 0;
	char dot = '.';
	int seconds = 0;
	string line;
	cout << "Please enter the number of minutes that you would like to wait for. "
		<< "if you wish to wait for an additional number of seconds, "
		<< "enter a time point (period) then the number of seconds";
	getline(cin,line);
	if(line.length() > 0)
	{	
		if(line.find(":") != -1)
		{
			istringstream iss(line);
			iss >> minutes >> dot >> seconds;
		}
		else
		{
			minutes = atof(line.c_str());
		}
	}
	else
	{
		minutes = 5;
	}
	Clock current;
	current.wait(seconds + 60 * minutes);
}

void alarm(const string& command)
{
	int hours,seconds,minutes;
	hours = 0;
	minutes = 0;
	char dot = '.';
	seconds = 0;
	string line;
	cout << "Please enter the time you would like to wait for. ";
	getline(cin,line);
	Clock current;
	if(line.length() > 0)
	{	
		if(line.find(":") != -1)
		{
			istringstream iss(line);
			iss >> hours >> dot >>  minutes >> dot >> seconds;
		}
		else
		{
			hours = current.timeValue.hours;
			minutes = atof(line.c_str());
		}
	}
	else
	{
		hours = current.timeValue.hours+1;
		minutes = 0;
	}
	TimeValue target;
	target.hours = hours;
	target.minutes = minutes;
	target.seconds = seconds;
	current.wait(target);
}

void getCommand(string& command)
{
	bool found = false;
	int lineIndex;
	string line;
	ifstream commandLines;
	commandLines.open("Command_Lines.dat");
	while(!found && !commandLines.eof() && !commandLines.fail())
	{
		lineIndex = 1;
		getline(commandLines,line);
		//set token to an empty string.
		string token = "";			
		//and loop through line incrementing lineIndex after each character and stopping once a space character is found.
		for(; lineIndex < line.length() && (line[lineIndex] != '\"'); lineIndex++)
		{
			// each loop through, append the current charachter from line to the token.
			token += line[lineIndex];
		}
		//once token is seperated, increment lineIndex one more time to skip over space on next call.
		lineIndex++;
		found = (command == token);
	}
	commandLines.close();
	if(found)
	{
		command = "";
		for(; lineIndex+1 < line.length(); lineIndex++)
		{
			command += line[lineIndex+1];
		}
	}
	else
	{
		ofstream output;
		output.open("Command_Lines.dat",ios::app);
		cout << "Please enter appropriate system command to complete task;";
		getline(cin,line);
		output << "\"" <<  command << "\"" << " " << line << endl;
		output.close();
		command = line;
	}
}

void main()
{
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	//cout << asctime(timeinfo);

	string command;
	ifstream fin;
	fin.open("settings.dat");
	bool config = true;
	string line = "";
	if(!fin.fail())
	{
		cout << "Would you like to use current settings?:" << endl << "( ";
		while(!fin.eof())
		{
		getline(fin,command);
		cout << command << ' ';
		}
		cout << ")\n";
		fin.close();
		fin.open("settings.dat");
		cin.clear();
		getline(cin,command);
		if((command.length() == 0) || (command == "yes" || command == "Yes" || command == "y" || command == "Y"))
		{
			config = false;
		}
		else
		{
			config = true;
		}
	}
	if(config)
	{
		//configure
		fin.close();
		ofstream fout;
		fout.open("settings.dat");

		cout << "What would you like the computer to do?:" << endl;
		string query = "";
		getline(cin,query);

		command = query;
		getCommand(command);

		cout << "Would you like to use alaerm mode or timer mode? (a/t):";
		
		getline(cin,line);

		fout << command << endl << line;

	}
	else
	{
		getline(fin,command);
		getline(fin,line);
	}

	if(line.length() == 0 || line[0] == 't' || line[0] == 'T')
	{
		timer(command);
	}
	else
	{
		alarm(command);
	}  
	executeCommand(command);
}