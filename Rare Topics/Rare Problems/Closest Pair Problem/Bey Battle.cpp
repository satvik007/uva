#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <double, double> ii;
#define inf (int)1e9

int n;
ii a[100010];

double dist(int i, int j){
    return max(abs(a[i].first - a[j].first), abs(a[i].second - a[j].second))/2;
}

double solve(int left, int right){
    if(left >= right)
        return inf;
    int mid = (left + right)/2;
    double d = min(solve(left, mid), solve(mid+1, right));
    double line = (a[mid].first + a[mid+1].first)/2;
    double min1 = d;
    for(int i=mid+1; i<=right && a[i].first < line + d; i++){
        for(int j = mid; j >= left && a[j].first > line - d; j--){
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
    cout << fixed << setprecision(0);
    while(cin >> n){
        for(int i=0; i<n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a, a+n);
        double ans = solve(0, n-1);
        cout << ans*2 << "\n";
    }
    return 0;
}