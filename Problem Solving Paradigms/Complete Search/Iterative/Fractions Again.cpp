#include <bits/stdc++.h>
#define epsilon 1e-6
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int k;
    double one = 1.0;
    while(cin >> k){
        int n = k+1;
        vi a;
        while(n<=2*k){
            if(fabs((int)((n*k*one)/(n-k)) - ((n*k*one)/(n-k))) < epsilon){
                a.push_back(n);
            } 
            n++;
        }
        cout << a.size() << "\n";
        for(auto el : a){
            n = el;
            cout << "1/" << k << " = 1/" << (int)((n*k*one)/(n-k))<< " + 1/" << n << "\n";
        }
    }
    return 0;
}
