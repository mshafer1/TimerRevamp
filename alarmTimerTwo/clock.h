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
	short seconds;
	short minutes;
	short hours;
	int days;
	int years;
	string month;
	int monthDay;
	int total;
	void update();
	void updateTotal();
	int difference;
	void updateCount();
	void display();
	void displayB();
	void normalize();
private:
};

struct Clock
{
public:
	Clock();
	void update();
	void wait(int secondsToWait);
	void wait(TimeValue target);
	TimeValue timeValue;
	int total();
private:

};