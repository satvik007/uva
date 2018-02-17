#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define mx 10001

ll n;
int b, tc;
vi f[mx];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> b, n||b){
        if(b < 2){
            cout << "Case " << ++tc << ": " << n << ' ' << b << " 0" << endl;
            continue;
        }
        if(f[b].empty()){
            f[b].push_back(1);
            f[b].push_back(1);
            do{
                f[b].push_back(f[b].back() + f[b][f[b].size()-2] + 1);
                f[b].back() %= b;
            } while(f[b].back() != 1 || f[b][f[b].size()-2] != 1);
            f[b].pop_back();
            f[b].pop_back();
        }
        cout << "Case " << ++tc << ": " << n << " " << b << " " << f[b][n%f[b].size()] << endl;
    }

    return 0;
}