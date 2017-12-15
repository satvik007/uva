#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll sieveSize;
bitset <1000010> bs;
vi primes;

void sieve(ll size){
    sieveSize = size + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    int val = (int)sqrt(sieveSize) + 1;
    for(ll i=2; i <= val; i++) if(bs[i]){
            for(ll j = i*i; j<=sieveSize; j+=i) bs[j] = 0;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve(1000005);
    int n;
    while(cin >> n){
        string a = to_string(n);
        reverse(a.begin(), a.end());
        int m = stoi(a);
        if(bs[n]){
            if(bs[m] && n != m) cout << n << " is emirp.\n";
            else cout << n << " is prime.\n";
        }else cout << n << " is not prime.\n";
    }
    return 0;
}