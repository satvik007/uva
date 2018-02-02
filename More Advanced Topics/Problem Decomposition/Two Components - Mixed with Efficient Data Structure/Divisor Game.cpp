#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

vi primes;
bitset <11000> bs;

void sieve(){
    int size = 1010;
    bs.set(); bs[0] = bs[1] = 0;
    for(int i=2; i<=size; i++) if(bs[i]){
            primes.push_back(i);
            for(int j = i*i; j<=size; j+=i) bs[j] = 0;
        }
}

int val[1000010];
int b[1000010];

inline int div(int k){
    int res = 1, cnt;
    for(int i=0; i<primes.size() && k != 1; i++){
        if(k % primes[i] == 0){
            cnt = 0;
            while(k % primes[i] == 0){
                k /= primes[i]; cnt++;
            }
            res *= (cnt+1);
        }
    }
    if(k != 1)
        res *= 2;
    return res;
}

void solve(){
    for(int i=1; i<=1000000; i++){
        val[i] = div(i);
    }
    b[0] = 0;
    for(int i=1; i<=1000000; i++){
        b[i] = val[b[i-1]] > val[i] ? b[i-1] : i;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve();
    solve();
    int tc; cin >> tc;
    int n;

    while(tc--){
        cin >> n;
        cout << b[n] << "\n";
    }
    return 0;
}
