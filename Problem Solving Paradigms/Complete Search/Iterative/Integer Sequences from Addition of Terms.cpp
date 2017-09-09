#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll t, d, k, temp, sum, n;
    int deg;
    cin >> t;
    vi a;
    while(t--){
        cin >> deg;
        a.resize(deg+1);
        for(int i=0; i<deg+1; i++) cin >> a[i];
        cin >> d >> k;
        temp = 0;
        n = 0;
        while(1){
            n++;
            if(n*(n+1)/2*d >= k) break;
        }
        sum = 0;
        temp = 1;
        for(int i=0; i<deg+1; i++){
        	sum += a[i]*temp;
        	temp *= n;
		}
		cout << sum << "\n";
    }
}
