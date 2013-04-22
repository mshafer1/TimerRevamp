#include"clock.h"

	const int INITIAL_YEAR = 1970;
	const int INITIAL_YEAR_Add = 1900;
	const int SECONDS_IN_A_YEAR = 31557600;
	const int SECONDS_IN_A_DAY = 86400;
	const int SECONDS_IN_A_HOUR = 3600;
	const int SECONDS_IN_A_MINUTE = 60;

TimeValue::TimeValue()
{

	time_t now;
	struct tm current;
	struct tm blah;
	now = time(NULL);
	blah = *gmtime(&now);// = localtime(&now);
	current = *localtime(&now);
	if(blah.tm_yday==current.tm_yday)
	{
		difference = blah.tm_hour-current.tm_hour;
	}
	else
	{
		difference = (blah.tm_yday-current.tm_yday)*24-(current.tm_hour-blah.tm_hour);
	}
	//seconds = time(NULL);
	total = ((((INITIAL_YEAR_Add+current.tm_year-INITIAL_YEAR))*SECONDS_IN_A_YEAR) +(current.tm_yday)*SECONDS_IN_A_DAY+current.tm_hour*SECONDS_IN_A_HOUR + current.tm_min*SECONDS_IN_A_MINUTE + current.tm_sec);

	years = current.tm_year+INITIAL_YEAR_Add;
	days = current.tm_yday;
	hours = current.tm_hour;
	minutes = current.tm_min;
	seconds = current.tm_sec;
	//hours -= difference;

	//seconds = temp;
	if(days <= 31)
	{
		month = "January";
	}
	else if(days <= 59)
	{
		month = "February";
	}
	else if(days <= 90)
	{
		month = "March";
	}
	else if(days <= 120)
	{
		month = "April";
	}
	else if(days <= 151)
	{
		month = "May";
	}
	else if(days <= 181)
	{
		month = "June";
	}
	else if(days <= 212)
	{
		month = "July";
	}
	else if(days <= 243)
	{
		month = "August";
	}
	else if(days <= 273)
	{
		month = "September";
	}
	else if(days <= 304)
	{
		month = "October";
	}
	else if(days <= 334)
	{
		month = "November";
	}
	else
	{
		month = "December";
	}
	monthDay = current.tm_mday;
}

void TimeValue::update()
{
	time_t now;
	struct tm current;
	struct tm blah;
	now = time(NULL);
	blah = *gmtime(&now);// = localtime(&now);
	current = *localtime(&now);
	if(blah.tm_yday==current.tm_yday)
	{
		difference = blah.tm_hour-current.tm_hour;
	}
	else
	{
		difference = (blah.tm_yday-current.tm_yday)*24-(current.tm_hour-blah.tm_hour);
	}
	//seconds = time(NULL);
	total = ((((INITIAL_YEAR_Add+current.tm_year-INITIAL_YEAR))*SECONDS_IN_A_YEAR) +(current.tm_yday)*SECONDS_IN_A_DAY+current.tm_hour*SECONDS_IN_A_HOUR + current.tm_min*SECONDS_IN_A_MINUTE + current.tm_sec);

	years = current.tm_year+INITIAL_YEAR_Add;
	days = current.tm_yday;
	hours = current.tm_hour;
	minutes = current.tm_min;
	seconds = current.tm_sec;
	//hours -= difference;

	//seconds = temp;
	if(days <= 31)
	{
		month = "January";
	}
	else if(days <= 59)
	{
		month = "February";
	}
	else if(days <= 90)
	{
		month = "March";
	}
	else if(days <= 120)
	{
		month = "April";
	}
	else if(days <= 151)
	{
		month = "May";
	}
	else if(days <= 181)
	{
		month = "June";
	}
	else if(days <= 212)
	{
		month = "July";
	}
	else if(days <= 243)
	{
		month = "August";
	}
	else if(days <= 273)
	{
		month = "September";
	}
	else if(days <= 304)
	{
		month = "October";
	}
	else if(days <= 334)
	{
		month = "November";
	}
	else
	{
		month = "December";
	}
	monthDay = current.tm_mday;
}

void TimeValue::updateCount()
{
	
	int temp = total;
	years = temp/SECONDS_IN_A_YEAR + INITIAL_YEAR;
	temp %= SECONDS_IN_A_YEAR;

	days = temp/SECONDS_IN_A_DAY;
	temp %= SECONDS_IN_A_DAY;

	hours = temp/SECONDS_IN_A_HOUR;
	//hours -= difference;
	temp %= SECONDS_IN_A_HOUR;

	minutes = temp/SECONDS_IN_A_MINUTE;
	temp %= SECONDS_IN_A_MINUTE;

	seconds = temp;
	if(days <= 31)
	{
		month = "January";
	}
	else if(days <= 59)
	{
		month = "February";
	}
	else if(days <= 90)
	{
		month = "March";
	}
	else if(days <= 120)
	{
		month = "April";
	}
	else if(days <= 151)
	{
		month = "May";
	}
	else if(days <= 181)
	{
		month = "June";
	}
	else if(days <= 212)
	{
		month = "July";
	}
	else if(days <= 243)
	{
		month = "August";
	}
	else if(days <= 273)
	{
		month = "September";
	}
	else if(days <= 304)
	{
		month = "October";
	}
	else if(days <= 334)
	{
		month = "November";
	}
	else
	{
		month = "December";
	}
}

void TimeValue::updateTotal()
{
	total = (years-INITIAL_YEAR)*SECONDS_IN_A_YEAR + days*SECONDS_IN_A_DAY + hours * SECONDS_IN_A_HOUR + minutes*SECONDS_IN_A_MINUTE + seconds;
}

Clock::Clock()
{
}

void Clock::wait(TimeValue target)
{
	target.updateTotal();
	cout << "Waiting For: ";
	target.display();
	cout << endl;
	cout << "Current Time: ";
	while(timeValue.total < target.total)
	{
		timeValue.displayB();
		Sleep(999);
		timeValue.update();
	}
	timeValue.display();
}

void Clock::update()
{
	timeValue.update();
}

void TimeValue::normalize()
{
	time_t current;
	time(&current);
	struct tm* Total = localtime(&current);

	while(seconds >= 60)
	{
		seconds-=60;
		minutes++;
	}
	while(seconds < 0)
	{
		seconds+=60;
		minutes--;
	}

	while(minutes >= 60)
	{
		minutes-=60;
		hours++;
	}
	while(minutes < 0)
	{
		minutes+= 60;
		hours--;
	}

	monthDay = Total->tm_mday;

	while(hours >= 24)
	{
		hours-=24;
		days++;
		monthDay++;
	}
	while(hours < 0)
	{
		hours+=24;
		days--;
		monthDay--;
	}

	if(days <= 31)
	{
		month = "January";
	}
	else if(days <= 59)
	{
		month = "February";
	}
	else if(days <= 90)
	{
		month = "March";
	}
	else if(days <= 120)
	{
		month = "April";
	}
	else if(days <= 151)
	{
		month = "May";
	}
	else if(days <= 181)
	{
		month = "June";
	}
	else if(days <= 212)
	{
		month = "July";
	}
	else if(days <= 243)
	{
		month = "August";
	}
	else if(days <= 273)
	{
		month = "September";
	}
	else if(days <= 304)
	{
		month = "October";
	}
	else if(days <= 334)
	{
		month = "November";
	}
	else
	{
		month = "December";
	}
}

void TimeValue::display()
{
	normalize();
	int lineLength = 0;
	if(hours < 10)
	{
		cout << '0';
	}
	cout << hours; 
	cout << ":";
	if(minutes < 10)
	{
		cout << '0';
	}
	cout << minutes << ":";
	if(seconds < 10)
	{
		cout << '0';
	}
	cout << seconds << " ";
	cout << month << " ";
	if(monthDay < 10)
	{
		cout << '0';
	}
	cout << monthDay << ", ";
	cout << years;
	lineLength += 18 + month.length();
}

void TimeValue::displayB()
{
	normalize();
	int lineLength = 0;
	if(hours < 10)
	{
		cout << '0';
	}
	cout << hours; 
	cout << ":";
	if(minutes < 10)
	{
		cout << '0';
	}
	cout << minutes << ":";
	if(seconds < 10)
	{
		cout << '0';
	}
	cout << seconds << " ";
	cout << month << " ";
	if(monthDay < 10)
	{
		cout << '0';
	}
	cout << monthDay << ", ";
	cout << years;
	lineLength +=18 + month.length();
	for(int i = 0; i < lineLength; i++)
	{
		cout << "\b";
	}
}

void Clock::wait(int secondsToWait)
{
	TimeValue target;
	target.total+=secondsToWait;
	target.updateCount();
	cout << "Waiting For: ";
	target.display();
	cout << endl;
	cout << "Current Time: ";
	while(timeValue.total < target.total)
	{
		timeValue.displayB();
		Sleep(999);
		timeValue.update();
	}
	timeValue.display();
}

int Clock::total()
{
	return timeValue.total;
}