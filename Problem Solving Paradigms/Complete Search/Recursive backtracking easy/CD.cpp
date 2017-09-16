#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, k, counter, min1, ans;
vi a;

void solve(int u, int mask, int r){
    if(u > k || min1 == 0) return;
    if(k - u < min1){
    	min1 = k-u; ans = mask;
	} 
    for(int i=r; i<n; i++){
        solve(u+a[i], mask | (1<<i), i+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> k >> n){
        a.resize(n);
        min1 = k;
        for(int i=0; i<n; i++) cin >> a[i];
        solve(0, 0, 0);
        counter = 0;
        for(int i=0; i<n; i++){
            if(ans & (1<<i)){
            	counter += a[i]; cout << a[i] << " ";
			} 
        }
        cout << "sum:" << counter << "\n";
    }
}
