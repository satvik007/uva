#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

stack <char> s;
string a;
map <char, int> prec;

/*
 * If we encounter an open bracket, we will push it to the stack. If we
encounter a close bracket, we will output the topmost items of the stack until we encounter
an open bracket (but we do not output the open bracket). If we encounter an operator, we
will keep outputting and then popping the topmost item of the stack if it has greater than or
equal precedence with this operator, or until we encounter an open bracket, then push this
operator to the stack. At the end, we will keep outputting and then popping the topmost
item of the stack until the stack is empty.
 */
void solve(){
    auto n = (int)a.size();
    for(int i=0; i<n; i++){
        if(a[i] >= '0' && a[i] <= '9') cout << a[i];
        else if(a[i] == '(') s.push(a[i]);
        else if(a[i] == ')'){
            while(s.top() != '(') cout << s.top(), s.pop();
            s.pop();
        }else{
            while(!s.empty() && s.top() != '(' && prec.count(s.top()) && prec[s.top()] >= prec[a[i]]){
                cout << s.top(); s.pop();
            }
            s.push(a[i]);
        }
    }
    while(!s.empty()){
        if(s.top() != '(') cout << s.top();
        s.pop();
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    prec['+'] = 5; prec['-'] = 5;
    prec['/'] = 10; prec['*'] = 10;

    int tc; cin >> tc; cin.ignore();
    while(tc--){
        cin.ignore();
        char cur;
        a.clear();
        while(cin.peek() != '\n' && cin.peek() != EOF){
            cin >> cur; cin.ignore();
            a += cur;
        }
        solve();
        if(tc) cout << "\n";
    }
    return 0;
}