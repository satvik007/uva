#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

map <string, char> map1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for(int i=0; i<128; i++){
        bitset <8> bs(i);
        string temp; temp += bs.to_string();
        for(int j=0; j<8; j++){
            if(temp[j] == '0') temp[j] = ' ';
            else if(temp[j] == '1') temp[j] = 'o';
        } temp += '|';
        temp = "|" + temp;
        temp.insert(temp.begin() + 6, '.');
        //cout << temp << " " << (char) i << "\n";
        map1[temp] = (char)i;
    }
    string a;
    int counter = 0;
    while(true){
        getline(cin, a);
        if(a[0] == '_'){
            counter++;
            if(counter >= 2) break; continue;
        }
        cout << map1[a];
    }
    return 0;
}