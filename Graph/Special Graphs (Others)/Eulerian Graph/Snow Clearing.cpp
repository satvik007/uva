#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef pair <int, bool> ib;

int t, fx, fy, k, p, q, r, s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t; cin.ignore();
    while(t--){
        cin >> fx >> fy;
        cin.ignore();
        double dist=0;
        while(cin.peek() != '\n' && cin.peek() != EOF){
            cin >> p >> q >> r >> s; cin.ignore();
            dist += hypot(p-r, q-s) / 1000 / 20 * 2;
        }
        int hour = dist;

        int minute = round((dist - hour) * 60);
        if (minute == 60) {
            hour++;
            minute = 0;
        }
        cout << hour << ":";
        if (minute < 10)
            cout << "0";
        cout << minute << "\n";
        if(t) cout << "\n";
    }
    return 0;
}