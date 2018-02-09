#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define maxn 1010

int S, A, M;
int dfs_num[maxn], dfs_low[maxn], visited[maxn], scc[maxn];
stack <int> s;
int numSCC, cool, counter;
vector <vi> a;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = cool++;
    s.push(u);
    visited[u] = 1;
    for(auto v:a[u]){
        if(dfs_num[v] == -1)
            tarjanSCC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        ++numSCC;
        while(true){
            int v = s.top(); s.pop(); visited[v] = 0;
            scc[v] = numSCC;
            if(u == v) break;
        }
    }
}

void init(){
    memset(dfs_num, -1, sizeof dfs_num);
    memset(dfs_low, 0, sizeof dfs_low);
    memset(visited, 0, sizeof visited);
    cool = numSCC = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    int s1, a1, s2, a2;
    while(tc--){
        cin >> S >> A >> M;
        int n = (S+A)*2;
        a.clear(); a.resize(n);
        while(M--){
            cin >> s1 >> a1 >> s2 >> a2;
            s1--; a1--; s2--; a2--;
            s1 <<= 1; a1 <<= 1;
            s2 <<= 1; a2 <<= 1;
            a1 += 2 * S, a2 += 2 * S;
            if(a1 > a2) s1 ^= 1, s2 ^= 1;
            if(s1 > s2) a1 ^= 1, a2 ^= 1;
            if(s1 == s2){
                a[s1^1].push_back(s2);
                continue;
            }
            if(a1 == a2){
                a[a1^1].push_back(a2);
                continue;
            }
            a[s1^1].push_back(a1);
            a[a1^1].push_back(s1);

            a[s2^1].push_back(a2);
            a[a2^1].push_back(s2);

            a[a1^1].push_back(a2);
            a[a2^1].push_back(a1);

            a[s2^1].push_back(s1);
            a[s1^1].push_back(s2);
        }
        init();
        for(int i=0; i<n; i++){
            if(dfs_num[i] == -1)
                tarjanSCC(i);
        }
        bool flag = true;
        for(int i=0; i<n; i+=2){
            if(scc[i] == scc[i^1]){
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes": "No") << "\n";
    }
    return 0;
}