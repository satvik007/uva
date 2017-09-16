#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int n, m;
vector <pair<int, int>> a;
int flag;

void solve(int row, int mask, int last){
    if(row == n){
        if(a[last].second == a[m+1].first) flag = 1;
        return;
    }
    for(int i=1; i<=m; i++){
        if(!(mask & (1<<i))){
            if(a[last].second == a[i].first) solve(row+1, mask | (1<<i), i);
            if(a[last].second == a[i].second){
                swap(a[i].first, a[i].second);
                solve(row+1, mask | (1<<i), i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        cin >> m;
        flag = 0;
        a.resize(m+2);
        cin >> a[0].first >> a[0].second;
        cin >> a[m+1].first >> a[m+1].second;
        for(int i=1; i<m+1; i++) cin >> a[i].first >> a[i].second;
        solve(0, 1, 0);
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}