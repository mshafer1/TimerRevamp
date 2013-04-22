#include"clock.h"
#include<iostream>
#include<fstream>
#include <time.h>       /* time_t, struct tm, time, localtime */
#include <stdio.h>      /* puts, printf */
using namespace std;

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
	cout << asctime(timeinfo);

	string command;
	ifstream fin;
	fin.open("settings.dat");
	bool config = true;
	string line = "";
	if(!fin.fail())
	{
		cout << "Would you like to use current settings?:" << endl << "(" << endl;
		do
		{
		getline(fin,command);
		cout << command << endl;
		}while(!fin.eof());
		fin.close();
		fin.open("settings.dat");
		cin.clear();
		getline(cin,command);
		if((command.length() > 0) && (command == "yes" || command == "Yes" || command == "y" || command == "Y"))
		{
			config = true;
		}
		else
		{
			config = false;
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
		fin >> command;
		fin >> line;
	}

	if(line[0] == 't' || line[0] == 'T')
	{
		timer();
	}
	else
	{
		alarm();
	}  
}