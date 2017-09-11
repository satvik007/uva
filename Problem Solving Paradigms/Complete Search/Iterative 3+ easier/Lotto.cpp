#include <bits/stdc++.h>
#define epsilon 1e-9
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m, counter;
    vi a;
    int cas = 0;
    while(cin >> n, n){
        if(cas != 0) cout << "\n";
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n-5; i++){
            for(int j=i+1; j<n-4; j++){
                for(int k=j+1; k<n-3; k++){
                    for(int l = k+1; l<n-2; l++){
                        for(int m=l+1; m<n-1; m++){
                            for(int o=m+1; o<n; o++){
                                cout << a[i] << " " << a[j] << " " << a[k] << " " <<
                                a[l] << " " << a[m] << " " << a[o] << "\n";                                                   
                            }
                        }
                    }
                }
            }
        }
        cas++;
    }
    return 0;
}
