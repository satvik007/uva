#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <double, double> pdd;
#define eps 1e-9

pdd calcDist(const pdd f, const pdd s, const double x0, const double y0){
    double m = (s.second - f.second)/(s.first - f.first);
    double c1 = f.second - m * f.first;
    double c2 = y0 + x0 / m;
    double x = (c2 - c1)/(m + 1 / m);
    double y = (m*c2 + c1 / m)/(m + 1 / m);
    if(x < min(f.first, s.first)-eps || x > max(f.first, s.first)+eps){
        return (hypot(f.first - x0, f.second - y0) <=  hypot(s.first - x0, s.second - y0)) ?
                f : s;
    }else{
        return {x, y};
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    double x, y;
    vector <pdd> a;
    cout << setprecision(4) << fixed;
    while(cin >> x >> y){
        double theta = 1.023;
        double tempx, tempy;
        tempx = x * cos(theta) + y * sin(theta);
        tempy = - x * sin(theta) + y * cos(theta);
        x = tempx, y = tempy;
        int n; cin >> n;
        a.resize(n+1);
        for(int i=0; i<n+1; i++) {
            cin >> a[i].first >> a[i].second;
            double tx = a[i].first * cos(theta) + a[i].second * sin(theta);
            double ty = -a[i].first * sin(theta) + a[i].second * cos(theta);
            a[i].first = tx; a[i].second = ty;
        }
        double ans = INT_MAX;
        pdd final;
        for(int i=0; i<n; i++){
            pdd points = calcDist(a[i], a[i+1], x, y);
            double dist = hypot(points.first - x, points.second - y);
            if(dist < ans){
                ans = dist;
                final = points;
            }
        }
        double tx = final.first * cos(theta) - final.second * sin(theta);
        double ty = final.first * sin(theta) + final.second * cos(theta);
        cout << tx+eps << "\n" << ty+eps << "\n";
    }
    return 0;
}