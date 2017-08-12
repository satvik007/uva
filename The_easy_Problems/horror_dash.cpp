#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++){
		int n;
		cin >> n;
		vi a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		cout << "Case " << cas << ": " << (*max_element(a.begin(), a.end())) << endl;
	}
}
