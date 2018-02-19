#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn  2000010

int n, a[maxn];
int c[120];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        memset(c, 0, sizeof c);
        for(int i=0; i<n; i++){
            cin >> a[i]; c[a[i]]++;
        }
        int k = 0;
        for(int i=0; i<100; i++){
            while(c[i]){
                if(k) cout << " ";
                cout << i;
                k++;
                c[i]--;
            }
        }
        cout << "\n";
    }
    return 0;
}