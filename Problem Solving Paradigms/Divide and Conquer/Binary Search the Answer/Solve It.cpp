#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;
#define e 1e-7
//p ? e?x + q ? sin(x) + r ? cos(x) + s ? tan(x) + t ? x 2 + u = 0

int p, q, r, s, t, u;

double f(double x){
    return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while(cin >> p >> q >> r >> s >> t >> u){
        double left = 0;
        double right = 1;
        double mid = 0;
        while(right - left > e){
        	//cout << f(mid) << endl;
            mid = left + (right - left)/2;
            if(fabs(f(mid)) < e) break;
            if(f(mid) > 0){
            	if(f(left) > 0) left = mid;
            	else right = mid;
			}
            else {
            	if(f(left) < 0) left = mid;
            	else right = mid;
			}
        }
        double ans = f(mid);
        if(ans < 1e-5 && ans > -1e-5) cout << fixed << setprecision(4) << mid << "\n";
        else cout << "No solution\n";
    }
    return 0;
}
