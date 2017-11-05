#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
#define inf 100000000

int n, m, s, t;
vector <vector <ii>> AdjList;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cases, cas = 1, p, q, r;
    cin >> cases;
    while(cases--){
        AdjList.clear();
        cin >> n >> m >> s >> t;
        AdjList.resize(n);
        for(int i=0; i<m; i++){
            cin >> p >> q >> r;
            AdjList[p].push_back({q, r});
            AdjList[q].push_back({p, r});
        }
        vi dist(n); dist.assign(n, inf); dist[s] = 0;
        priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
        while (!pq.empty()) {
            ii front = pq.top(); pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }
        cout << "Case #" << (cas++) << ": ";
        if(dist[t] == inf) cout << "unreachable\n";
        else cout << dist[t] << "\n";
    }
    return 0;
}