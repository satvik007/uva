#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
int a[105][105];
int visited[105];
int ans[105][105];

void dfs(int u){
    visited[u] = 1;
    for(int i=0; i<n; i++){
        if(a[u][i] && !visited[i]){
            dfs(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cas = 1;
    int u, v, w;
    char c1, c2;
    while(cin >> n){
        memset(a, 0, sizeof a);
        memset(ans, 0, sizeof ans);
        for(int i=0; i<n; i++){
            cin >> u >> c1 >> w >> c2;
            for(int j=0; j<w; j++){
                cin >> v;
                a[v][u] = a[u][v] = 1;
            }
        }
        memset(visited, 0, sizeof visited);
        int init = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                init++;
                dfs(i);
            }
        }
        int current;
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(a[i][j]){
                    a[i][j] = a[j][i] = 0;
                    current = 0;
                    memset(visited, 0, sizeof visited);
                    for(int k=0; k<n; k++){
                        if(!visited[k]){
                            current++;
                            dfs(k);
                        }
                    }
                    if(current > init) ans[i][j] = ans[j][i] = 1, count++;
                    a[i][j] = a[j][i] = 1;
                }
            }
        }
        cout << count << " critical links\n";
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(ans[i][j]){
                    cout << i << " - " << j << "\n";
                }
            }
        }
        cout << "\n";
        cas++;
    }
    return 0;
}