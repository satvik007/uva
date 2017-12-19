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
ll sumDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while (PF * PF <= N) {
        ll power = 0;
        while (N % PF == 0) { N /= PF; power++; }
        ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last
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
    for(int i=1; i<100000; i++){
        int current = sumDiv(i);
        if(current <= 1000) sum[current] = i;
    }
    while(cin >> n, n){
        cout << "Case " << cas++ << ": ";
        if(sum[n] == 0) cout << "-1\n";
        else cout << sum[n] << "\n";
    }
    return 0;
}