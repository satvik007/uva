#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef pair<int, ii> iii;

int n, m, q;
vector <iii> a;

class UnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
    vi con;
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        con.assign(N, 1);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) {
        while(i != p[i]) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x, con[x] += con[y]; // rank keeps the tree short
            else {
                p[x] = y;
                con[y] += con[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int u, v, w;
    int cas = 1;
    while(cin >> n >> m >> q, n||m||q){
        if(cas != 1) cout << "\n";
        cout << "Case #" << cas << "\n";
        a.clear();
        for(int i=0; i<m; i++){
            cin >> u >> v >> w; u--; v--;
            a.push_back({w, {u, v}});
        }
        sort(a.begin(), a.end());

        while(q--){
            cin >> u >> v; u--; v--;
            UnionFind seg(n);
            int ans = -1, flag = 1;
            for (int i = 0; i < m; i++) { // for each edge, O(E)
                iii front = a[i];
                if (!seg.isSameSet(front.second.first, front.second.second)) { // check
                    ans = max(ans, front.first);
                    seg.unionSet(front.second.first, front.second.second); // link them
                }
                if(seg.isSameSet(u, v)){
                    flag = 0; break;
                }
            }
            if(flag) cout << "no path\n";
            else cout << ans << "\n";
        }
        cas++;
    }
    return 0;
}
