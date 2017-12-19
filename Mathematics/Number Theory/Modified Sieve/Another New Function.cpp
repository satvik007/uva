#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef unsigned long long ull;

int phi[2000005], depth[2000005], sum[2000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sum[1] = 0; phi[1] = 1; depth[1] = 0;
    for(int i=0; i<=2000001; i++) phi[i] = i;
    for (int i = 2; i < 2000001; i++){
        if (phi[i] == i){
            for (int j = i; j < 2000001; j += i){
                phi[j] -= phi[j]/i;
            }
        }
    }
    for(int i=2; i<=2000000; i++){
        depth[i] = depth[phi[i]] + 1;
        sum[i] = sum[i-1] + depth[i];
    }
    int tc, n, m;
    cin >> tc;
    while(tc--){
        cin >> m >> n;
        cout << (sum[n] - sum[m-1]) << "\n";
    }
    return 0;
}