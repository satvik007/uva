#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

bool satvik(pair <vi, int> a, pair <vi, int> b){
	return a.second < b.second;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int n;
	while(cin >> n, n){
		vector <vi> a(n, vi(5));
		map <vi, int> map1;
		for(int i=0; i<n; i++){
			for(int j=0; j<5; j++) cin >> a[i][j];
			sort(a[i].begin(), a[i].end());
			if(map1.find(a[i]) == map1.end()) map1[a[i]] = 1;
			else map1[a[i]]++;
		} 
		int max1 = -1;
		int current;
		int counter = 0;
		for(auto iter = map1.begin(); iter != map1.end(); iter++){
			current = iter->second;
			if(current > max1) max1 = current;
		}
		for(auto iter = map1.begin(); iter != map1.end(); iter++){
			current = iter->second;
			if(current == max1) counter+=current;
		}
		cout << counter << "\n";
	}
	return 0;
}
