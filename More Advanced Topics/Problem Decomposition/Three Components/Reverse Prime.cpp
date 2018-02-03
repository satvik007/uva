#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define  LSOne(S) (S & (-S))
class FenwickTree {
private: vi ft;
public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }
    int rsq(int b) { // returns RSQ(1, b)
        int sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) { // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    void adjust(int k, int v) { // note: n = ft.size() - 1
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};

bitset <2000010> bs;
vi primes;
vi revP;
vi fac;
map <int, int> map1;

void sieve(){
    int size = 1000101;
    bs.set(); bs[0] = bs[1] = 0;
    for(ll i = 2; i <= size; i++) if(bs[i]){
            primes.push_back(i);
            for(ll j = i * i; j <= size; j += i)
                bs[j] = 0;
        }
}

int factors(int k){
    int res = 0;
    for(int i=0; primes[i] * primes[i] <= k; i++){
        while(k % primes[i] == 0){
            k /= primes[i]; res++;
        }
    }
    if(k != 1) res++;
    return res;
}

void reversePrime(){
    string a;
    for(int i=0; primes[i] < 1000000; i++){
        a = to_string(primes[i]);
        reverse(a.begin(), a.end());
        while(a.size() < 7) a += '0';
        revP.push_back(stoi(a));
    }
    sort(revP.begin(), revP.end());
    fac.resize(revP.size());
    for(int i=0; i<revP.size(); i++){
        map1[revP[i]] = i;
        fac[i] = factors(revP[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve();
    reversePrime();
    FenwickTree ft((int)fac.size()), satvik((int)fac.size());
    for(int i=1; i<=fac.size(); i++){
        ft.adjust(i, 1);
        satvik.adjust(i, fac[i-1]);
    }
    char last; int n;
    int lo, mid, hi, ans;
    while(cin >> last >> n){
        if(last == 'q'){
            lo = 1; hi = fac.size(); ans = hi;
            while(lo <= hi){
                mid = lo + (hi-lo)/2;
                if(ft.rsq(mid) > n) ans = min(ans, mid), hi = mid - 1;
                else lo = mid + 1;
            }
            cout << satvik.rsq(ans) << endl;
        }else{
            int index = map1[n];
            ft.adjust(index+1, -1);
            satvik.adjust(index+1, -fac[index]);
        }
    }
    return 0;
}