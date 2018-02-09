#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

stack <int> s;
string a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc; cin.ignore();
    while(tc--){
        getline(cin, a);
        bool flag = true;
        for(int i=0; i<a.size(); i++){
            if(a[i] == '(')
                s.push(a[i]);
            else if(a[i] == '[')
                s.push(a[i]);
            else if(a[i] == ')'){
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else {
                    flag = false; break;
                }
            }else if(a[i] == ']'){
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else {
                    flag = false; break;
                }
            }
        }
        if(flag && s.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
        while(!s.empty())
            s.pop();
    }
    return 0;
}