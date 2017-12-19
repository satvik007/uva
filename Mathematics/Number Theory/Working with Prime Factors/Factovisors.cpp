#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef unsigned long long ull;

int sieveSize;
vi primes;
bitset <1000010> bs;
map <ll, int> map1;

void sieve(int size){
    sieveSize = size + 1;
    bs.set(); bs[0] = bs[1] = 0;
    for(ll i=2; i<=sieveSize; i++) if(bs[i]){
            primes.push_back(i);
            for(ll j=i*i; j<=sieveSize; j+=i) bs[j] = 0;
        }
}
ll get_powers(ll n, ll p) {
    int res = 0;
    for (ll power = p ; power <= n ; power *= p)
        res += n/power;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve(1000000);
    ll n, m;
    while(cin >> n >> m){
        map1.clear();
        ll val = m;
        for(int i=0; (ll)primes[i] * primes[i] <= m && m != 1; i++){
            if(m % primes[i] == 0){
                map1[primes[i]] = 1; m /= primes[i];
                while(m % primes[i] == 0) m /= primes[i], map1[primes[i]]++;
            }
        }
        if(m != 1) map1[m] = 1;
        int flag = 1;
        for(auto iter = map1.begin(); iter != map1.end(); iter++){
            if(get_powers(n, iter->first) < iter->second){
                flag = 0; break;
            }
        }
        if(flag) cout << val << " divides " << n << "!\n";
        else cout << val << " does not divide " << n << "!\n";
    }
    return 0;
}