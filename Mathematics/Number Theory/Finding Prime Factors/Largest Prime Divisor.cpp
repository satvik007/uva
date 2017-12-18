#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef unsigned long long ull;

int sieveSize;
vi primes;
bitset <10000010> bs;

void sieve(int size){
    sieveSize = size + 1;
    bs.set(); bs[0] = bs[1] = 0;
    for(ll i=2; i<=sieveSize; i++) if(bs[i]){
            primes.push_back(i);
            for(ll j=i*i; j<=sieveSize; j+=i) bs[j] = 0;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string line;
    sieve(10000000);
    ll n;
    while(cin >> n, n != 0){
        n = abs(n);
        int cnt = 0;
        ll max1 = -1;
        for(int i=0; (ll)primes[i] * primes[i] <= n && n != 1; i++){
            if(n % primes[i] == 0){
                cnt++; max1 = primes[i];
                while(n % primes[i] == 0) n /= primes[i];
            }
        }
        if(n != 1) max1 = n, cnt++;
        if(cnt < 2) cout << "-1\n";
        else cout << max1 << "\n";
    }
    return 0;
}