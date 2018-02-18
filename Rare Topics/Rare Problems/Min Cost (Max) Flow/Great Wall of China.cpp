#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

struct Node{
    int x, y, cap, cost;
    int next;
} edge[1000005];

int e, head[10005], dis[10005], previous[10005];
int record[10005], inq[10005];

void addEdge(int x, int y, int cap, int cost){
    edge[e].x = x, edge[e].y = y, edge[e].cap = cap, edge[e].cost = cost;
    edge[e].next = head[x], head[x] = e++;
    edge[e].x = y, edge[e].y = x, edge[e].cap = 0, edge[e].cost = -cost;
    edge[e].next = head[y], head[y] = e++;
}
int mincost(int s, int t){
    int mncost = 0, flow, totflow = 0;
    int i, x, y;
    while(true){
        memset(dis, 63, sizeof dis);
        int oo = dis[0];
        dis[s] = 0;
        deque<int> Q;
        Q.push_front(s);
        while(!Q.empty()){
            x = Q.front(), Q.pop_front();
            inq[x] = 0;
            for(i=head[x]; i!=-1; i=edge[i].next){
                y = edge[i].y;
                if(edge[i].cap > 0 && dis[y] > dis[x] + edge[i].cost){
                    dis[y] = dis[x] + edge[i].cost;
                    previous[y] = x, record[y] = i;
                    if(inq[y] == 0){
                        inq[y] = 1;
                        if(Q.size() && dis[Q.front()] > dis[y])
                            Q.push_front(y);
                        else
                            Q.push_back(y);
                    }
                }
            }
        }
        if(dis[t] == oo)
            break;
        flow = oo;
        for(x = t; x != s; x = previous[x]){
            int ri = record[x];
            flow = min(flow, edge[ri].cap);
        }
        for(x=t; x!=s; x=previous[x]){
            int ri = record[x];
            edge[ri].cap -= flow;
            edge[ri^1].cap += flow;
            edge[ri^1].cost = -edge[ri].cost;
        }
        totflow += flow;
        mncost += dis[t]*flow;
    }
    return mncost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    char s[5][1024];
    int i, j, k;
    while(cin >> n && n){
        e = 0;
        memset(head, -1, sizeof head);
        for(i=0; i<5; i++)
            cin >> s[i];
        int st = (2*5*n), ed = st + 1;
        for(i=0; i<5; i++){
            if(s[i][0] == '@'){
                addEdge(st, (i*n+0)*2, 1, 0);
            }
        }
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(i=0; i<5; i++){
            for(j=0; j<n; j++){
                int node = (i*n+j)*2+1;
                for(k=0; k<4; k++){
                    int tx = i + dx[k], ty = j + dy[k];
                    if(tx < 0 || ty < 0 || tx >= 5 || ty >= n)
                        continue;
                    if(s[tx][ty] == '@')
                        continue;
                    addEdge(node, (tx*n+ty)*2, 1, s[tx][ty]-'0');
                }
                addEdge(node -1, node, 1, 0);
            }
        }
        for(i=0; i<5; i++){
            int node = (i*n+(n-1))*2+1;
            addEdge(node, ed, 1, 0);
        }
        cout << mincost(st, ed) << "\n";
    }
    return 0;
}