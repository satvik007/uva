#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	string h, m;
	while(1){
		getline(cin, h, ':');
		getline(cin, m, '\n');
		int hour = stoi(h);
		int min1 = stoi(m);
		if((hour || min1)  == 0) break;
		double angle1 = min1*6;
		double angle2 = (hour%12)*30 + min1/2.0;
		double current = (fabs(angle1 - angle2));
		cout << fixed << setprecision(3) << (min(current, 360.000 - current)) << endl;
	}
}
