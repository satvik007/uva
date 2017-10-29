#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef pair<int, ii> iii;

int n, m;
vector <iii> a;
int visited[1200];

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
    while(cin >> n >> m, n||m){
        a.clear();
        for(int i=0; i<m; i++){
            cin >> u >> v >> w;
            a.push_back({w, {u, v}});
        }
        sort(a.begin(), a.end());
        UnionFind seg(n);
        int mst_cost = 0;
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < m; i++) { // for each edge, O(E)
            iii front = a[i];
            if (!seg.isSameSet(front.second.first, front.second.second)) { // check
                visited[i] = 1;
                seg.unionSet(front.second.first, front.second.second); // link them
            }
        }
        ll counter = 0;
        int flag = 1;
        for(int i=0; i<m; i++){
            if(!visited[i]) {
                if(flag) cout << a[i].first, flag = 0;
                else cout << " " << a[i].first;
            }
        }
        if(flag) cout << "forest\n";
        else cout << "\n";
    }
    return 0;
}
