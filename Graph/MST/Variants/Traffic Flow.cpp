#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
#define inf (int)1e9

int n, m, tc;
vector <iii> a;

class MyUnionFind{
public:
    vi p, rank;
    int num;
    MyUnionFind(int n){
        rank.assign(n, 0);
        num = n;
        p.resize(n);
        for(int i=0; i<n; i++) p[i] = i;
    }
    int findSet(int i){
        while(i != p[i]) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        i = findSet(i);
        j = findSet(j);
        if(i != j){
            num--;
            if(rank[i] < rank[j]){
                p[i] = j;
            }else{
                p[j] = i;
                if(rank[i] == rank[j]) rank[i]++;
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    int cas = 1;
    while(tc--){
        cin >> n >> m;
        a.clear();
        int u, v, c;
        for(int i=0; i<m; i++){
            cin >> u >> v >> c;
            a.push_back({c, {u, v}});
        }
        sort(a.begin(), a.end(), greater<iii>());
        MyUnionFind satvik(n);
        int ans = inf;
        for(int i=0; i<m && satvik.num != 1; i++){
            if(!satvik.isSameSet(a[i].second.first, a[i].second.second)){
                ans = min(ans, a[i].first);
                satvik.unionSet(a[i].second.first, a[i].second.second);
            }
        }
        cout << "Case #" << cas++ << ": " << ans << "\n";
    }
    return 0;
}