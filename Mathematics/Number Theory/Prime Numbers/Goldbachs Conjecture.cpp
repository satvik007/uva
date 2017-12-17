#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;

int sieveSize;
bitset <10000010> bs;
vi primes;

void sieve(int size){
    sieveSize = size+1;
    bs.set();
    bs[0] = 0; bs[1] = 0;
    for(ll i = 2; i<=sieveSize; i++) if(bs[i]){
            primes.push_back(i);
            for(ll j = i*i; j<=sieveSize; j += i) bs[j] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve(1000000);
    int n;
    while(cin >> n, n){
        for(int i=0; i<primes.size(); i++){
            if(binary_search(primes.begin(), primes.end(), n - primes[i])){
                cout << n << " = " <<  primes[i] << " + " << (n - primes[i]) << "\n";
                break;
            }
        }
    }
}