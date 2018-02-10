#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<double, double> ii;
#define inf LONG_MAX

int n;
ii a[10010];

double dist(int i, int j){
    return hypot(a[i].first - a[j].first, a[i].second - a[j].second);
}
double solve(int left, int right){
    if(left >= right)
        return inf;
    int mid = (left + right)/2;
    double d = min(solve(left, mid), solve(mid+1, right));
    double min1 = d;
    double line = (a[mid].first + a[mid+1].first)/2;
    for(int i=mid+1; i<=right && a[i].first < line + d; i++){
        for(int j=mid; j >= left && a[j].first > line - d; j--){
            min1 = min(min1, dist(i, j));
        }
    }
    return min1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << setprecision(4) << fixed;
    while(cin >> n && n){
        for(int i=0; i<n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a, a+n);
        double ans = solve(0, n-1);
        if(ans >= 10000.0) cout << "INFINITY\n";
        else cout << ans << "\n";
    }
    return 0;
}