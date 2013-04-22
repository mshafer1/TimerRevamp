#include<iostream>
#include<string>
#include<time.h>
#include<windows.h>
using std::cout;
using std::string;
using namespace std;

struct TimeValue
{
public:
	TimeValue();
	TimeValue(int initial);
	short seconds;
	short minutes;
	short hours;
	int days;
	int years;
	string month;
	int monthDay;
	int total;
	void update();
private:
};

struct Clock
{
public:
	Clock();
	Clock(int initial);
	void update();
	void update(int initial);
	void wait(TimeValue target);
	void display(TimeValue target);
	void displayB(TimeValue target);
	TimeValue* timeValue;
private:
};