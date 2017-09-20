#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

ll n, lo, hi, u, v, one = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> n >> u >> v){
        ll a = v;
        int index = 31;
        for(int i=31; i>=0; i--){
            if(v & (one<<i)){ index = i; break;}
        }
        for(int i=index; i>=0; i--){
            if(!(n & (one << i)) && (a | (one << i)) <= v) a |= (one<<i);
            if((n & (one<<i)) && (a & ~(one<<i)) >= u) a &= ~(one<<i);
        }
        cout << a << "\n";
    }
}
