#include <iostream>
using namespace std;

class Time{
	public:
	int hour;
	int minute;
	string print;
	
	Time(){}
	Time(Time* t){
		hour = t->hour;
		minute = t->minute;
		print = t->print;
	}
	Time(string time){
		print = time;
		string temp;
	       	temp.push_back(time[0]);
		temp.push_back(time[1]);
		hour = stoi(temp);
		temp = "";
		temp.push_back(time[3]);
		temp.push_back(time[4]);
		minute = stoi(temp);

		if(time[5]=='p' and hour !=12){
			hour+=12;
		}
		if(time[5]=='a' and hour == 12){
			hour= hour -12;
		}
	}
	friend bool operator>(Time &x,Time &y){
		if(x.hour>y.hour){
			return true;
		}if(x.hour<y.hour){
			return false;
		}else{
			if(x.minute>y.minute){
				return true;
			}else{
				return false;
			}
		}
	}
	friend bool operator<(Time &x,Time &y){
		if(x.hour<y.hour){
			return true;
		}if(x.hour>y.hour){
			return false;
		}else{
			if(x.minute<y.minute){
				return true;
			}else{
				return false;
			}
		}
	}
	friend ostream& operator<<(ostream&os, const Time& t){
		os<<t.print;
		return os;
	}
	Time& operator=(const Time& y){
		hour = y.hour;
		minute = y.minute;
		print = y.print;
		return *this;
	}
};
