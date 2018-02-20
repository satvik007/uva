#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <int> a[3];

int n, m, counter;

void init(){
    a[0].clear(); a[1].clear(); a[2].clear();
    counter = 0;
    a[0].resize(n);
    for(int i=0; i<n; i++) a[0][i] = n - i;
}

void transfer(int from, int mid, int to){
    int val = a[from].back();
    a[from].pop_back();
    a[to].push_back(val);
    for(int i=0; i<3; i++){
        cout << (char)('A'+i) << "=>";
        if(!a[i].empty()) cout << "   ";
        for(int j=0; j<a[i].size(); j++){
            if(j) cout << " ";
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve(int n, int from, int mid, int to){
    if(counter == 0) return;
    if(n == 1) {
        transfer(from, mid, to);
        counter--;
    }else{
        solve(n-1, from, to, mid);
        if(counter == 0) return;
        transfer(from, mid, to);
        counter--;
        if(counter == 0) return;
        solve(n-1, mid, from, to);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> m, n||m){
        init();
        counter = m;
        cout << "Problem #" << cas++ << "\n\n";
        for(int i=0; i<3; i++){
            cout << (char)('A'+i) << "=>";
            if(!a[i].empty()) cout << "   ";
            for(int j=0; j<a[i].size(); j++){
                if(j) cout << " ";
                cout << a[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
        solve(n, 0, 1, 2);
    }

    return 0;
}