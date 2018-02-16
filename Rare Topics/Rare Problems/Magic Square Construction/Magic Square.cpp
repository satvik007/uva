#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int a[20][20];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    int cas = 1;
    while(cin >> n){
        if(cas != 1) cout << "\n";
        cas++;
        memset(a, 0, sizeof a);
        int cnt = 1;
        a[0][n/2] = 1;
        int x = 0, y = n/2;
        int tx, ty;
        while(cnt != n*n){
            tx = (x-1+n)%n;
            ty = (y+1)%n;
            if(a[tx][ty]){
                x = (x + 1)%n;
                a[x][y] = ++cnt;
            }else{
                a[tx][ty] = ++cnt;
                x = tx, y = ty;
            }
        }
        int max1 = -1;
        cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                string b = to_string(a[i][j]);
                max1 = max(max1, (int)b.size());
            }
            cnt += a[i][0];
        }
        cout << "n=" << n << ", sum=" << cnt << "\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << setw(max1+1) << a[i][j];
            }
            cout << "\n";
        }

    }
    return 0;
}