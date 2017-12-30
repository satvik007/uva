#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a;
ll dp[205];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc; cin.ignore();
    while(tc--){
        getline(cin, a);
        memset(dp, 0, sizeof dp);
        string u, v;
        for(int i=1; i<=a.size(); i++){
            ll max1 = -1;
            for(int j=0; j<=10 && i + j <= a.size(); j++){
                u = a.substr(i-1, j+1);
                if(u[0] == '0' && u != "0") continue;
                ll temp = stoll(u);
                if(temp <= INT_MAX) dp[i+j] = max(dp[i+j], temp + dp[i-1]);
            }
        }
        cout << dp[a.size()] << "\n";
    }
    return 0;
}