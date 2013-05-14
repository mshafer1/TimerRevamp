#include"clock.h"
#include<iostream>
#include<fstream>
#include <time.h>       /* time_t, struct tm, time, localtime */
#include <stdio.h>      /* puts, printf */
#include<sstream>
using namespace std;

const int MAX_COMMAND_LINES = 5;

void executeCommand(const string command[])
{
	for(int i = 1; i < MAX_COMMAND_LINES && command[i].length() > 0; i++)
	{
		system(command[i].c_str());
	}
}

void timer(const string& command)
{
	float minutes = 0;
	char dot = ':';
	int seconds = 0;
	string line;
	cout << "Please enter the floating point number of minutes that you would like to wait for. "
		<< "if you wish to wait for an additional number of seconds, "
		<< "enter a colon (:) then the number of seconds";
	getline(cin,line);
	if(line.length() > 0)
	{	
		if(line.find(":") != -1)
		{
			istringstream iss(line);
			iss >> minutes ;
			iss >> dot;
			iss >> seconds;
		}
		if(line[0] == ':')
		{
			string lines = "";
			for(int i = 1; i < 79 && i < line.length(); i++)
			{
				lines += line[i];
			}
			seconds = atof(lines.c_str());
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
	system("cls");
	cout << command << endl;
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
		hours = current.timeValue.hours;
		minutes = 50;
	}
	TimeValue target;
	target.hours = hours;
	target.minutes = minutes;
	target.seconds = seconds;
	system("cls");
	cout << command << endl;
	current.wait(target);
}

void getCommand(string command[])
{
	bool found = false;
	int lineIndex;
	string line;
	string option = command[0];
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
		found = (command[0] == token);
		if(found)
		{
			for(int i = 0; i < MAX_COMMAND_LINES && line.length() > 0; i++)
			{
				command[i] = "";
				string commandLine;
				command[i] = line;
				getline(commandLines,line);
			}
		}
	}
	commandLines.close();
	
	if(!found)
	{
		ofstream output;
		output.open("Command_Lines.dat",ios::app);
		cout << "Please enter appropriate system command to complete task;";
		line = "blah";
		for(int i = 1; i < MAX_COMMAND_LINES && line.length() > 0; i++)
		{
			getline(cin,line);
			command[i] = "";
			char commandLine[80];
			strcpy(commandLine,line.c_str());
			command[i] = commandLine;
		}

		output << "\"" <<  option << "\"";
		for(int i = 0; i < MAX_COMMAND_LINES && command[i].length() > 0; i++)
		{
			output << " " << command[i] << endl;
		}
		output.close();
	}
}

void main()
{
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	//cout << asctime(timeinfo);

	string command[MAX_COMMAND_LINES];
	ifstream fin;
	fin.open("settings.dat");
	bool config = true;
	string line = "";
	string query = "";
	if(!fin.fail())
	{
		cout << "Would you like to use current settings?:" << endl << "( ";
		while(!fin.eof())
		{
		getline(fin,command[0]);
		cout << command[0] << ' ';
		}
		cout << ")\n";
		fin.close();
		fin.open("settings.dat");
		cin.clear();
		getline(cin,command[0]);
		if((command[0].length() == 0) || (command[0] == "yes" || command[0] == "Yes" || command[0][0] == 'y' || command[0][0] == 'Y'))
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
		
		getline(cin,query);

		command[0] = query;
		getCommand(command);

		cout << "Would you like to use alarm mode or timer mode? (a/t):";
		
		getline(cin,line);

		fout << query << endl << line;

	}
	else
	{
		getline(fin,query);
		command[0] = query;
		getCommand(command);
		getline(fin,line);
		//getline(fin,query);
	}

	if(line.length() == 0 || line[0] == 't' || line[0] == 'T')
	{
		timer(query);
	}
	else
	{
		alarm(query);
	}  
	executeCommand(command);
}