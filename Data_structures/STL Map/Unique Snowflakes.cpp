#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	cin >> t;
	int n;
	while(t--){
		cin >> n;
		vi a(n);
		map <int, int> map1;
		for(int i=0; i<n; i++) cin >> a[i];
		int max1 = -1;
		int last = 0;
		int flag = 0;
		for(int i=0; i<n; i++){
			if(i-last > max1) max1 = i-last;
			if(map1.find(a[i]) == map1.end());
			else if(map1[a[i]] >= last){
				flag = 1;
				last = map1[a[i]]+1; 
			}
			map1[a[i]] = i;
		}
		if(n-last > max1) max1 = n-last;
		cout << max1 << "\n";
	}
	return 0;
}
