#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;
	//ifstream cin("in.txt");
	//ofstream cout ("out.txt");
	while(cin >> k, k){
		int n, m;
		cin >> n >> m;
		int u, v;
		for(int i=0; i<k; i++){
			cin >> u >> v;
			if(u == n || v  == m) cout << "divisa" << endl;
			else if(u < n && v < m) cout << "SO" << endl;
			else if(u >n && v < m) cout << "SE" << endl;
			else if(u <n && v>m) cout << "NO" << endl;
			else if(u>n && v > m ) cout << "NE" << endl;
		}
	}
}