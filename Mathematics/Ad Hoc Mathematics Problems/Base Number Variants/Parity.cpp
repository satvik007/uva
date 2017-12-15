#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        bitset<32> a(n);
        int counter = 0;
        for(int i=0; i<32; i++){
            if(a.test(i)) counter++;
        }
        string b;
        int flag = 0;
        for(int i=31; i>=0; i--){
            if(a[i]) flag = 1;
            if(flag) b += (char)(a[i] + '0');
        }

        cout << "The parity of " << b << " is " << counter << " (mod 2).\n";
    }
    return 0;
}
