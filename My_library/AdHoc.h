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

int ipow(int base, int exp){
    int result = 1;
    while (exp){
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


#endif

int gcd(unsigned int u, unsigned int v) {
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }
        v = v - u;
    } while (v != 0);
    return u << shift;
}
