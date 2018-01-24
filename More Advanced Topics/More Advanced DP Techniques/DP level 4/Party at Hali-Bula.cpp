#include<bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef map <string, int> msi;
const int maxn = 210;

msi id;
int d[maxn][2];
bool f[maxn][2];
vi sons[maxn];

int dp(int u, int t){
    int &k = d[u][t] = t;
    if(sons[u].empty()) return k;
    if(t==1){
        for(int i=0; i<(int)sons[u].size(); ++i){
            k += dp(sons[u][i], 0);
            if(f[sons[u][i]][0] != 1)
                f[u][1] = false;
        }
    }
    else {
        for(int i=0; i<(int)sons[u].size(); ++i){
            int s = sons[u][i], a = dp(s,0), b = dp(s,1);
            k += max(a,b);
            if(a == b || (a > b && !f[s][0]) || (a < b && !f[s][1]))
                f[u][0] = false;
        }
    }
    return k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n, n){
        id.clear();
        memset(d, 0, sizeof(d));
        memset(f, 1, sizeof(f));
        for(int i=0; i<maxn; ++i) sons[i].clear();
        string s; cin >> s;
        int cnt = 0;
        id[s] = cnt++;
        for(int i = 2; i <= n; ++i){
            cin >> s;
            if(!id.count(s)) id[s] = cnt++;
            int k = id[s];
            cin >> s;
            if(!id.count(s)) id[s] = cnt++;
            sons[id[s]].push_back(k);
        }
        int a = dp(0,0), b = dp(0,1);
        bool unk = true;
        if(a == b || (a > b && !f[0][0]) || (a < b && !f[0][1])) unk = false;
        cout << max(a, b) << (unk ? " Yes\n" : " No\n");
    }
    return 0;
}