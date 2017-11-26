#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
#define inf 100000000

int t, n, m;
vector <vector <ii>> adjList;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    int x, y, z;
    while(t--) {
        cin >> n >> m;
        adjList.clear();
        adjList.resize(n);
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> z;
            adjList[x].push_back({y, z});
        }
        vi dist(n, inf); dist[0] = 0;
        for (int i = 0; i < n - 1; i++)
            for (int u = 0; u < n; u++)
                for (int j = 0; j < (int)adjList[u].size(); j++) {
                    ii v = adjList[u][j];
                    dist[v.first] = min(dist[v.first], dist[u] + v.second);
                }

        bool hasNegativeCycle = false;
        for (int u = 0; u < n; u++)
            for (int j = 0; j < (int)adjList[u].size(); j++) {
                ii v = adjList[u][j];
                if (dist[v.first] > dist[u] + v.second) hasNegativeCycle = true;
            }
        cout << (hasNegativeCycle ? "possible\n" : "not possible\n");
    }
    return 0;
}