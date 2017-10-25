#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
vector <vi> a;
int visited[205];
int colors[205];
int dist[205][205];
int vcopy[205];

int dfs(int u, int color){
    visited[u] = 1;
    colors[u] = color;
    int ans = 1;
    for(auto el:a[u]){
        if(!visited[el]){
            ans += dfs(el, !color);
        }
    }
    return ans;
}

void copy(){
    for(int i=0; i<n; i++){
        vcopy[i] = colors[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, u, v;
    cin >> t;
    while(t--){
        cin >> n >> m;
        a.clear(); a.resize(n);
        memset(dist, 0, sizeof dist);
        for(int i=0; i<m; i++){
            cin >> u >> v;
            dist[u][v] = 1;
            dist[v][u] = 1;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        memset(visited, 0, sizeof visited);
        memset(colors, 0, sizeof colors);
        copy();
        int counter = 0;
        int current;
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                copy();
                current = dfs(i, 1);
                if(current == 1) counter++;
                else{
                    count = 0;
                    for(int j=0; j<n; j++){
                        if(vcopy[j] != colors[j]) count++;
                    }
                    counter += min(current - count, count);
                }
            }

        }
        int flag = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j] && colors[i] == colors[j]){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout << "-1\n";
        else{
            cout << counter << "\n";
        }
    }
}