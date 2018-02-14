#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef map <string, int> msi;
typedef pair <double, double> ii;

#define EPS 1e-6
#define PI acos(-1)

double gcDistance(ii f1, ii f2, double radius = 1) {
    double pLat=f1.first, pLong=f1.second, qLat=f2.first, qLong=f2.second;
    pLat *= PI / 180; pLong *= PI / 180;
// convert degree to radian
    qLat *= PI / 180; qLong *= PI / 180;
    return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
                         cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
                         sin(pLat)*sin(qLat));
}

map <string, ii> cities;
vector <ii> a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    cout << fixed << setprecision(2);
    while(cin >> n) {
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        double max1 = LONG_MAX;
        ii ans;
        for (int i = 0; i < n; i++) {
            double cnt = 0;
            for (int j = 0; j < n; j++) {
                if(i != j)
                    cnt = max(cnt, gcDistance(a[i], a[j]));
            }
            if (cnt < max1 || fabs(max1 - cnt) < 1e-5) {
                max1 = cnt;
                ans = a[i];
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}