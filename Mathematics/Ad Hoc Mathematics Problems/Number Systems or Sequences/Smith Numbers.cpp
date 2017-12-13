#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int n, tc;


ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int sum(int k){
    string a = to_string(k);
    int res = 0;
    for(int i=0; i<a.size(); i++){
        res += a[i] - '0';
    }
    return res;
}

bool solve(int k){
    int counter = sum(k);
    int original = k;
    if(*lower_bound(primes.begin(), primes.end(), k) == k) return 0;
    for(int i=0; i<primes.size() && k != 1; i++){
        while(k % primes[i] == 0){
            counter -= sum(primes[i]);
            k /= primes[i];
        }
    }
    if(k != 1 && k != original){
        counter -= sum(k);
    }
    return (counter == 0 && original != k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    sieve(100000);
    while(tc--){
        cin >> n;
        for(int i=n+1; ; i++){
            if(solve(i)){
                cout << i << "\n";
                //check(i);
                break;
            }
        }
    }
    return 0;
}