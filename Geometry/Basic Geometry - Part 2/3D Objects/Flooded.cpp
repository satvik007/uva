#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m, v;
vi a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int cas = 1;
    while(cin >> n >> m, n||m){
        cout << "Region " << cas++ << "\n";
        a.resize(n*m);
        for(int i=0; i<n*m; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        //for(auto el:a) cout << el << " "; cout << endl;
        cin >> v;
        double height = a[0];
        int area = 0;
        for(int i=0; i<n*m && v; i++){
            int current = a[i];
            int j;
            for(j=i; j<n*m; j++){
                if(a[j] != current){
                    break;
                }
            }
            //cout << i << " " << j << " " << a[i] << " " << a[j] << endl;
            area += (j - i);
            int vol = (a[j] - a[i]) * 100 * (area);
            //cout << vol << " " << v << endl;
            if(v >= vol && j != n*m){
                v -= vol; height = a[j];
            }else {
                height = v / (area*100.0) + a[i];
                break;
            }
            i = j - 1;
        }
        cout << "Water level is " << height << " meters.\n";
        cout << (area * 100.0/ n / m) << " percent of the region is under water.\n\n";

    }
    return 0;
}