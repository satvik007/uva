#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll ipow(ll base, ll exp) {
    ll result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n, n){
        if (n==1){
            cout << "0\n";
            continue;
        }
        int sum=0, count=0;
        while (1) {
            sum += sum+1;
            if (sum<n) count++;
            else if (sum>=n) break;
        }
        cout << count << "\n";
    }
    return 0;
}
