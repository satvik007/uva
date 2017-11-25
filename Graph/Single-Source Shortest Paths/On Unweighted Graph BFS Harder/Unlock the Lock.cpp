#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000

int L, U, R, visited[10005], dist[10005];
vi a;

void bfs(){
    dist[L] = 0;
    queue <int> q; q.push(L);
    int v, temp;
    while(!q.empty()){
        v = q.front(); q.pop();
        if(v == U) break;
        for(int i=0; i<R; i++){
            temp = (v + a[i])%10000;
            if(dist[temp] > dist[v] + 1){
                dist[temp] = dist[v] + 1;
                q.push(temp);
            }
        }
    }
    if(dist[U] == inf) cout << "Permanently Locked\n";
    else cout << dist[U] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> L >> U >> R, L || U || R){
        a.resize(R); //memset(visited, 0, sizeof visited);
        for(int i=0; i<10005; i++) dist[i] = inf;
        for(int i=0; i<R; i++){
            cin >> a[i];
        }
        cout << "Case " << (cas++) << ": ";
        bfs();
    }
    return 0;
}