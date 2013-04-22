#include"clock.h"


TimeValue::TimeValue()
{
	const int INITIAL_YEAR = 1970;
	const int SECONDS_IN_A_YEAR = 31557600;
	const int SECONDS_IN_A_DAY = 86400;
	const int SECONDS_IN_A_HOUR = 3600;
	const int SECONDS_IN_A_MINUTE = 60;
	int initial = time(NULL);
	total = initial;
	years = initial/SECONDS_IN_A_YEAR + INITIAL_YEAR;
	initial %= SECONDS_IN_A_YEAR;

	days = initial/SECONDS_IN_A_DAY;
	initial %= SECONDS_IN_A_DAY;

	hours = initial/SECONDS_IN_A_HOUR;
	initial %= SECONDS_IN_A_HOUR;

	minutes = initial/SECONDS_IN_A_MINUTE;
	initial %= SECONDS_IN_A_MINUTE;

	seconds = initial;
	if(days <= 31)
	{
		month = "January";
		monthDay = days;
	}
	else if(days <= 59)
	{
		month = "February";
		monthDay = days - 31;
	}
	else if(days <= 90)
	{
		month = "March";
		monthDay = days - 58;
	}
	else if(days <= 120)
	{
		month = "April";
		monthDay = days - 90;
	}
	else if(days <= 151)
	{
		month = "May";
		monthDay = days - 120;
	}
	else if(days <= 181)
	{
		month = "June";
		monthDay = days - 151;
	}
	else if(days <= 212)
	{
		month = "July";
		monthDay = days - 181;
	}
	else if(days <= 243)
	{
		month = "August";
		monthDay = days - 212;
	}
	else if(days <= 273)
	{
		month = "September";
		monthDay = days - 243;
	}
	else if(days <= 304)
	{
		month = "October";
		monthDay = days - 273;
	}
	else if(days <= 334)
	{
		month = "November";
		monthDay = days - 304;
	}
	else
	{
		month = "December";
		monthDay = days - 334;
	}
}

TimeValue::TimeValue(int initial)
{
	total = initial;
	const int INITIAL_YEAR = 1980;
	const int SECONDS_IN_A_YEAR = 315554400;
	const int SECONDS_IN_A_DAY = 31557600;
	const int SECONDS_IN_A_HOUR = 3600;
	const int SECONDS_IN_A_MINUTE = 60;
	years = initial/SECONDS_IN_A_YEAR;
	initial %= SECONDS_IN_A_YEAR;

	days = initial/SECONDS_IN_A_DAY;
	initial %= SECONDS_IN_A_DAY;

	hours = initial/SECONDS_IN_A_HOUR;
	initial %= SECONDS_IN_A_HOUR;

	minutes = initial/SECONDS_IN_A_MINUTE;
	initial %= SECONDS_IN_A_MINUTE;

	seconds = initial;
	if(days <= 31)
	{
		month = "January";
		monthDay = days;
	}
	else if(days <= 59)
	{
		month = "February";
		monthDay = days - 31;
	}
	else if(days <= 90)
	{
		month = "March";
		monthDay = days - 58;
	}
	else if(days <= 120)
	{
		month = "April";
		monthDay = days - 90;
	}
	else if(days <= 151)
	{
		month = "May";
		monthDay = days - 120;
	}
	else if(days <= 181)
	{
		month = "June";
		monthDay = days - 151;
	}
	else if(days <= 212)
	{
		month = "July";
		monthDay = days - 181;
	}
	else if(days <= 243)
	{
		month = "August";
		monthDay = days - 212;
	}
	else if(days <= 273)
	{
		month = "September";
		monthDay = days - 243;
	}
	else if(days <= 304)
	{
		month = "October";
		monthDay = days - 273;
	}
	else if(days <= 334)
	{
		month = "November";
		monthDay = days - 304;
	}
	else
	{
		month = "December";
		monthDay = days - 334;
	}
}

void TimeValue::update()
{
	const int INITIAL_YEAR = 1980;
	const int SECONDS_IN_A_YEAR = 315554400;
	const int SECONDS_IN_A_DAY = 31557600;
	const int SECONDS_IN_A_HOUR = 3600;
	const int SECONDS_IN_A_MINUTE = 60;
	int initial = time(NULL);
	total = initial;
	years = initial/SECONDS_IN_A_YEAR;
	initial %= SECONDS_IN_A_YEAR;

	days = initial/SECONDS_IN_A_DAY;
	initial %= SECONDS_IN_A_DAY;

	hours = initial/SECONDS_IN_A_HOUR;
	initial %= SECONDS_IN_A_HOUR;

	minutes = initial/SECONDS_IN_A_MINUTE;
	initial %= SECONDS_IN_A_MINUTE;

	seconds = initial;
	if(days <= 31)
	{
		month = "January";
		monthDay = days;
	}
	else if(days <= 59)
	{
		month = "February";
		monthDay = days - 31;
	}
	else if(days <= 90)
	{
		month = "March";
		monthDay = days - 58;
	}
	else if(days <= 120)
	{
		month = "April";
		monthDay = days - 90;
	}
	else if(days <= 151)
	{
		month = "May";
		monthDay = days - 120;
	}
	else if(days <= 181)
	{
		month = "June";
		monthDay = days - 151;
	}
	else if(days <= 212)
	{
		month = "July";
		monthDay = days - 181;
	}
	else if(days <= 243)
	{
		month = "August";
		monthDay = days - 212;
	}
	else if(days <= 273)
	{
		month = "September";
		monthDay = days - 243;
	}
	else if(days <= 304)
	{
		month = "October";
		monthDay = days - 273;
	}
	else if(days <= 334)
	{
		month = "November";
		monthDay = days - 304;
	}
	else
	{
		month = "December";
		monthDay = days - 334;
	}
}

Clock::Clock()
{
	timeValue = new TimeValue;
}

Clock::Clock(int initial)
{
	
}

void Clock::update()
{
	const int INITIAL_YEAR = 1980;
	const int SECONDS_IN_A_YEAR = 315554400;
	const int SECONDS_IN_A_DAY = 31557600;
	const int SECONDS_IN_A_HOUR = 3600;
	const int SECONDS_IN_A_MINUTE = 60;
	int initial = time(NULL);
	timeValue->total = initial;
	timeValue->years = initial/SECONDS_IN_A_YEAR;
	initial /= SECONDS_IN_A_YEAR;

	timeValue->days = initial/SECONDS_IN_A_DAY;
	initial /= SECONDS_IN_A_DAY;

	timeValue->hours = initial/SECONDS_IN_A_HOUR;
	initial /= SECONDS_IN_A_HOUR;

	timeValue->minutes = initial/SECONDS_IN_A_MINUTE;
	initial /= SECONDS_IN_A_MINUTE;

	timeValue->seconds = initial;
}

void Clock::update(int initial)
{
	timeValue->total = initial;
	const int INITIAL_YEAR = 1980;
	const int SECONDS_IN_A_YEAR = 315554400;
	const int SECONDS_IN_A_DAY = 31557600;
	const int SECONDS_IN_A_HOUR = 3600;
	const int SECONDS_IN_A_MINUTE = 60;

	timeValue->years = initial/SECONDS_IN_A_YEAR;
	initial /= SECONDS_IN_A_YEAR;

	timeValue->days = initial/SECONDS_IN_A_DAY;
	initial /= SECONDS_IN_A_DAY;

	timeValue->hours = initial/SECONDS_IN_A_HOUR;
	initial /= SECONDS_IN_A_HOUR;

	timeValue->minutes = initial/SECONDS_IN_A_MINUTE;
	initial /= SECONDS_IN_A_MINUTE;

	timeValue->seconds = initial;
}

void Clock::display(TimeValue target)
{
		if(target.hours< 24)
	{
		if(target.hours < 10)
		{
			cout << '0';
		}
		cout << target.hours; 
		cout << ":";
		if(target.minutes < 10)
		{
			cout << '0';
		}
		cout << target.minutes << ":";
		if(target.seconds < 10)
		{
			cout << '0';
		}
		cout << target.seconds << " ";
		cout << target.month << " ";
		if(target.monthDay < 10)
		{
			cout << '0';
		}
		cout << target.monthDay << ", ";
		cout << target.years;
		int lineLength = 18 + target.month.length();
	}
	else
	{
		target.hours -= 24;
		if(target.hours < 10)
		{
			cout << '0';
		}
		cout << target.hours;
		cout << ":";
		if(target.minutes < 10)
		{
			cout << '0';
		}
		cout << target.minutes << ":";
		if(target.seconds < 10)
		{
			cout << '0';
		}
		cout << target.seconds << " ";
		cout << target.month << " ";
		target.monthDay++;
		if(target.monthDay < 10)
		{
			cout << '0';
		}
		cout << target.monthDay << ", ";
		cout << target.years;
	}
}

void Clock::displayB(TimeValue target)
{

	if(target.hours< 24)
	{
		if(target.hours < 10)
		{
			cout << '0';
		}
		cout << target.hours; 
		cout << ":";
		if(target.minutes < 10)
		{
			cout << '0';
		}
		cout << target.minutes << ":";
		if(target.seconds < 10)
		{
			cout << '0';
		}
		cout << target.seconds << " ";
		cout << target.month << " ";
		if(target.monthDay < 10)
		{
			cout << '0';
		}
		cout << target.monthDay << ", ";
		cout << target.years + 1970;
		int lineLength = 18 + target.month.length();
		for(int i = 0; i < lineLength; i++)
		{
			cout << "\b";
		}
	}
	else
	{
		target.hours -= 24;
		if(target.hours < 10)
		{
			cout << '0';
		}
		cout << target.hours; 
		cout << ":";
		if(target.minutes < 10)
		{
			cout << '0';
		}
		cout << target.minutes << ":";
		if(target.seconds < 10)
		{
			cout << '0';
		}
		cout << target.seconds << " ";
		cout << target.month << " ";
		target.monthDay++;
		if(target.monthDay < 10)
		{
			cout << '0';
		}
		cout << target.monthDay << ", ";
		cout << target.years + 1970;
		int lineLength = 18 + target.month.length();
		for(int i = 0; i < lineLength; i++)
		{
			cout << "\b";
		}
	}
}

void Clock::wait(TimeValue target)
{
	TimeValue current;
	int last = current.total;
	cout << "Waiting for: ";
	display(target);
	while(current.total < target.total)
	{
		if(last == current.total)
		{
			Sleep(999);
			current.update();
		}
		else
		{
			displayB(current);
		}
	}
}