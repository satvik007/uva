#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int sieveSize;
vi primes;
bitset <1000010> bs;
vector <int> imp(1000010, 0);

void sieve(int size){
    sieveSize = size + 1;
    bs.set(); bs[0] = bs[1] = 0;
    for(ll i = 2; i<=sieveSize; i++)if(bs[i]){
            primes.push_back(i);
            for(ll j = i*i; j <= sieveSize; j+=i) bs[j] = 0;
        }
}
// I promise I will make a language where this will be the only function.
void doWhatTheProgrammerWants(){
    for(int i=0; i < primes.size(); i++){
        ll res = primes[i];
        while(res <= 1000000){
            imp[res] = primes[i];
            res *= primes[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve(1000000);
    doWhatTheProgrammerWants();
    vector <int> a(1000005);
    a[1] = 1;
    const auto val = (int)1e9;
    for(int i=2; i<=1000000; i++){
        if(imp[i]){
            ll current = (ll)a[i-1] * imp[i];
            if(current % 10 == 0) current /= 10;
            a[i] = current % val;
        }else a[i] = a[i-1];
    }
    int n;
    while(cin >> n, n){
        cout << a[n] % 10 << "\n";
    }
    return 0;
}