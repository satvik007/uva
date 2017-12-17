#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector <ll> cat(30), sup(30);
    cat[0] = cat[1] = sup[0] = sup[1] = sup[2] = 1; cat[2] = 2;
    for(int i=3; i<30; i++){
        cat[i] = (2 * (2 * i - 1) * cat[i-1]) / (i+1);
        sup[i] = ((6*i - 9) * sup[i-1] - (i-3) * sup[i-2])/ i;
    }
    int n;
    while(cin >> n){
        cout << (sup[n] - cat[n-1]) << "\n";
    }
    return 0;
}