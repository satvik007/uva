#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int n, dist[105][105], visited[105], mat[105][105];
vector <vi> a;

void dfs(int u){
    for(int i=0; i<a[u].size(); i++){
        if(!visited[a[u][i]]){
            visited[a[u][i]] = 1;
            dfs(a[u][i]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    int cas = 1;
    while(t--){
        cin >> n;
        a.clear(); a.resize(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> dist[i][j];
                if(dist[i][j]) a[i].push_back(j);
            }
        }
        cout << "Case " << cas << ":\n";
        cout << "+"; for(int j=0; j<2*n-1; j++) cout << "-"; cout << "+\n";
        memset(mat, 0, sizeof mat);

        for(int i=0; i<n; i++){
            memset(visited, 0, sizeof visited);
            visited[0] = 1; visited[i] = 1;
            dfs(0);
            for(int j=0; j<n; j++){
                if(!visited[j]) mat[i][j] = 1;
            }
            //for(int j=0; j<n; j++) cout << visited[j] << " "; cout << endl;
            mat[0][i] = 1;
            mat[i][i] = 1;
        }
        memset(visited, 0, sizeof visited);
        dfs(0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                for(int j=0; j<n; j++){
                    mat[j][i] = 0;
                }
            }
        }
        mat[0][0] = 1;
        for(int i=0; i<n; i++){
            cout << "|";
            for(int j=0; j<n; j++){
                if(mat[i][j]) cout << "Y|";
                else cout << "N|";
            }
            cout << "\n+"; for(int j=0; j<2*n-1; j++) cout << "-"; cout << "+\n";
        }
        cas++;
    }
    return 0;
}
