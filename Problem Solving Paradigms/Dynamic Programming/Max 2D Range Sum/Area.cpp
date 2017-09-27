#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m, maxprice;
int a[105][105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        cout << "Case #" << cas << ": ";
        cin >> n >> m >> maxprice;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> a[i][j];
                if(i > 0) a[i][j] += a[i-1][j] ;
                if(j > 0) a[i][j] += a[i][j - 1];
                if(j > 0 && i > 0) a[i][j] -= a[i - 1][j - 1];
            }
        }
        int maxRect = INT_MIN;
        int subRect;
        int area;
        int var = INT_MAX;
        for(int j = 0; j < n; ++j) for(int k = 0; k < m; ++k)
                for(int l = j; l < n; ++l) for(int r = k; r < m; ++r){
                        subRect = a[l][r];
                        if(j > 0) subRect -= a[j-1][r];
                        if(k > 0) subRect -= a[l][k-1];
                        if(j > 0 && k > 0) subRect += a[j-1][k-1];
                        area = (l-j+1)*(r-k+1);
                        if(subRect <= maxprice && area > maxRect){
                            maxRect = area;
                            var = subRect;
                        }
                        else if(subRect <= maxprice && area == maxRect){
                            var = min(var, subRect);
                        }
                    }
        if(maxRect == INT_MIN) cout << "0 0\n";
        else cout << maxRect << " " << var << "\n";

    }
    return 0;

}

