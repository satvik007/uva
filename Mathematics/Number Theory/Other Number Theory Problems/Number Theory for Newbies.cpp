#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long n;
    while(cin >> n){
        string a = to_string(n);
        sort(a.begin(), a.end());
        string b = a; reverse(b.begin(), b.end());
        if(a[0] == '0')
        for(int i=0; i<a.size(); i++){
            if(a[i] != '0'){
                swap(a[i], a[0]); break;
            }
        }
        ll u = stol(a), v = stol(b);
        cout << v << " - " << u << " = " << (v - u) << " = 9 * " << (v - u) / 9 << "\n";
    }
    return 0;
}