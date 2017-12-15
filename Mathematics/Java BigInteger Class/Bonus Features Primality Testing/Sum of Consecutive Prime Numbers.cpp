#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll _sieve_size;
bitset<100010> bs;
vi primes;
int ans[10005];

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    sieve(10005);
    memset(ans, 0, sizeof ans);
    ll res = 0;
    vector <ll> b;
    b.push_back(0);
    for(int i=0; i<primes.size(); i++){
        res += primes[i];
        b.push_back(res);
    }
    for(int i=0; i<b.size(); i++){
        for(int j=i+1; j<b.size(); j++){
            if(b[j] - b[i] <= 10000)
                ans[b[j] - b[i]]++;
        }
    }
    while(cin >> n, n){
        cout << ans[n] << "\n";
    }
    return 0;
}