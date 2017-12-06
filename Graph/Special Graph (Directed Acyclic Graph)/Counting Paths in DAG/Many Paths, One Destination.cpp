#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
int memo[105];
vector <vi> a;

int solve(int current){
    if(a[current].empty()) return 1;
    if(memo[current] != -1) return memo[current];
    int ans = 0;
    for(auto el:a[current]){
        ans += solve(el);
    }
    return memo[current] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 0;
    while(cin >> n){
        if(cas) cout << "\n";
        cas++;
        a.clear(); a.resize(n); memset(memo, -1, sizeof memo);
        int size;
        for(int i=0; i<n; i++){
            cin >> size; a[i].resize(size);
            for(int j=0; j<size; j++){
                cin >> a[i][j];
            }
        }
        int ans = solve(0);
        cout << ans << "\n";
    }
    return 0;
}