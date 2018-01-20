#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int x[3], y[3];
int n, m;
unordered_map <ll, int> ans1, ans2;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int ax, int ay, ll &current){
    for(int k=0; k<4; k++){
        int tx = ax + dr[k];
        int ty = ay + dc[k];
        if(tx >= 0 && ty >= 0 && tx < n && ty < m && !(current & (1LL<<(m*tx + ty)))){
            current |= (1LL<<(m*tx + ty));
            dfs(tx, ty, current);
        }
    }
}
bool floodFill(int ax, int ay, ll current){
    dfs(ax, ay, current);
    if(n * m == 64) return current != -1;
    return (current != (1LL<<(n*m)) - 1);
}
void bfs1(){
    queue <int> dist; dist.push(n*m);
    queue <int> q; q.push(0); q.push(1);
    queue <ll> mask; mask.push(2LL);
    ll current;
    int tx, ax, ty, ay, distance;
    bool flag;
    while(!q.empty()){
        ax = q.front(); q.pop();
        ay = q.front(); q.pop();
        distance = dist.front(); dist.pop();
        current = mask.front(); mask.pop();
        if(ax == 0 && ay == 0) continue;
        if(ax == x[1] && ay == y[1]) {
            if(distance == n * m / 2){
                if(ans1.find(current) != ans1.end()) ans1[current]++;
                else ans1[current] = 1;
            }
            continue;
        }else if(distance == n*m/2) continue;
        flag = false;
        for(int i=0; i<3; i++){
            if(x[i] == ax && y[i] == ay && distance != (i+1)*n*m/4) {
                flag = true; break;
            }else if(distance == (i+1)*n*m/4 && (x[i] != ax || y[i] != ay)){
                flag = true; break;
            }
        }
        if(flag) continue;
        if(distance > m*n*3/4){
            if(abs(ax-x[2]) + abs(ay-y[2]) > distance - m*n*3/4) continue;
        }else if(distance > m * n / 2){
            if(abs(ax-x[1]) + abs(ay-y[1]) > distance - m*n/2) continue;
        }
        if(floodFill(0, 0, current)) continue;
        for(int k=0; k<4; k++){
            tx = ax + dr[k];
            ty = ay + dc[k];
            if(tx >= 0 && ty >= 0 && tx < n && ty < m && !(current & (1LL<<(tx*m+ty)))){
                q.push(tx); q.push(ty);
                dist.push(distance-1);
                mask.push(current | (1LL<<(m*tx + ty)));
            }
        }
    }
}
void bfs2(){
    //cout << endl;
    queue <int> dist; dist.push(1);
    queue <int> q; q.push(0); q.push(0);
    queue <ll> mask; mask.push(1LL);
    ll current;
    int tx, ax, ty, ay, distance;
    bool flag;
    while(!q.empty()){
        ax = q.front(); q.pop();
        ay = q.front(); q.pop();
        distance = dist.front(); dist.pop();
        current = mask.front(); mask.pop();
        if(ax == 0 && ay == 1) continue;
        if(ax == x[1] && ay == y[1]) {
            if(distance == n * m / 2){
                if(ans2.find(current) != ans2.end()) ans2[current]++;
                else ans2[current] = 1;
            }
            continue;
        }else if(distance == n*m/2) continue;
        flag = false;
        for(int i=0; i<3; i++){
            if(x[i] == ax && y[i] == ay && distance != (i+1)*n*m/4) {
                flag = true; break;
            }else if(distance == (i+1)*n*m/4 && (x[i] != ax || y[i] != ay)){
                flag = true; break;
            }
        }
        if(flag) continue;
        if(floodFill(0, 1, current)) continue;
        //cout << ax << " " << ay << " " << distance << " " << bitset <32> (current) << endl;
        for(int k=0; k<4; k++){
            tx = ax + dr[k];
            ty = ay + dc[k];
            if(tx >= 0 && ty >= 0 && tx < n && ty < m && !(current & (1LL<<(tx*m+ty)))){
                q.push(tx); q.push(ty);
                dist.push(distance+1);
                mask.push(current | (1LL<<(m*tx + ty)));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> m, n){
        ans1.clear(); ans2.clear();
        for(int i=0; i<3; i++){
            cin >> x[i] >> y[i];
        }
        bfs1(); bfs2();
        int counter = 0;
        ll check = (1LL << (n*m)) - 1;
        for(auto el1:ans2){
            ll temp = el1.first;
            if(n*m == 64) temp = (~temp) | (1LL<<(m*x[1] + y[1]));
            else temp = ((~temp) & ((1LL << (n*m)) - 1))|(1LL<<(m*x[1] + y[1]));
            if(ans1.find(temp) != ans1.end()){
                counter += (el1.second * ans1[temp]);
            }
        }
        cout << "Case " << cas++ << ": " << counter << "\n";
    }
    return 0;
}