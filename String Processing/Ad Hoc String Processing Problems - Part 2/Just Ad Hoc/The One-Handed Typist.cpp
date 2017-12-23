#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <string> a(11);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);


    a[1] = "qaz"; a[2] = "wsx"; a[3] = "edc"; a[4] = "rfvtgb";
    a[7] = "yhnujm"; a[8] = "ik"; a[9] = "ol"; a[10] = "p";

    int n, k;
    int used[30];
    set <string> found;
    while(cin >> n >> k){
        string ans, u;
        int m;
        for(int i=0; i<n; i++){
            cin >> m; ans += a[m];
        }
        memset(used, 0, sizeof used);
        for(int j=0; j<ans.size(); j++) used[ans[j]-'a'] = 1;
        vector <string> b;
        int max1 = -1;
        for(int i=0; i<k; i++){
            cin >> u;
            int flag = 1;
            for(int j=0; j<u.size(); j++){
                if(used[u[j]-'a']){
                    flag = 0; break;
                }
            }
            if(flag){
                if((int)u.size() > max1){
                    max1 = (int)u.size(); found.clear();
                    b.clear(); b.push_back(u); found.insert(u);
                }
                else if((int)u.size() == max1 && found.find(u) == found.end()){
                    b.push_back(u); found.insert(u);
                }
            }
        }
        cout << b.size() << "\n";
        for(int i=0; i<b.size(); i++) cout << b[i] << "\n";
    }

    return 0;
}