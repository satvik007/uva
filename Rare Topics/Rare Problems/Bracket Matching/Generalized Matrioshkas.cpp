#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    stack <int> s, r;
    stack <int> q;
    string b; int u;
    vi a;
    while(cin.peek() != EOF){
        getline(cin, b);
        stringstream sin(b); a.clear();
        while(sin >> u)
            a.push_back(u);
        auto n = int(a.size());
        bool flag = true;
        for(int i=0; i<n; i++) {
            if(a[i] < 0){
                s.push(-a[i]);
                if(q.empty()){
                    q.push(-a[i]);
                }else{
                    int t = q.top(); q.pop();
                    t += a[i];
                    if(t <= 0){
                        flag = false;
                        break;
                    }
                    q.push(t);
                    q.push(-a[i]);
                }
            }else{
                if(!s.empty() && s.top() == a[i])
                    s.pop(), q.pop();
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(s.empty() && flag) cout << ":-) Matrioshka!\n";
        else cout << ":-( Try again.\n";
        while(!s.empty())
            s.pop();
        while(!q.empty())
            q.pop();
    }
    return 0;
}