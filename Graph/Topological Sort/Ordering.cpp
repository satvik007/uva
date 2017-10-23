#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int a[40][40];
string names, temp;
int n, flag;
bool visited[256];

void dfs(){
    if(temp.size() == n) {
        flag = 0;
        cout << temp[0];
        for(int i=1; i<n; i++) cout << " " << temp[i]; cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            int solve = 1;
            for(auto el:temp){
                if(a[names[i]-'A'][el-'A']){
                    solve = 0; break;
                }
            }
            if(solve){
                visited[i] = true;
                temp += names[i];
                dfs();
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t; cin.ignore();
    string line;
    char c1, c2, null;
    while(t--){
        memset(a, 0, sizeof a);
        names.clear();
        getline(cin, line);
        getline(cin, line);
        stringstream take1(line);
        while(take1 >> c1) names += c1;
        sort(names.begin(), names.end());
        n = (int)names.size();
        getline(cin, line);
        stringstream take2(line);
        while(take2 >> c1 >> null >> c2){
            a[c1-'A'][c2-'A'] = 1;
        }
        temp.clear();
        flag = 1;
        memset(visited, false, sizeof visited);
        dfs();
        if(flag) cout << "NO\n";
        if(t) cout << "\n";
    }
}