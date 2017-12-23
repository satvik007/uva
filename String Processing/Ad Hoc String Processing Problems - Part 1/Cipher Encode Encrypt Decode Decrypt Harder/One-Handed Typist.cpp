#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

set <string> set1;
string line, u, v;
int max1 = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> line){
        if(line == "#") break;
        set1.insert(line);
    } cin.ignore();
    vector <string> b; line.clear();
    getline(cin, line);// cout << line << endl;
    for(int i=1; i<28; i++){
        for(int j=0; j<line.size(); j++){
            if(line[j] == ' ') line[j] = 'A';
            else if(line[j] == 'Z') line[j] = ' ';
            else line[j]++;
        }
        stringstream sin(line);
        int counter = 0;
        while(sin >> u){
            if(set1.find(u) != set1.end()) counter++;
        }
        if(counter > max1){
            max1 = counter; v = line;
        }
    }
    stringstream sin(v);
    string ans;
    while(sin >> u){
        if(ans.empty()) ans = u;
        else if(ans.size() + 1 + u.size() <= 60) ans += " " + u;
        else cout << ans << "\n"; ans = u;
    }
    if(!ans.empty()) cout << ans << "\n";
    return 0;
}