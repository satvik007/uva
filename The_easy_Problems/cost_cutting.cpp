#include <bits/stdc++.h>
using namespace std;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	int t;
	cin >> t;
	for(int m=1; m<=t; m++){
		vector <int> a(3);
		for(int i=0; i<3; i++) cin >> a[i];
		sort(a.begin(), a.end());
		cout << "Case " << m << ": " << a[1] << endl;
	}
}