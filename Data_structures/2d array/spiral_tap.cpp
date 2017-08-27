#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ll n, m;
	while(cin >> n >> m, n||m){
		ll row = n/2;
		ll col = n/2;
		ll index = 1;
		ll k = 1;
		while(k != m){
			if(k+index<=m) k += index, row += index;
			else row += m - k, k = m;
			if(k+index<=m) k += index, col -= index;
			else col -= m - k, k = m;
			index++;
			if(k+index<=m) k += index, row -= index;
			else row -= m - k, k = m;
			if(k+index<=m) k += index, col += index;
			else col += m - k, k = m;
			index++;
		}
		cout << "Line = " << (row+1) << ", column = " << (col+1) << ".\n";
	}
	
	return 0;
}
