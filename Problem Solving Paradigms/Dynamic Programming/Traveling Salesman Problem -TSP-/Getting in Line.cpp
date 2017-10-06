#include <bits/stdc++.h>
using namespace std;

int x[10], y[10];
int n, i, p[10];
double dist[10][10];

void solve(){
    int a[10];
    double min1 = 100000000, temp;
    do{
        double sum = 0;
        for(int i=1; i<n; i++){
            sum += dist[p[i]][p[i-1]];
        }
        if(sum < min1) {
            min1 = sum;
            for(i = 0; i < n; i++)
                a[i] = p[i];
        }
    }while(next_permutation(p, p+n));
    for(int i=1; i<n; i++){
        cout << "Cable requirement to connect (" << x[a[i-1]] << "," << y[a[i-1]]
             << ") to (" << x[a[i]] << "," << y[a[i]] << ") is "
             << dist[a[i]][a[i-1]] << " feet.\n";
    }
    cout << "Number of feet of cable required is " << min1 << ".\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cas = 1;
    cout << setprecision(2) << fixed;
    while(cin >> n, n){
        for(int i=0; i<n; i++) cin >> x[i] >> y[i], p[i] = i;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2))+16;
            }
        }
        cout << "**********************************************************\n";
        cout << "Network #" << cas << "\n";
        solve();
        cas++;
    }
    return 0;
}