#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;
typedef unsigned long long ull;

int sieveSize;
vi primes;
bitset <1000010> bs;

void sieve(int size){
    sieveSize = size + 1;
    bs.set(); bs[0] = bs[1] = 0;
    for(ll i=2; i<=sieveSize; i++) if(bs[i]){
            primes.push_back(i);
            for(ll j=i*i; j<=sieveSize; j+=i) bs[j] = 0;
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string line;
    sieve(1000000);
    ll n;
    while(cin >> n, n!=0){
        if(n < 0) cout << n << " = -1 x ";
        else cout << n << " = ";
        n = abs(n);
        queue <ll> q;
        int val = (int)sqrt(n) + 1;
        for(int i=0; primes[i] <= val && n != 1; i++){
            while(n % primes[i] == 0){
                n /= primes[i]; q.push(primes[i]);
            }
        }
        if(n != 1) q.push(n);
        cout << q.front(); q.pop();
        while(!q.empty()){
            cout << " x " << q.front(); q.pop();
        } cout << "\n";
    }
    return 0;
}