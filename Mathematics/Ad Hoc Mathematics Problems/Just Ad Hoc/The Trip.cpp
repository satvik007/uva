#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

int n;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(2);
    double c[1010];
    while(cin >> n, n){
        double avg = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lf", &c[i]);
            avg += c[i];
        }
        avg = avg / n;
        double pos = 0, neg = 0;
        for(int i = 0; i < n; i++) {
            double v = (long) ((c[i] - avg) * 100.0) / 100.0;
            if(v > 0) pos += v;
            else neg += v;
        }
        neg = -neg;
        printf("$%.2f\n", neg > pos? neg : pos);
    }
    return 0;
}
