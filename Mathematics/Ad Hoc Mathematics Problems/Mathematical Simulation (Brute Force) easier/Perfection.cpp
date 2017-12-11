#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << "PERFECTION OUTPUT\n";
    while(cin >> n, n){
        cout << setw(5) << n << "  ";
        int counter = 0;
        for(int i=1; i<n; i++){
            if(n % i == 0) counter += i;
        }
        if(counter < n) cout << "DEFICIENT\n";
        else if(counter == n) cout << "PERFECT\n";
        else cout << "ABUNDANT\n";
    }
    cout << "END OF OUTPUT\n";
    return 0;
}