#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;

int sieveSize;
bitset <1000010> bs;
vi primes;

void sieve(int size){
    sieveSize = size+1;
    bs.set();
    bs[0] = 0; bs[1] = 0;
    for(ll i = 2; i<=sieveSize; i++) if(bs[i]){
            primes.push_back(i);
            for(ll j = i*i; j<=sieveSize; j += i) bs[j] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sieve(1000000);
    unsigned n, m;
    while(cin >> n >> m){
        unsigned last = 1, first = 1;
        int min1 = INT_MAX;
        int max1 = 0;
        pair <int, int> ans, sec;
        for(unsigned i=n; i<=m; i++){
            int flag = 1;
            if(binary_search(primes.begin(), primes.end(), i));
            else{
                if(i == 1) flag = 0;
                for(int j=0; primes[j] * primes[j] <= i; j++){
                    if(i % primes[j] == 0){
                        flag = 0; break;
                    }
                }
            }
            if(flag) {
                if(first == 1) first = i;
                else{
                    if(min1 > i - last){
                        min1 = i - last;
                        ans.first = last; ans.second = i;
                    }
                    if(max1 < i - last){
                        max1 = i - last;
                        sec.first = last; sec.second = i;
                    }
                }
                last = i;
            }
        }
        if(first != last){
            cout << ans.first << "," << ans.second << " are closest, "<<
                 sec.first << "," << sec.second << " are most distant.\n";
        }else cout << "There are no adjacent primes.\n";
    }
    return 0;
}