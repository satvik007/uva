#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc;
vector <string> a(10);
map <string, char> map1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    for(int i=0; i<128; i++){
        string temp; temp += '0';
        int res = 1;
        for(int j=0; j<8; j++){
            temp += (char)((i/res)%2 + '0');
            res <<= 1;
        } temp += '0';
        map1[temp] = (char)(i);
    }
    while(tc--){
        for(int i=0; i<10; i++) cin >> a[i];
        for(int i=1; i<a[0].size()-1; i++){
            string temp;
            for(int j=0; j<10; j++){
                temp += (a[j][i] == '/' ? '0' : '1');
            }
            cout << map1[temp];
        }
        cout << "\n";
    }
    return 0;
}