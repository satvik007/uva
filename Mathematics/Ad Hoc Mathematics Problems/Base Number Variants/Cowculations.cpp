#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

int tc;
map <char, int> map1;
map <int , char> map2;

int convert(string a){
    int res = 0;
    int mult = 1;
    for(int i=0; i<a.size(); i++){
        res += mult * map1[a[a.size()-i-1]];
        mult *= 4;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    cout << "COWCULATIONS OUTPUT\n";
    string a, b;
    map1['V'] = 0; map1['U'] = 1; map1['C'] = 2; map1['D'] = 3;
    map2[0] = 'V'; map2[1] = 'U'; map2[2] = 'C'; map2[3] = 'D';
    while(tc--){
        cin >> a >> b;
        int n1 = convert(a), n2 = convert(b);
        char last;
        //cout << a << " " << n1 << endl << b << " " << n2 << endl;
        for(int i=0; i<3; i++){
            cin >> last;
            if(last == 'A'){
                n2 += n1;
            }else if(last == 'L'){
                n2 <<= 2;
            }else if(last == 'R'){
                n2 >>= 2;
            }
        }
        string ans; cin >> ans;
        int final = convert(ans);
        if(n2 == final) cout << "YES\n";
        else cout << "NO\n";
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
