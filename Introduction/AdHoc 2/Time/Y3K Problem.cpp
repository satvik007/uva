#include <bits/stdc++.h>
using namespace std;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int n, d, m, y;
	while(cin >> n >> d >> m >> y, n||d||m||y){
		//cout << n<< " " << d << " " << m << " " << y << endl;
		tm curr;
		curr.tm_mday = d+n;
		curr.tm_mon = m-1;
		curr.tm_year = y-1900;
		mktime(&curr);
		cout << (curr.tm_mday) << " " << (curr.tm_mon+1) << " " << (curr.tm_year+1900) << endl;
	}
}
