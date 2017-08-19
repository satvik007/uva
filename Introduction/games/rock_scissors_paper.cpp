#include <bits/stdc++.h>
using namespace std;

int n, m, k;

void simulate(vector <string> &a){
	vector <string> b(a);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			//cout << i << " " << j << endl;
			if(a[i][j] == 'R'){
				if(i-1>=0 && a[i-1][j] == 'P') b[i][j] = 'P';
				if(i+1<n && a[i+1][j] == 'P') b[i][j] = 'P';
				if(j-1>=0 && a[i][j-1] == 'P') b[i][j] = 'P';
				if(j+1<m && a[i][j+1] == 'P') b[i][j] = 'P';
			}
			else if(a[i][j] == 'S'){
				if(i-1>=0 && a[i-1][j] == 'R') b[i][j] = 'R';
				if(i+1<n && a[i+1][j] == 'R') b[i][j] = 'R';
				if(j-1>=0 && a[i][j-1] == 'R') b[i][j] = 'R';
				if(j+1<m && a[i][j+1] == 'R') b[i][j] = 'R';
			}
			else if(a[i][j] == 'P'){
				if(i-1>=0 && a[i-1][j] == 'S') b[i][j] = 'S';
				if(i+1<n && a[i+1][j] == 'S') b[i][j] = 'S';
				if(j-1>=0 && a[i][j-1] == 'S') b[i][j] = 'S';
				if(j+1<m && a[i][j+1] == 'S') b[i][j] = 'S';
			}
		}
	}
	a = b;
	return;
}

void print(vector <string> &a, ostream &cout){
	for(int i=0; i<a.size(); i++){
		cout << a[i] << endl;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++){
		if(cas != 1) cout << endl;
		cin >> n >> m >> k;
		if(!(n&&m)) continue;
		vector <string> a(n);
		for(int i=0; i<n; i++) cin >> a[i];	

		for(int i=0; i<k; i++){
			simulate(a);
		}
		print(a, cout);
	}
}