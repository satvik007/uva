#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef map <string, int> msi;
typedef pair <double, double> ii;

#define PI acos(-1)

double gcDistance(ii f1, ii f2, double radius = 6378) {
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
    string u, v;
    double p, q;
    while(cin >> u, u != "#"){
        cin >> p >> q;
        cities[u] = {p, q};
    }
    while(cin >> u >> v && u != "#"){
        cout << u << " - " << v << "\n";
        if(!cities.count(u) || !cities.count(v)){
            cout << "Unknown\n"; continue;
        }
        ll dist = round(gcDistance(cities[u], cities[v]));
        if(dist < 0) dist = 0;
        cout << dist << " km\n";
    }

    return 0;
}