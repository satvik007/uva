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
ll EulerPhi(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = N;
    while (PF * PF <= N) {
        if (N % PF == 0) ans -= ans / PF;
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1) ans -= ans / N;
    return ans;
}
vi sum (1005, 0);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve(1000000);
    int n, cas = 1;
    while(cin >> n, n){
        cout << EulerPhi(n) << "\n";
    }
    return 0;
}