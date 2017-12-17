#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector <int> cat(11);
    cat[0] = 1;
    for(int i=1; i<=10; i++){
        cat[i] = (2*(2*i-1) * cat[i-1])/ (i+1);
    }
    int n;
    int cas = 1;
    while(cin >> n){
        if(cas != 1) cout << "\n"; cas++;
        cout << cat[n] << "\n";
    }
    return 0;
}