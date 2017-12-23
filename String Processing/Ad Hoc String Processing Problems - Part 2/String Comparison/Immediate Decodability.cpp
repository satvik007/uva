#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector <string> a;
    int cas = 1;
    while(cin.peek() != EOF){
        a.clear();
        string u;
        int flag = 1;
        while(cin >> u && u != "9") a.push_back(u); cin.ignore();
        int n = a.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(a[i][0] == a[j][0]){
                    if(a[i].find(a[j]) == 0) flag = 0;
                    if(a[j].find(a[i]) == 0) flag = 0;
                }
            }
        }
        if(flag) cout << "Set " << cas++ << " is immediately decodable\n";
        else cout << "Set " << cas++ << " is not immediately decodable\n";
    }
    return 0;
}