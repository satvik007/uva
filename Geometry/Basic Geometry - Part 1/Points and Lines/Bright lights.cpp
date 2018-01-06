#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef pair <double, double> pdd;
#define eps 1e-10
#define inf 1e60

class Data{
public:
    double x, y, z, rot;
    double slope;
};
bool comp(const Data &a, const Data &b){
    if(a.rot != b.rot){
        return (a.rot > b.rot);
    }
    else if(fabs(b.slope - a.slope) > eps){
        return (a.slope <= b.slope);
    }
    else{
        return (abs(a.x) <= abs(b.x));
    }
}

bool comp2(const pdd x, const pdd y){
    if(x.first == y.first) return x.second < y.second;
    else return x.first < y.first;
}
double theta = 49.494949;
int n;
vector <Data> a;
vector <ii> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    cout << setprecision(0) << fixed;
    while(cin >> n, n){
        a.resize(n); ans.clear();
        for(int i=0; i<n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
            double tx, ty;
            tx = a[i].x * cos(theta) + a[i].y * sin(theta);
            ty = - a[i].x * sin(theta) + a[i].y * cos(theta);
            a[i].x = tx; a[i].y = ty;
            a[i].rot = (a[i].y > 0);
            a[i].slope = a[i].y / a[i].x;
        }
        sort(a.begin(), a.end(), comp);
        double last = -1.23, height = 0;
        for(int i=0; i<n; i++){
            if(fabs(a[i].slope - last) < eps){
                if(a[i].z <= height){
                    double tx, ty;
                    tx = a[i].x * cos(theta) - a[i].y * sin(theta);
                    ty = a[i].x * sin(theta) + a[i].y * cos(theta);
                    ans.push_back({round(tx), round(ty)});
                }else{
                    height = a[i].z;
                }
            }else{
                height = a[i].z;
                last = a[i].slope;
            }
        }
        cout << "Data set " << cas++ << ":\n";
        if(ans.empty()){
            cout << "All the lights are visible.\n";
        }else{
            sort(ans.begin(), ans.end(), comp2);
            sort(ans.begin(), ans.end(), comp2);
            cout << "Some lights are not visible:\n";
            for(int i=0; i<ans.size(); i++){
                cout << "x = " << ans[i].first << ", y = " << ans[i].second;
                if(i == ans.size()-1) cout << ".\n";
                else cout << ";\n";
            }
        }
    }
    return 0;
}