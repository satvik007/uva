#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a;
    while(cin >> a, a != "."){
        string u;
        for(int i=1; i<=a.size(); i++){
            if(a.size() % i) continue;
            u = a.substr(0, i);
            int flag = 1;
            for(int j=0; j<a.size(); j++){
                if(a[j] != u[j % u.size()]){
                    flag = 0; break;
                }
            }
            if(flag){
                cout << (a.size() / i) << "\n"; break;
            }
        }
    }
    return 0;
}