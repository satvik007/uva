#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    unsigned n; string a, b;
    map <string, int> map1;
    while(cin >> n >> a){
        map1.clear();
        for(unsigned i=0; i<a.size()-n+1; i++){
            b = a.substr(i, n);
            if(map1.find(b) == map1.end()) map1[b] = 1;
            else map1[b]++;
        }
        int max1=-1; string ans;
        for(auto el:map1){
            if(el.second > max1){
                max1 = el.second; ans = el.first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}