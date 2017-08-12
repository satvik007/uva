#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
#define print(a) {for(int i=0; i<a.size(); i++) cout << a[i] << " "; cout << endl;}
vi a;
vi rank1;
vector <bool> status;
vi counter;
int flag;
int count1;

int dfs(int u){
	count1++;
	if(rank1[u] != 0){
		return rank1[u];
	} 
	if(status[u] == false){
		counter[u] = count1;
		status[u] = true;
		int current = dfs(a[u]);
		if(flag != -1)
			rank1[u] = current;
		else
			rank1[u] = current + 1;
		if(u == flag) flag = -1;
		return rank1[u];
	}
	else{
		flag = u;
		rank1[u] = count1 - counter[u];
		return rank1[u];
	}
}
int main(){
	//ifstream cin("in.txt");
	int t;
	cin >> t;
	for(int cas = 1; cas <=t; cas++){
		int n;
		cin >> n;
		a.resize(n);
		rank1.resize(n); fill(rank1.begin(), rank1.end(), 0);
		status.resize(n); fill(status.begin(), status.end(), false);
		counter.resize(n); fill(counter.begin(), counter.end(), 0);
		int u, v;
		for(int i=0; i<n; i++){
			cin >> u >> v;
			a[u-1] = v-1; 
		}
		for(int i = 0; i<n; i++){
			if(rank1[i] != 0) continue;
			flag = -1;
			count1 = 0;
			dfs(i);
		}
		int index = max_element(rank1.begin(), rank1.end()) - rank1.begin();
		cout << "Case " << cas << ": " << (index+1) << endl;
	}
}
