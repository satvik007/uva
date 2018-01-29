#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

bitset <2000000> bs;
vi primes;
vi imp;
void sieve(){
    bs.set(); bs[0] = bs[1] = 0;
    for(ll i = 2; i<=1000010; i++) if(bs[i]){
            primes.push_back(i);
            for(ll j = i * i; j<=1000010; j+=i) bs[j] = 0;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve();
    for(int i=0; i<primes.size(); i++){
        ll res = primes[i]*primes[i];
        while(res > 0 && res <= 1e13){
            imp.push_back(res);
            res *= primes[i];
        }
    }
    sort(imp.begin(), imp.end());
    int tc; cin >> tc;
    ll u, v;
    while(tc--){
        cin >> u >> v;
        int ind1 = upper_bound(imp.begin(), imp.end(), u) - imp.begin();
        int ind2 = upper_bound(imp.begin(), imp.end(), v) - imp.begin();
        cout << (ind2 - ind1 + (imp[ind1-1] == u ? 1 : 0)) << "\n";
    }
    return 0;
}