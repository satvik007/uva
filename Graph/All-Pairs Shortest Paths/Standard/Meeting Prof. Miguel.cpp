#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000
int a[30][30], b[30][30], n, m;
map <char, int> map1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char age, type;
    n = 26;
    char u, v;
    while(cin >> m, m){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) a[i][j] = b[i][j] = inf;
            a[i][i] = b[i][i] = 0;
        }
        int w;
        for(int i=0; i<m; i++){
            cin >> age >> type >> u >> v >> w;
            if(u == v) continue;
            if(age == 'Y'){
                a[u-'A'][v-'A'] = w;
                if(type == 'B') a[v-'A'][u-'A'] = w;
            }
            else {
                b[u-'A'][v-'A'] = w;
                if(type == 'B') b[v-'A'][u-'A'] = w;
            }
        }
        cin >> u >> v;
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
                    b[i][j] = min(b[i][j], b[i][k]+b[k][j]);
                }
            }
        }
        int min1 = inf - 5;
        int current;
        vi ans;
        for(int i=0; i<n; i++){
            current = a[u-'A'][i]+b[v-'A'][i];
            if(current < min1){
                ans.clear(); ans.push_back(i);
                min1 = current;
            }
            else if(current == min1) ans.push_back(i);
        }
        if(ans.size() == 0) cout << "You will never meet.\n";
        else{
            cout << min1;
            for(auto el:ans) cout << " " << (char)(el+'A'); cout << "\n";
        }
    }
    return 0;
}
