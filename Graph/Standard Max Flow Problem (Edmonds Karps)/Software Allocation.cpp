#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

int f, mf, s, t, res[50][50], total;
vi p;

void augment(int v, int minEdge){
    if(v == s) f = minEdge;
    else if (p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}
void EdmondKarp(){
    mf = 0;
    while(true){
        f = 0; queue <int> q; q.push(s);
        bitset<64> visited; visited.set(s);
        p.assign(50, -1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v = 0; v <= 40; v++){
                if(res[u][v] > 0 && !visited.test(v)){
                    visited.set(v); q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(t, inf);
        if(!f) break;
        mf += f;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a;
    s = 0; t = 1;
    while(cin.peek() != EOF){
        total = 0; memset(res, 0, sizeof res);
        while(true){
            getline(cin, a);
            if(a.empty()) break;
            res[0][a[0]-'A'+2] = a[1]-'0'; total += a[1]-'0';
            for(int i=3; i<a.size()-1; i++){
                res[a[0]-'A'+2][a[i]-'0'+28] = inf;
            }
        }
        for(int i=28; i<38; i++) res[i][1] = 1;
        EdmondKarp();
        int flag;
        if(total == mf){
            for(int i=28; i<38; i++){
                flag = 0;
                for(int j=2; j<28; j++){
                    if(res[i][j] == 1){
                        cout << (char)(j+'A'-2); flag = 1;
                        break;
                    }
                }
                if(!flag) cout << "_";

            }
            cout << "\n";
        }
        else cout << "!\n";
    }
    return 0;
}