#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

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

ll numDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while (PF * PF <= N) {
        ll power = 0;
        while (N % PF == 0) { N /= PF; power++; }
        ans *= (power + 1);
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= 2;
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
        ii ans;
        int max1 = 0;
        for(int i=u; i<=v; i++){
            int current = numDiv(i);
            if(current > max1){
                max1 = current;
                ans.first = i; ans.second = current;
            }
        }
        cout << "Between " << u << " and " << v << ", " << ans.first
             << " has a maximum of " << ans.second << " divisors.\n";
    }
    return 0;
}