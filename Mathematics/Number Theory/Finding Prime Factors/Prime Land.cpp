#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef unsigned long long ull;

int sieveSize;
vi primes;
bitset <1000010> bs;

void sieve(int size){
    sieveSize = size + 1;
    bs.set(); bs[0] = bs[1] = 0;
    for(int i=2; i<=sieveSize; i++) if(bs[i]){
            primes.push_back(i);
            for(int j=i*i; j<=sieveSize; j+=i) bs[j] = 0;
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string line;
    sieve(40000);
    map <int, int> map1;
    while(true){
        getline(cin, line); if(line == "0") break;
        vi a;
        stringstream take(line);
        int u, v, value = 1;
        while(take >> u >> v){
            value *= pow(u, v);
        } value--;
        map1.clear();
        if(binary_search(primes.begin(), primes.end(), value)){
            cout << value << " " << 1 << "\n";
        }else{
            for(int i=0; value != 1; i++){
                if(value % primes[i] == 0){
                    map1[primes[i]] = 1; value /= primes[i];
                    while(value % primes[i] == 0) value /= primes[i], map1[primes[i]]++;
                }
            }
            for(auto ind = map1.rbegin(); ind != map1.rend(); ind++){
                if(ind != map1.rbegin()) cout << " ";
                cout << ind->first << " " << ind->second;
            }
            cout << "\n";
        }

    }
    return 0;
}