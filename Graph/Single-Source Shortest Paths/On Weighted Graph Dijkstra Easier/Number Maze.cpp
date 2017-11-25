#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define inf 100000000
typedef pair <int, int> ii;

int t, n, m, a[1005][1005], visited[1005][1005];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dijkstra(){
    int x, y, tx, ty;
    memset(visited, 0, sizeof visited);
    priority_queue <ii, vector <ii>, greater <ii>> pq;
    pq.push({a[0][0], 0});
    visited[0][0] = 1;
    ii temp;
    int ans;
    while(!pq.empty()){
        ii current = pq.top(); pq.pop();
        x = current.second / m; y = current.second % m;
        if(current.second == m*n-1){
            ans = current.first; break;
        }
        for(int i=0; i<4; i++){
            tx = x + dr[i]; ty = y + dc[i];
            if(tx >= 0 && ty >= 0 && tx < n && ty < m && !visited[tx][ty]){
                visited[tx][ty] = 1;
                temp.first = current.first + a[tx][ty];
                temp.second = tx*m + ty;
                pq.push(temp);
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> a[i][j];
        dijkstra();
    }
    return 0;
}