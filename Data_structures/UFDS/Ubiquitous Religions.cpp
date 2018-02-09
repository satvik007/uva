#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;

class MyUnionFind{
public:
    vi p, rank;
    int n, counter;
    MyUnionFind(int _n){
        n = _n;
        p.resize(n);
        rank.assign(n, 1);
        counter = n;
        for(int i=0; i<n; i++)
            p[i] = i;
    }
    int findSet(int i){
        while(i != p[i]) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            counter--;
            int left = findSet(i);
            int right = findSet(j);
            if(rank[left] < rank[right]) {
                p[left] = right;
            }else {
                p[right] = left;
                if(rank[right] == rank[left]) rank[left]++;
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> m, n){
        int u, v;
        MyUnionFind satvik(n);
        for(int i=0; i<m; i++){
            cin >> u >> v; u--; v--;
            satvik.unionSet(u, v);
        }
        cout << "Case " << cas++ << ": " << satvik.counter << endl;
    }
    return 0;
}