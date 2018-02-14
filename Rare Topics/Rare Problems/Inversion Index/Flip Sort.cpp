#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, a[1010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n){
        for(int i=0; i<n; i++)
            cin >> a[i];
        int key;
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n-1; j++){
                if(a[j] > a[j+1]) swap(a[j], a[j+1]), cnt++;
            }
        }
        cout << "Minimum exchange operations : " << cnt << "\n";
    }
    return 0;
}