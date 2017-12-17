#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

vi twins;
int sieveSize;
bitset <18500010> bs;
vi primes;

void sieve(int size){
    sieveSize = size+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i<= sieveSize; i++) if(bs[i]){
            primes.push_back(i);
            for(ll j = i*i; j <= sieveSize; j+=i) bs[j] = 0;
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve(18500000);
    twins.reserve(100000);
    for(int i=1; i<primes.size(); i++){
        if(primes[i] - primes[i-1] == 2) twins.push_back(i-1);
    }
    int n;
    while(cin >> n){
        cout << "(" << primes[twins[n-1]] << ", " << primes[twins[n-1]+1] << ")\n";
    }
    return 0;
}