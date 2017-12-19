#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int sieveSize;
vi primes;
bitset <1000010> bs;
void sieve(int size){
    sieveSize = size + 1;
    bs.set(); bs[0] = bs[1] = 0;
    for(ll i = 2; i<=sieveSize; i++)if(bs[i]){
            primes.push_back(i);
            for(ll j = i*i; j <= sieveSize; j+=i) bs[j] = 0;
        }
}

vi find_factors(int n){
    vi ans;
    for(int i=0; (ll)primes[i]*primes[i] <= n; i++){
        if(n % primes[i] == 0){
            ans.push_back(primes[i]);
            while(n % primes[i] == 0) n /= primes[i];
        }
    }
    if(n != 1) ans.push_back(n);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve(1000000);
    int tc, u, v;
    cin >> tc;
    while(tc--){
        cin >> u >> v;
        if(v % u != 0) cout << "NO SOLUTION\n";
        else {
            int m = v / u;
            vi factors = find_factors(m);
            int ans = 1;
            for(auto el:factors){
                while(v % el == 0){
                    v /= el; ans *= el;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}