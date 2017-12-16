#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll modpow(ll base, ll exp, ll modulus) {
    base %= modulus;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int sieveSize;
bitset <10000010> bs;
vi primes;

void sieve(int size){
    sieveSize = size + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(int i=2; i<=sieveSize; i++)if(bs[i]){
        primes.push_back(i);
        for(int j = i*i; j<=sieveSize; j+=i) bs[j] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve((int)sqrt(1e9) + 1);
    int a, p;
    while(cin >> p >> a, p||a){
        int flag = 0;
        for(int i=0; i<primes.size(); i++){
            if(p % primes[i] == 0 && p!=primes[i]) flag = 1;
        }
        cout << ((modpow(a, p, p) == a && flag) ? "yes" : "no") << "\n";
    }
    return 0;
}