#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define PI acos(-1.0)
double d, v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(3);
    while(cin >> d >> v, d || v){
        cout << pow(pow(d, 3) - 6 / PI*v, 1/3.0) << "\n";
    }
    return 0;
}