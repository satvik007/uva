#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
vector <vector <vi>> a;
map <char, int> map1;
int visited[600][600][6], rota[600][600];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct Data{
    int x, y, tim;
    Data(int xa, int ya, int tima){
        x = xa, y = ya, tim = tima;
    }
    Data(){};
};

void bfs(){
    memset(visited, 0, sizeof visited);
    memset(rota, 0, sizeof rota);
    Data root(0, 0, 0);
    queue <Data> q; q.push(root);
    visited[0][0][0] = 1;
    int tx, ty, rot;
    Data current;
    while(!q.empty()){
        current = q.front(); q.pop();
        if(current.x == n - 1 && current.y == m - 1) break;
        for(int k=0; k<a[current.x][current.y].size(); k++){
            tx = current.x + dr[(a[current.x][current.y][k] + current.tim) % 4];
            ty = current.y + dc[(a[current.x][current.y][k] + current.tim) % 4];
            if(tx >=0 && ty >= 0 && tx < n && ty < m && !visited[tx][ty][(current.tim+1)%4]){
                visited[tx][ty][(current.tim+1)%4] = 1;
                q.push(Data(tx, ty, current.tim + 1));
            }
        }
    }
    if(current.x == n-1 && current.y == m-1) {
        cout << current.tim << "\n";
    }else{
        cout << "no path to exit\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    map1['N'] = 0; map1['E'] = 1; map1['S'] = 2; map1['W'] = 3;
    while(cin >> n >> m){
        string u;
        a.clear(); a.resize(n);
        for(int i=0; i<n-1; i++){
            a[i].resize(m);
            for(int j=0; j<m; j++){
                cin >> u;
                a[i][j].resize(u.size());
                for(int k=0; k<u.size(); k++){
                    a[i][j][k] = map1[u[k]];
                }
            }
        }
        a[n-1].resize(m);
        for(int i=0; i<m-1; i++){
            cin >> u;
            for(int k=0; k<u.size(); k++){
                a[n-1][i].push_back(map1[u[k]]);
            }
        }
        bfs();
    }

    return 0;
}