#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
struct Data{
    int val, ind;
    string name;
    bool operator < (Data b){
        if(val == b.val) return ind < b.ind;
        return val < b.val;
    }
};
vector <Data> a;

inline int inverse(string b){
    int cnt = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<m-1; j++){
            if(b[j] > b[j+1]) swap(b[j], b[j+1]), cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> m >> n;
        a.resize(n);
        for(int i=0; i<n; i++){
            cin >> a[i].name;
            a[i].ind = i;
        }
        for(int i=0; i<n; i++){
            a[i].val = inverse(a[i].name);
        }
        sort(a.begin(), a.end());
        for(int i=0; i<n; i++){
            cout << a[i].name << "\n";
        }
        if(tc) cout << "\n";
    }
    return 0;
}