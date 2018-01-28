#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

vi primes;
bitset <2000010> bs;

void sieve(){
    bs.set(); bs[1] = 0;
    for(ll i = 5; i<1000010; i += 4) if(bs[i]){
            primes.push_back(i);
            for(ll j = i*i; j<1000010; j += i){
                bs[j] = 0;
            }
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve();
    vi imp;
    for(int i=0; i<primes.size(); i++){
        for(int j=i; j<primes.size(); j++){
            if(primes[i] * primes[j] > 1000010) break;
            imp.push_back(primes[i] * primes[j]);
        }
    }
    sort(imp.begin(), imp.end());
    auto it = unique(imp.begin(), imp.end());
    imp.resize(it - imp.begin());
    int n;
    while(cin >> n, n){
        int index = upper_bound(imp.begin(), imp.end(), n) - imp.begin();
        cout << n << " " << index << "\n";
    }
    return 0;
}