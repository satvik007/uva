#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	double h, u, d, f;
	while(cin >> h >> u >> d >> f, h){
		double current = 0;
		current += u;
		int counter = 1;
		int flag = 0;
		double fatigue = f/100*u;
		while(1){
			if(current > h) break;
			u -= fatigue;
			if(u < 0) u = 0;
			current -= d;
			if(current < 0) {
				flag = 1;
				break;
			}
			current += u;
			counter++;
		}
		if(flag == 1)
			cout << "failure on day " << counter << endl;
		else cout << "success on day " << counter << endl;
	}
	return 0;
}
