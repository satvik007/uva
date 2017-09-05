#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

map <string, int> map1;

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
    int t;
    cin >> t;
    int m;
    while(t--){
        map1.clear();
        cin >> m;
        string x, y;
        int k = 0;
        UnionFind a(100005);
        for(int i=0; i<m; i++){
            cin >> x >> y;
            if(map1.find(x) == map1.end()) map1[x] = k++;
            if(map1.find(y) == map1.end()) map1[y] = k++;
            a.unionSet(map1[x], map1[y]);
            cout << a.con[a.findSet(map1[x])] << "\n";
        }
    }
    return 0;
}
