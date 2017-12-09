#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef pair <int, bool> ib;

vi get_diameter(vector <vector <ib>> &adjList, int start_node){
    queue <int> q; q.push(start_node);
    vector <bool> visited(adjList.size(), false); visited[start_node] = true;
    int far = start_node;
    while(!q.empty()){
        int u = q.front(); q.pop();
        far = u;
        for(auto &item : adjList[u]){
            if(!item.second) continue;
            int v = item.first;
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    visited.assign(adjList.size(), false); visited[far] = true;
    vi parent(adjList.size()); parent[far] = -1; q.push(far);
    while(!q.empty()){
        int u = q.front(); q.pop();
        far = u;
        for(auto &item:adjList[u]){
            if(!item.second) continue;
            int v = item.first;
            if(!visited[v]){
                visited[v] = true;
                q.push(v); parent[v] = u;
            }
        }
    }
    vi path;
    while(far != -1){
        path.push_back(far);
        far = parent[far];
    }
    return path;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N; cin >> N;
    while(N--){
        int n; cin >> n;
        vector <vector <ib>> adjList(n);
        int a, b;
        for(int i=0; i<n-1; i++){
            cin >> a >> b;
            adjList[a-1].push_back({b-1, true});
            adjList[b-1].push_back({a-1, true});
        }
        vi diameter = get_diameter(adjList, 0);
        ii cancel, add;
        ib *edge1, *edge2;
        int solution = n;
        for(int i=1; i<diameter.size(); i++){
            int u = diameter[i-1], v = diameter[i];
            for(auto &item:adjList[u]) if(item.first == v){
                    edge1 = &item; break;
                }
            for(auto &item:adjList[v]) if(item.first == u){
                    edge2 = &item; break;
                }
            edge1->second = false; edge2->second = false;
            vi left = get_diameter(adjList, u), right = get_diameter(adjList, v);
            int new_dia = max(ceil((left.size()-1)/2.0) + ceil((right.size()-1)/2.0) + 1, max(left.size()-1.0, right.size()-1.0));
            if(new_dia < solution) {
                solution = new_dia;
                cancel.first = u+1; cancel.second = v+1;
                add.first = left[left.size()/2]+1; add.second = right[right.size()/2]+1;
            }
            edge1->second = true; edge2->second = true;
        }
        cout << solution << "\n" << cancel.first << " " << cancel.second << "\n" <<
             add.first << " " << add.second << "\n";
    }
    return 0;
}