#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef unsigned long long ull;

#define INF (int)1e9
#define X 15
#define PUZZLE 16
#define ROW 4

int p[PUZZLE];
int lim, nlim;
map <int, int> pred;
map <ull, int> vis;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
char ans[] = "RULD";

inline int h1(){
    int ans = 0;
    for(int i=0; i<PUZZLE; i++){
        if(p[i] != X)
            ans += abs(i/4-p[i]/4) + abs(i%4-p[i]%4);
    }
    return ans;
}
inline int h2(int i1, int j1, int i2, int j2){
    int tgt_i = p[i2*4+j2]/4, tgt_j = p[i2*4+j2]%4;
    return -(abs(i2 - tgt_i) + abs(j2 - tgt_j)) + (abs(i1 - tgt_i) + abs(j1 - tgt_j));
}
inline bool goal(){
    for(int i=0; i<PUZZLE; i++){
        if(p[i] != X && p[i] != i)
            return false;
    }
    return true;
}
inline bool valid(int r, int c){
    return r >= 0 && c >= 0 && r < 4 && c < 4;
}
inline void swap(int i, int j, int new_i, int new_j){
    int temp = p[i*4+j];
    p[i*4+j] = p[new_i*4+new_j];
    p[new_i*4+new_j] = temp;
}
bool DFS(int g, int h){
    if(g+h > lim){
        nlim = min(nlim, g + h);
        return false;
    }
    if(goal())
        return true;
    ull state = 0;
    for(int i=0; i<PUZZLE; i++){
        state <<= 4;
        state += p[i];
    }
    if(vis.count(state) && vis[state] <= g)
        return false;
    vis[state] = g;
    int i, j, d, new_i, new_j;
    for(i=0; i<PUZZLE; i++){
        if(p[i] == X) break;
    }
    j = i%4;
    i /= 4;
    for(d=0; d<4; d++){
        new_i = i + dr[d], new_j = j + dc[d];
        if(valid(new_i, new_j)){
            int dh = h2(i, j, new_i, new_j);
            swap(i, j, new_i, new_j);
            pred[g+1] = d;
            if(DFS(g+1, h+dh))
                return true;
            swap(i, j, new_i, new_j);
        }
    }
    return false;
}
int IDA_Star(){
    lim = h1();
    while(true){
        nlim = INF;
        pred.clear();
        vis.clear();
        if(DFS(0, h1()))
            return lim;
        if(nlim == INF)
            return -1;
        lim = nlim;
        if(lim > 45)
            return -1;
    }
}
void output(int d){
    if(d == 0) return;
    output(d-1);
    cout << ans[pred[d]];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        int i, j, blank=0, ans=0, sum=0;
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                cin >> p[i*4+j];
                if(p[i*4+j] == 0){
                    p[i*4+j] = X;
                    blank = i*4+j;
                }else{
                    p[i*4+j]--;
                }
            }
        }
        for(i=0; i<PUZZLE; i++){
            for(j=0; j<i; j++){
                if(p[i] != X && p[j] != X && p[j] > p[i])
                    sum++;
            }
        }
        sum += blank/4;
        if(sum % 2 != 0 && (ans = IDA_Star()) != -1)
            output(ans), cout << "\n";
        else
            cout << "This puzzle is not solvable.\n";
    }
    return 0;
}