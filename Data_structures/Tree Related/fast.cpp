#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

const int N = 1e5+5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(res, t[--r]);
  }
  return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int q;
    int u, v;
    while(cin >> n, n){
        cin >> q;
        vi a(n);
        vi start(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int last = 0;
        int counter = 0;
        for(int i=0; i<n; i++){
            if(a[i] != a[last]){
                int j = i;
                while(j>=0 && j!= last-1){
                    t[j--+n] = counter;
                }
                last = i;
                counter = 1;
            }
            else counter++;
            start[i] = last;
        }
        int j = n-1;
        while(j!=0 && j!= last-1){
            t[j--+n] = counter;
        }
        build();
        for(int i=0; i<q; i++){
            cin >> u >> v;
            u--; v--;
            if(a[u] == a[v]) cout << (v-u+1) << "\n";
            else{
                int k = start[u] + t[u+n];
                int cnt1 = k - u;
                int cnt2 = v - start[v]+1;
                int cnt3 = query(k, start[v]-1);
                cout << max((int)max(cnt1, cnt2), cnt3) << "\n";
            }
        }
    }
}
