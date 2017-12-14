#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <ll> ans;

void func(const vi &num, const vi &que){
    int n = (int)num.size(), m = (int)que.size();
    for(int i=0; i<m; i++){
        int x = que[i];
        ll final=0;
        for(int j=0; j<n; j++){
            final = (final) * x + num[j];
        }
        ans.push_back(final);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a, b;
    while(cin.peek() != '\n' && cin.peek() != EOF){
        ans.clear();
        getline(cin, a); getline(cin, b);
        //cout << a << " " << b << endl;
        stringstream cin1(a), cin2(b);
        int u;
        vi num;
        while(cin1 >> u) num.push_back(u);
        vi que;
        while(cin2 >> u) que.push_back(u);
        func(num, que);
        cout << ans[0];
        for(int i=1; i<ans.size(); i++){
            cout << " " << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
