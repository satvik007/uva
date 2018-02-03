#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef unsigned long long llu;
const int INF = INT_MAX;

struct dpe{
    ll cost;
    int count, from, to;
};

const int MAX = 1 << 20;

vvi roads;
ll n;
dpe DP[MAX];
ll target;

dpe dp(ll mask, vii distances, ll count){
    auto &r = DP[mask];
    if(r.cost == -1){
        if((mask & target) == target){
            r.cost = 0;
            r.count = count;
            r.to = -1;
            r.from = -1;
            return r;
        }
        r.cost = INF;
        for(ll i = 0; i<n; i++){
            if(mask & (1<<i) || distances[i].first == INF)
                continue;
            vii cp = distances;
            for(ll j = 0; j<n; j++){
                if(cp[j].first <= roads[i][j])
                    continue;
                cp[j].first = roads[i][j];
                cp[j].second = i;
            }
            auto t = dp(mask | (1<<i), cp, count+1);
            t.cost += distances[i].first;
            if(t.cost < r.cost || (t.cost == r.cost && t.count < r.count)){
                r.count = t.count;
                r.cost = t.cost;
                r.to = i;
                r.from = distances[i].second;
            }
        }
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll tc = 0;
    while(cin >> n, n > -1){
        tc++;
        target = 0;
        dpe e; e.cost = -1;
        fill(&DP[0], &DP[MAX], e);
        roads.clear(); roads.resize(n);
        for(ll i=0; i<n; i++) roads[i].resize(n, INF);
        int dc; cin >> dc; dc--;
        target = target | (1 << dc);
        int nr; cin >> nr;
        for(ll i = 0; i<nr; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            roads[u][v] = roads[v][u] = w;
        }
        int nj; cin >> nj;
        vi judges(nj);
        for(ll i = 0; i<nj; i++){
            cin >> judges[i]; judges[i]--;
            target = target | (1<< judges[i]);
        }
        vii distances(n);
        for(ll i = 0; i<n; i++){
            distances[i] = make_pair(roads[dc][i], dc);
        }
        auto answer = dp(1<<dc, distances, 1);
        cout << "Case " << tc << ": distance = " << answer.cost << endl;
        bitset <20> in_trip;
        in_trip.set(dc);
        auto t = answer;
        ll mask = (1<<dc);
        vector <stack<int>> road_to(n);
        road_to[dc].push(dc);
        while(t.to != -1){
            road_to[t.to] = road_to[t.from];
            road_to[t.to].push(t.to);
            mask = mask | (1<<t.to);
            t = DP[mask];
        }
        for(ll i = 0; i<nj; i++){
            cout << "   ";
            auto &s = road_to[judges[i]];
            while(!s.empty()){
                cout << s.top() + 1;
                s.pop();
                if(!s.empty()) cout << "-";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
