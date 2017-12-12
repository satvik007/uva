#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
// a = (2 × n + r − r 2 )/(2 × r)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n>0){
        int r = (int)sqrt(2*n)+1;
        int a;
        for(; r>0; r--){
            if((2 * n + r - r * r) % (2 * r) == 0){
                a = (2 * n + r - r * r)/(2 * r); break;
            }
        }
        cout << n << " = " << max(a, 1) << " + ... + " << (a+r-1) << "\n";
    }
    return 0;
}