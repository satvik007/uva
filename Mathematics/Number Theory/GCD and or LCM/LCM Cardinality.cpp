#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int sieveSize;
vi primes;
bitset<1000010> bs;

void sieve(int size) {
    sieveSize = size + 1;
    bs.set(); bs[0] = bs[1] = 0;
    for(ll i = 2; i<=sieveSize; i++)if(bs[i]) {
            primes.push_back(i);
            for(ll j = i*i; j<=sieveSize; j+=i) bs[j] = 0;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve(1000000);
    int n;
    while(cin >> n, n){
        int m = n;
        vi num;
        for(int i=0; i<primes.size() && n>1; i++){
            int cnt = 0;
            while(n % primes[i] == 0){
                cnt++, n /= primes[i];
            }
            if(cnt) num.push_back(cnt);
        }
        if(n>1)num.push_back(1);
        ll res = 1;
        for(auto el:num){
            res *= (2 * el + 1);
        }
        cout << m << " " << (res + 1)/2 << "\n";
    }

    return 0;
}