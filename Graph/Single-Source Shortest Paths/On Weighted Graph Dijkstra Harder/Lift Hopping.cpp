#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000

class Data{
public:
    int pos, dis, vator;
    Data(){}
    Data(int p, int d, int v) : pos(p), dis(d), vator(v) {}
};
class comp{
public:
    bool operator ()(Data x, Data y){
        return (x.dis >= y.dis);
    }
};

int n, k, b[105], dist[105][10];
vector <vi> a;
vector <vector <Data>> c;

void dijkstra(){
    priority_queue <Data, vector <Data>, comp> pq;
    for(int i=0; i<105; i++) for(int j=0; j<10; j++) dist[i][j] = inf;
    for(int i=0; i<n; i++){
        dist[0][i] = 0;
        if(a[i][0] == 0) pq.push(Data(0, 0, i));
    }
    Data current, temp;
    while(!pq.empty()){
        current = pq.top(); pq.pop();
        if(current.pos == k) break;
        for(auto el:c[current.pos]){
            temp = current;
            if(el.vator == current.vator){
                if(dist[el.pos][el.vator] > dist[current.pos][el.vator] + el.dis){
                    dist[el.pos][el.vator] = dist[current.pos][el.vator] + el.dis;
                    pq.push(Data(el.pos, dist[el.pos][el.vator], el.vator));
                }
            }
            else{
                if(dist[el.pos][el.vator] > dist[current.pos][current.vator] + el.dis + 60){
                    dist[el.pos][el.vator] = dist[current.pos][current.vator] + el.dis + 60;
                    pq.push(Data(el.pos, dist[el.pos][el.vator], el.vator));
                }
            }
        }
    }
    if(current.pos == k) cout << current.dis << "\n";
    else cout << "IMPOSSIBLE\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u;
    while(cin >> n >> k){
        a.clear(); a.resize(n); c.clear(); c.resize(100);
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++){
            cin.ignore();
            while(cin.peek() != '\n' && cin.peek() != EOF){
                cin >> u; a[i].push_back(u);
            }
            for(int j=1; j<a[i].size(); j++){
                c[a[i][j]].push_back(Data(a[i][j-1], (a[i][j] - a[i][j-1])*b[i], i));
                c[a[i][j-1]].push_back(Data(a[i][j], (a[i][j] - a[i][j-1])*b[i], i));
            }
        }
        dijkstra();
    }
    return 0;
}