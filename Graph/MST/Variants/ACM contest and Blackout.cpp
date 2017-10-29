#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef pair<int, ii> iii;
#define inf 100000000

vector <iii> a;
int visited[10005], n, m;

class UnionFind{
public: vi p, rank;
    int N, total;
    UnionFind(int N){
        n = N;
        rank.assign(n, 1);
        p.resize(n);
        for(int i=0; i<n; i++) p[i] = i;
        total = n;
    }
    int findSet(int i){
        while(i != p[i]) p[i] = p[p[i]], i=p[i]; return i;
    }
    bool isSameSet(int i, int j){
        return (findSet(i) == findSet(j));
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] < rank[y]) p[x] = y;
            else{
                p[y]=x;
                if(rank[x] == rank[y]) rank[x]++;
            }
            total--;
        }
    }
    void clear(){
        rank.assign(n, 1);
        p.resize(n);
        for(int i=0; i<n; i++) p[i] = i;
        total = n;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, u, v, w;
    cin >> t;
    while(t--){
        cin >> n >> m;
        a.clear();
        for(int i=0; i<m; i++){
            cin >> u >> v >> w; u--; v--;
            a.push_back({w, {u, v}});
        }
        sort(a.begin(), a.end());
        UnionFind seg(n);
        memset(visited, 0, sizeof visited);
        int ans=0, newans=inf, current;
        for(int i=0; i<m; i++){
            iii el = a[i];
            if(!seg.isSameSet(el.second.first, el.second.second)){
                seg.unionSet(el.second.first, el.second.second);
                ans += el.first;
                visited[i] = 1;
                //if(seg.total == 1) break;
            }
        }
        for(int j=0; j<m; j++){
            if(visited[j]){
                current = 0;
                seg.clear();
                for(int i=0; i<m; i++){
                    if(i == j) continue;
                    iii el = a[i];
                    if(!seg.isSameSet(el.second.first, el.second.second)){
                        seg.unionSet(el.second.first, el.second.second);
                        current += el.first;
                        //if(seg.total == 1) break;
                    }
                }
                if(current < ans) continue;
                newans = min(newans, current);
            }
        }
        cout << ans << " " << newans << "\n";

    }
    return 0;
}
