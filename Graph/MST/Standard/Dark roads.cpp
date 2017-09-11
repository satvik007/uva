#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

class MyUnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
    MyUnionFind(int N) {
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int m, n, k, u, v, states, num, w;
    double rails, roads;
    vector< pair<int, ii>> EdgeList;
    ll counter;
    while(cin >> n >> m, n||m){
    	EdgeList.resize(m);
        counter = 0;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            counter += w;
            EdgeList[i] = {w, {u, v}}; 
        }
        sort(EdgeList.begin(), EdgeList.end());
        ll mst_cost = 0;
        MyUnionFind UF(n);
        num = 0;
        for (int i = 0; i < m; i++) {
            pair<int, ii> front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) { 
                mst_cost += front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
            if(num == n-1) break;
        }
        cout << (counter - mst_cost) << "\n";
    }
}
