#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vi ans;
int n, min1, counter;
int prime[32];
vector <vi> final;
vector <vi> check;
map <vi, int> map1;

void solve(vi ans, int mask){
	if(ans.size() == n && prime[ans[0] + ans[ans.size()-1]]){
		cout << ans[0];
		for(int i=1; i<n; i++) cout << " " << ans[i]; cout << "\n";
		return;
	}
	for(int i=2; i<=n; i++){
		if(!(mask & (1<<i))){
			if(prime[ans[ans.size()-1]+i]){
				ans.push_back(i);
				solve(ans, mask|(1<<i));
				ans.pop_back();
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for(int i=0; i<32; i++) prime[i] = 0; 
    prime[2] = 1; prime[7] = 1; prime[17] = 1; prime [29] = 1;
	prime[3] = 1; prime[11] = 1; prime[19] = 1; prime[31] = 1;
	prime[5] = 1; prime[13] = 1; prime[23] = 1;
	int cas = 1;
    while(cin >> n){
    	if(cas != 1) cout << "\n";
    	cout << "Case " << cas << ":\n"; cas++;
    	ans.clear(); final.clear(); map1.clear();
    	ans.push_back(1);
    	solve(ans, 2);
    }
    return 0;
}