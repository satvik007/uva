#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int n, b[105], dist[105], reach[105];
vector <vi> a, c;

void dfs(int u){
    reach[u] = 1;
    for(auto el:c[u]){
        if(!reach[el]) dfs(el);
    }
}

void ford(){
    memset(dist, -1, sizeof dist);
    memset(reach, 0, sizeof reach);
    dist[0] = 100;
    for(int i=0; i<n-1; i++){
        for(int u=0; u<n; u++){
            for(auto el:a[u]){
                if(dist[u] > 0 && dist[el] < dist[u] + b[el]) dist[el] = dist[u] + b[el];
            }
        }
    }
    bool flag = false;
    dfs(n-1);
    for(int i=0; i<n; i++){
        for(auto el:a[i]){
            if(dist[i] > 0 && dist[el] < dist[i] + b[el]){
                if(reach[el]) flag = true;
            }
        }
    }
    if(dist[n-1] >= 0 || flag) cout << "winnable\n";
    else cout << "hopeless\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v;
    while(cin >> n, n != -1){
        a.clear(); a.resize(n);
        c.clear(); c.resize(n);
        for(int i=0; i<n; i++){
            cin >> b[i];
            cin >> u; a[i].resize(u);
            for(int j=0; j<a[i].size(); j++){
                cin >> a[i][j];
                a[i][j]--;
                c[a[i][j]].push_back(i);
            }
        }
        ford();
    }
    return 0;
}