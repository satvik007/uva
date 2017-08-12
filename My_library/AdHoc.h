#ifndef ADHOC_H
#define ADHOC_H

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
// are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
// 1 billion, safer than 2B for Floyd Warshall’s
//memset(memo, -1, sizeof memo); // initialize DP memoization table with -1
//memset(arr, 0, sizeof arr);

class Date{
public:
	int day;
	int month;
	int year;
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


#endif