#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

int n, dp[6000], dist[6000];
vector <vi> a;

int bfs1(int u){
    bitset <5005> visited; visited.set(u);
    queue <int> q; q.push(u);
    dist[u] = 0;
    int max1 = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dist[u] > dist[max1]) max1 = u;
        for(auto v:a[u]){
            if(!visited.test(v)){
                visited.set(v); dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return max1;
}

void bfs2(int u){
    bitset <5005> visited; visited.set(u);
    queue <int> q; q.push(u);
    dp[u] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v:a[u]){
            if(!visited.test(v)){
                visited.set(v); dp[v] = dp[u] + 1;
                q.push(v);
            }
        }
    }
}
void solve(){
    int ind = bfs1(0);
    int ind2 = bfs1(ind);
    int max1 = dist[ind2];
    bfs2(ind2);
    cout << "Best Roots  :";
    for(int i=0; i<n; i++){
        if(max(dp[i], dist[i]) == (max1+1)/2) cout << " " << i+1;
    }
    cout << "\nWorst Roots :";
    for(int i=0; i<n; i++){
        if(max(dp[i], dist[i]) == max1) cout << " " << i+1;
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v;
    while(cin >> n){
        a.clear(); a.resize(n);
        for(int i=0; i<n; i++){
            cin >> u; a[i].resize(u);
            for(int j=0; j<u; j++) cin >> a[i][j], a[i][j]--;
        }
        solve();
    }
    return 0;
}