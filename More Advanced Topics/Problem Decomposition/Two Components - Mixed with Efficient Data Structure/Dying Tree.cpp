#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

struct Data{
    int id, x, y;
};

int n, m, k, d, s;
ii doc[15];
Data a[10000];

class MyUnionFind { // OOP style
public:
    vi p, rank;
    explicit MyUnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
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
            if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

bool solve(){
    MyUnionFind satvik(s + m);
    for(int i=0; i<s; i++){
        for(int j=i+1; j<s; j++){
            if(a[i].id == a[j].id) satvik.unionSet(i, j);
            else if(hypot(a[i].x - a[j].x, a[i].y - a[j].y) <= k) satvik.unionSet(i, j);
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<s; j++){
            if(hypot(doc[i].first - a[j].x, doc[i].second - a[j].y) <= d){
                satvik.unionSet(i+s, j);
            }
        }
    }
    for(int i=0; i<m; i++){
        if(satvik.isSameSet(s+i, 0)) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m >> k >> d;
        for(int i=0; i<m; i++){
            cin >> doc[i].first >> doc[i].second;
        }
        s = 0; int b;
        for(int i=0; i<n; i++){
            cin >> b;
            for(int j=0; j<b; j++){
                cin >> a[s].x >> a[s].y;
                a[s].id = i; s++;
            }
        }
        bool ans = solve();
        if(ans) cout << "Tree can be saved :)\n";
        else cout << "Tree can't be saved :(\n";
    }
    return 0;
}
