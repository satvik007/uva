#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;

vector <vi> a(26);
vector <bool> status(26);

void stack1(int u){
    status[u] = true;
    for(auto el: a[u]){
        if(status[el] == false){
            stack1(el);
        }
    }
}
void bfs(){
    fill(status.begin(), status.end(), true);
    string b;
    cin >> b;
    for(int i=0; i<b.size(); i+=2) status[b[i]-'A'] = false;
    int count1 = 0;
    int count2 = 0;
    for(int i=0; i<26; i++){
        if(status[i] == false){
            if(a[i].empty()) count2++;
            else {
                count1++;
                stack1(i);
            }
        }
    }
    cout << "There are " << count1 << " tree(s) and " << count2 << " acorn(s).\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    string line;
    while(t--){
    	a.clear();
    	a.resize(26);
        while(cin >> line){
            if(line[0] == '*') break;
            a[line[1]-'A'].push_back(line[3]-'A');
            a[line[3]-'A'].push_back(line[1]-'A');
        }
        bfs();
    }
    return 0;
}
