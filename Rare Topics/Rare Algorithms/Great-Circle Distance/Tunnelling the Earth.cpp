#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef map <string, int> msi;
typedef pair <double, double> ii;

#define EPS 1e-6
#define PI acos(-1)

double gcDistance(ii f1, ii f2, double radius = 6371009) {
    double pLat=f1.first, pLong=f1.second, qLat=f2.first, qLong=f2.second;
    pLat *= PI / 180; pLong *= PI / 180;
// convert degree to radian
    qLat *= PI / 180; qLong *= PI / 180;
    return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
                         cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
                         sin(pLat)*sin(qLat));
}

map <string, ii> cities;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    cout << fixed << setprecision(0);
    cin >> n;
    while(n--){
        ii a, b;
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        double current = gcDistance(a, b);
        current = current - 6371009.0 * 2 * sin(current/6371009.0/2);
        cout << current << "\n";
    }

    return 0;
}