#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m;
    string wake;
    string temp;
    while(cin >> n >> m){
        cin >> wake;
        int k = 0;
        vector <vi> a(26, vi(26));
        vi pres(26);
        pres.assign(26, 0);
        for(int i=0; i<26; i++) a[i].assign(0, 26);
        for(int i=0; i<m; i++){
            cin >> temp;
            pres[temp[0]-'A'] = 1;
            pres[temp[1]-'A'] = 1;
            a[temp[0]-'A'][temp[1]-'A'] = 1;
            a[temp[1]-'A'][temp[0]-'A'] = 1;
        }
        vi b(26);
        b.assign(26, 0);
        for(auto el:wake) b[el-'A'] = 1;
        int flag = 1;
        int time = 0;
        vector <int> c;
        while(flag == 1){
            time++;
            flag = 0;
            for(auto el:c) b[el] = 1;
            c.clear();
            for(int i=0; i<26; i++){
                if(pres[i] == 0 or b[i] == 1) continue;
                int status = 0;
                for(int j=0; j<26; j++){
                    if(a[i][j] == 1 && b[j] == 1) status++;
                }
                if(status >= 3) c.push_back(i), flag = 1;
            }
        }
        int counter = 0;
        for(int i=0; i<26; i++) if(b[i] == 1) counter++;
        if(counter == n) cout << "WAKE UP IN, " << time-1 << ", YEARS\n";
        else cout << "THIS BRAIN NEVER WAKES UP\n";
    }
    return 0;
}
