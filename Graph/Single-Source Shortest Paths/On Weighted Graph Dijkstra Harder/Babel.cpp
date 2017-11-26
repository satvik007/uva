#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef map <string, int> msi;
typedef pair <int, int> ii;
#define inf 100000000

int m, k, w, dist[2010][30];
msi map1, words;
vector <string> lang, names;
vector <vector <ii>> a;
vector <ii> order;

class Data{
public:
    int len, pos, last;
    Data(int le, int po, int las) : len(le), pos(po), last(las) {}
    Data() {}
};
class comp{
public:
    bool operator () (Data x, Data y){
        return x.len >= y.len;
    }
};

void dijkstra(){
    for(int i=0; i<2010; i++) for(int j=0; j<30; j++) dist[i][j] = inf;
    for(int i=0; i<30; i++) dist[0][i] = 0;
    priority_queue <Data, vector <Data>, comp> pq;
    pq.push(Data(0, 0, m));
    Data current, temp;
    while(!pq.empty()){
        current = pq.top(); pq.pop();
        if(current.pos == 1) break;
        for(auto el:a[current.pos]){
            temp = current;
            if(names[el.second][0] != names[current.last][0] && dist[el.first][names[el.second][0]-'a'] > dist[current.pos][names[current.last][0] - 'a'] + names[el.second].size()){
                dist[el.first][names[el.second][0]-'a'] = dist[current.pos][names[current.last][0]-'a'] + (int)names[el.second].size();
                pq.push(Data(dist[el.first][names[el.second][0]-'a'], el.first, el.second));
            }
        }
    }
    if(current.pos == 1) cout << current.len << "\n";
    else cout << "impossivel\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string x, y, z;
    while(cin >> m, m){
        map1.clear(); k = w = 0; order.clear();
        words.clear(); lang.clear(); names.clear(); a.clear();
        cin >> x >> y;
        map1[x] = k++; map1[y] = k++;
        lang.push_back(x); lang.push_back(y);
        for(int i=0; i<m; i++){
            cin >> x >> y >> z;
            if(map1.find(x) == map1.end()) map1[x] = k++, lang.push_back(x);
            if(map1.find(y) == map1.end()) map1[y] = k++, lang.push_back(y);
            words[z] = w++; names.push_back(z);
            order.push_back({map1[x], map1[y]});
        }
        string satvik; satvik += ('z'+1);
        names.push_back(satvik);
        a.resize(k);
        for(int i=0; i<m; i++){
            a[order[i].first].push_back({order[i].second, i});
            a[order[i].second].push_back({order[i].first, i});
        }
        dijkstra();
    }
    return 0;
}