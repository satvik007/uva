#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define pi acos(-1.0L)

double n, m, v, a, s, dist;
long double x, y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m >> v >> a >> s, n){
        dist = v * s;
        x = dist * cos(a * pi / 180.0);
        y = dist * sin(a * pi / 180.0);
        int c1=0, c2=0;
        if(x >= n){
            x -= n; c1 = (int)(x/n/2) + 1;
        }
        if(y >= m){
            y -= m; c2 = (int)(y/m/2) + 1;
        }
        cout << c1 << " " << c2 << "\n";
    }
    return 0;
}