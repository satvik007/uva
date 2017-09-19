#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int t, n, counter;
ll sum = 0;
//vi a;
string a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        cout << "Case " << cas << ": ";
        cin >> n;
        cin >> a;
        counter = 0;
        for(int i=0; i<n; i++){
            if(a[i] == '.'){
                counter++;
                i+=2;
            }
        }
        cout << counter << "\n";
    }
}
