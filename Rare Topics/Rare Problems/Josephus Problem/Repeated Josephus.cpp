#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, n;

int survivor(int n){
    bitset <32> bs(n);
    int i;
    for(i=31; i>=0; i--){
        if(bs[i]) break;
    }
    for(int j=i-1; j>=0; j--){
        bs[j+1] = bs[j];
    }
    bs[0] = 1;
    n = bs.to_ullong();
    return n;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    int cas = 1;
    while(tc--){
        cin >> n;
        cout << "Case " << cas++ << ": ";
        int cnt = 0;
        while(survivor(n) != n){
            n = survivor(n);
            cnt++;
        }
        cout << cnt << " " << n << "\n";
    }
    return 0;
}