#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 0;
    while(cin >> n){
        //if(cas) cout << "\n"; cas++;
        int index=1;
        cout << "TERM " << n << " IS ";
        if(n == 1){
            cout << "1/1\n"; continue;
        }
        for(int i=1; n - i > 0; n-=i, i++) index = i;

        if(index % 2){
            cout << n << "/" << (index + 2 - n) << "\n";
        }
        else cout << (index + 2 - n) << "/" << (n) << "\n";
    }
    return 0;
}