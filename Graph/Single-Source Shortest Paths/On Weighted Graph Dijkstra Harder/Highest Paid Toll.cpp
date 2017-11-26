#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000
typedef pair <int, int> ii;

int tc, n, m, s, t, p, max1;
int dist1[10005], dist2[10005];
vector <vector <ii>> a, b;

void dijkstra1(){
    for(int i=0; i<n; i++) dist1[i] = inf;
    dist1[s] = 0;
    priority_queue <ii, vector <ii>, greater <ii>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        ii current = pq.top(); pq.pop();
        for(auto el:a[current.second]){
            if(dist1[el.first] > dist1[current.second] + el.second){
                dist1[el.first] = dist1[current.second] + el.second;
                pq.push({dist1[el.first], el.first});
            }
        }
    }
}

void dijkstra2(){
    for(int i=0; i<n; i++) dist2[i] = inf;
    dist2[t] = 0;
    priority_queue <ii, vector <ii>, greater <ii>> pq;
    pq.push({0, t});
    while(!pq.empty()){
        ii current = pq.top(); pq.pop();
        for(auto el:b[current.second]){
            if(dist2[el.first] > dist2[current.second] + el.second){
                dist2[el.first] = dist2[current.second] + el.second;
                pq.push({dist1[el.first], el.first});
            }
        }
    }
}

void ans(){
    max1 = -1;
    for(int i=0; i<n; i++){
        for(auto el:a[i]){
            if(dist1[i] + dist2[el.first] + el.second <= p && el.second > max1){
                max1 = el.second;
            }
        }
    }
    cout << max1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    int u, v, w;
    while(tc--){
        cin >> n >> m >> s >> t >> p; s--; t--;
        a.clear(); b.clear(); a.resize(n); b.resize(n);
        for(int i=0; i<m; i++){
            cin >> u >> v >> w; u--; v--;
            a[u].push_back({v, w});
            b[v].push_back({u, w});
        }
        dijkstra1();
        dijkstra2();
        ans();
    }
}