#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, n, m, b[50][50], visited[500], match[500], aleft[500], mcbm;
vector <string> a;
vector <vi> adjList;

int augment(int u){
    if(visited[u]) return 0;
    visited[u] = 1;
    for(int v:adjList[u]){
        if(match[v] == -1 || augment(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        a.resize(n); memset(b, -1, sizeof b);
        adjList.clear();
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int k=0;
        adjList.reserve(n*m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == '*'){
                    aleft[k] = (i+j) % 2;
                    b[i][j] = k++;
                    adjList.push_back(vi ());
                    if(i > 0 && b[i-1][j] >= 0){
                        adjList[b[i-1][j]].push_back(b[i][j]);
                        adjList[b[i][j]].push_back(b[i-1][j]);
                    }
                    if(j > 0 && b[i][j-1] >= 0){
                        adjList[b[i][j-1]].push_back(b[i][j]);
                        adjList[b[i][j]].push_back(b[i][j-1]);
                    }
                }
            }
        }
        memset(match, -1, sizeof match);
        mcbm = 0;
        for(int i=0; i<adjList.size(); i++){
            if(aleft[i]){
                memset(visited, 0, sizeof visited);
                mcbm += augment(i);
            }
        }
        cout << (adjList.size() - mcbm) << "\n";
    }

    return 0;
}