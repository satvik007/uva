/* There are 50000 time nodes which can be compressed on the basis on how they appear in
   the data that comes. eg.
   1 2 4
   2 5 9
   1 3 8
   is the data then the ranges are:

   2-3, 3-4, 4-5, 5-8, 8-9.

   We assign flow from source to animals as what the animal requires. (res[0][i+2])
   We assign flow from animals to any range as (right val - left val) (res[i+2][n+2+index])
   From any range to target as m*(right val - left val). The max capacity it can support.
   As 1 time slot supports m so (rv - lv) supports m*(rv - lv). (res[n+2+i][1])

   Then we apply Edmond Karp algorithm - pretty standard code.
   res[j][i] represents the flow to be represented in the compressed range.
   For writing the ranges we first fill the relatively less used blocks first and then
   if more are required we fill from the left using pivot as tracker.
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

class Data{
public:
    int v, a, b;
};

int n, m, f, mf, total, s, t, cnt, cas = 1, r;
int used[50005], times[500], pivot[500], res[320][320];
vi names, p, ans;
vector <Data> store;


void augment(int v, int minEdge){
    if(v == s) f = minEdge;
    else if(p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}
void EdmondKarp(){
    mf = 0;
    while(true){
        p.assign(310, -1); f = 0;
        queue <int> q; q.push(s);
        bitset<310> visited; visited.set(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v = 0; v<310; v++){
                if(res[u][v] > 0 && !visited.test(v)){
                    visited.set(v); q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(t, inf);
        if(!f) break;
        mf += f;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    s=0; t=1;
    while(cin >> n >> m){
        store.resize(n); memset(res, 0, sizeof res);
        names.clear(); memset(times, 0, sizeof times);
        memset(used, 0, sizeof used); total = 0;
        for(int i=0; i<n; i++){
            cin >> store[i].v >> store[i].a >> store[i].b;
            used[store[i].a] = 1; used[store[i].b] = 1;
            res[0][i+2] = store[i].v; total += store[i].v;
        }
        for(int i=0; i<50001; i++) if(used[i]) names.push_back(i);
        int index;
        for(int i=0; i<n; i++){
            index = lower_bound(names.begin(), names.end(), store[i].a) - names.begin();
            while(names[index] < store[i].b){
                res[i+2][n+2+index] = (names[index+1] - names[index]);
                index++;
            }
        }
        cnt = names.size();
        for(int i=0; i<names.size()-1; i++){
            pivot[i] = names[i];
            res[n+2+i][1] = m*(names[i+1] - names[i]);
        }
        EdmondKarp();
        cout << "Case " << (cas++) << ": ";
        if(mf == total){
            cout << "Yes\n";
            int left, right, flag, index, mid;
            //for(int i=0; i<50001; i++) times[i] = m;
            for(int i=2; i<n+2; i++){
                ans.clear();
                for(int j=n+2; j<n+2+cnt; j++){
                    // Remember its not the same as res[i][j]
                    if(res[j][i] > 0) {
                        left = names[j - n - 2];
                        right = names[j - n - 1];
                        if (res[j][i] == (right - left)) {
                            if (!ans.empty() && ans.back() == left) ans.back() = right;
                            else ans.push_back(left), ans.push_back(right);
                            continue;
                        }
                        index = pivot[j-n-2];
                        if (right - index < res[j][i]) {
                            mid = left + res[j][i] - (right - index);
                            if (!ans.empty() && ans.back() == left) ans.back() = mid;
                            else ans.push_back(left), ans.push_back(mid);
                            ans.push_back(index); ans.push_back(right);
                            pivot[j-n-2] = mid;
                        } else {
                            if(!ans.empty() && ans.back() == index) ans.back() = index+res[j][i];
                            else ans.push_back(index), ans.push_back(index + res[j][i]);
                            pivot[j-n-2] = (index + res[j][i] == right) ? left : (index + res[j][i]);
                        }
                    }
                }
                cout << (ans.size()/2);
                for(int j=0; j<ans.size(); j+=2){
                    cout << " (" << ans[j] << "," << ans[j+1] << ")";
                }
                cout << "\n";
            }
        }
        else cout << "No\n";
    }
    return 0;
}