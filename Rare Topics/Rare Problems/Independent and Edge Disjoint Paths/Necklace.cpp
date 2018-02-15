#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

struct Node{
    int x, y, v;
    int next;
} edge[500005];

int e, head[10005], dis[10005], previous[10005], record[10005];

void addEdge(int x, int y, int v){
    edge[e].x = x, edge[e].y = y, edge[e].v = v;
    edge[e].next = head[x], head[x] = e++;
    edge[e].x = y, edge[e].y = x, edge[e].v = 0;
    edge[e].next = head[y], head[y] = e++;
}

int maxflow(int s, int t){
    int flow = 0;
    int i, j, x, y;
    while(true){
        memset(dis, 0, sizeof dis);
        dis[s] = 0xffff;
        queue <int> Q;
        Q.push(s);
        while(!Q.empty()){
            x = Q.front();
            Q.pop();
            for(i = head[x]; i!=-1; i=edge[i].next){
                y = edge[i].y;
                if(dis[y] == 0 && edge[i].v > 0){
                    previous[y] = x, record[y] = i;
                    dis[y] = min(dis[x], edge[i].v);
                    Q.push(y);
                }
            }
            if(dis[t])
                break;
        }
        if(dis[t] == 0)
            break;
        flow += dis[t];
        for(x = t; x != s; x = previous[x]){
            int ri = record[x];
            edge[ri].v -= dis[t];
            edge[ri^1].v += dis[t];
        }
    }
    return flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m, cas = 1;
    int i, j, k, x, y;
    while(cin >> n >> m && (n || m)){
        e = 0;
        memset(head, -1, sizeof head);
        int S, T;
        for(i=0; i<m; i++){
            cin >> x >> y;
            addEdge(x, y, 1);
            addEdge(y, x, 1);
        }
        S = 0;
        cin >> x >> T;
        addEdge(S, x, 2);
        int flow = maxflow(S, T);
        cout << "Case " << cas++ << ": " << (flow == 2 ? "YES\n" : "NO\n");
    }

    return 0;
}