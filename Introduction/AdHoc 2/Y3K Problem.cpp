#include <bits/stdc++.h>
using namespace std;

class Date{
public:
	int day;
	int month;
	int year;
	Date(int d, int m, int y){
		day = d;
		month = m;
		year = y;
	}
	Date newDate(int n){
		tm current;
		current.tm_mday = day + n;
		current.tm_mon = month-1;
		current.tm_year = year - 1900;
		mktime(&current);
		day = current.tm_mday;
		month = current.tm_mon+1;
		year = current.tm_year + 1900;
		return (*this);
	}
};

int main(){
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	int n, d, m, y;
	while(cin >> n >> d >> m >> y, n||d||m||y){
		Date current(d, m, y);
		current.newDate(n);
		cout << current.day << " " << current.month << " " << current.year << endl;
	}
}
