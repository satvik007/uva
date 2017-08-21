#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++){
		vector <string> a(52);
		for(int i=0; i<52; i++) cin >> a[i];
		int counter = 51;
		int y = 0;
		counter -= 25;
		for(int i=0; i<3; i++){
			int x;
			if(a[counter][0] >= '2' && a[counter][0] <= '9') x = a[counter][0] - '0';
			else x = 10;
			y += x;
			counter -= 1;
			counter -= (10 - x);
		}
		cout << "Case " << cas << ": ";
		if(counter >= y) cout << a[y] << endl;
		else{
			y -= (counter+1);
			cout << a[51-25+y] << endl;
		}
	}
}