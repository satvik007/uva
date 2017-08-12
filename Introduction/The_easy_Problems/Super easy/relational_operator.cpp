#include <bits/stdc++.h>
using namespace std;

int main(){
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	long long a, b;
	int t;
	cin >> t;
	while(t--){
		cin >> a >> b;
		if(a<b) cout << "<" << endl;
		else if(a>b) cout << ">" << endl;
		else cout << "=" << endl;
	}
}