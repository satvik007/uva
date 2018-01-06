#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a, b;
int dp[500][500];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> a >> b){
        if(cas != 1) cout << "\n"; cas++;
        memset(dp, 0, sizeof dp);
        int max1 = -1;
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<b.size(); j++){
                if(a[i] == b[j]) dp[i+1][j+1] = max(1, dp[i][j] + 1);
                max1 = max(max1, dp[i+1][j+1]);
            }
        }
        if(max1 == 0){
            cout << "No common sequence.\n"; continue;
        }
        set <string> names;
        for(int i=1; i<=a.size(); i++){
            for(int j=1; j<=b.size(); j++){
                if(dp[i][j] == max1){
                    names.insert(a.substr(i - max1, max1));
                }
            }
        }
        for(auto el:names) cout << el << "\n";
    }
    return 0;
}