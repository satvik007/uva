#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
vector <vector <string>> a(30);
vector <vi> c(30);

bool check(string u, string v){
    if(u.size() == v.size()){
        for(int i=0; i<u.size()-1; i++){
            swap(u[i], u[i+1]);
            if(u == v){
                swap(u[i], u[i+1]);
                return true;
            }
            swap(u[i], u[i+1]);
        }
        int cnt = 0;
        for(int i=0; i<u.size(); i++) if(u[i] != v[i]) cnt++;
        return (cnt == 1);
    }else if(u.size() < v.size()){
        assert(u.size() == v.size() - 1);
        for(int i=0; i<u.size(); i++){
            if(u[i] != v[i]){
                u.insert(u.begin() + i, v[i]);
                return (u == v);
            }
        }
        return (v.find(u) != string::npos);
    }else{
        assert(u.size() == v.size() + 1);
        for(int i=0; i<v.size(); i++){
            if(v[i] != u[i]){
                v.insert(v.begin() + i, u[i]);
                return (u == v);
            }
        }
        return (u.find(v) != string::npos);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n;
    set <string> b;
    string u;
    for(int i=0; i<n; i++) {
        cin >> u;
        b.insert(u); a[u.size()].push_back(u);
        c[u.size()].push_back(i);
    }
    int q; cin >> q;
    while(q--){
        cin >> u;
        if(b.find(u) != b.end()){
            cout << u << " is correct\n";
            continue;
        }
        int flag = 1, pos = INT_MAX; string ans;
        for(auto i=(int)u.size()-1; i<=u.size()+1; i++){
            for(int j=0; j<a[i].size(); j++){
                if(c[i][j] > pos) break;
                if(check(u, a[i][j])){
                    pos = c[i][j]; ans = a[i][j]; flag = 0; break;
                }
            }
        }
        if(!flag) cout << u << " is a misspelling of " << ans << "\n";
        if(flag) cout << u << " is unknown\n";
    }
    return 0;
}