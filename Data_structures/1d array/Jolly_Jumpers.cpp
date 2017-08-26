#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int n;
	while(cin >> n){
		vector <int> a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		vector <bool> status(n);
		fill(status.begin(), status.end(), false);
		for(int i=1; i<n; i++) if(abs(a[i]-a[i-1]) < n) status[abs(a[i]-a[i-1])] = true;
		int flag = 0;
		for(int i=n-1; i>0; i--) if(status[i] == false){
			flag = 1;
			break;
		}
		if(flag == 1) cout << "Not jolly\n";
		else cout << "Jolly\n";
	}
}
