#include <bits/stdc++.h>
#define epsilon 1e-9
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, a, b, c, x, flag, y, z;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        flag = 0;
        for(x = -100; x <= 100; x++){
            if(flag == 1) break;
            if(((a-x)*(a-x) + x*x - c)*x == 2*b){
                for(y=-100; y<=100; y++){
                    if(x!=y && y!=(a-x-y) && x!=(a-x-y) && x*y*(a-x-y) == b){
                        flag = 1;
                        cout << x << " " << y << " " << (a - x - y) << "\n";
                        break;
                    }
                }
            }
        }
        if(flag == 0) cout << "No solution.\n";
    }
    return 0;
}
