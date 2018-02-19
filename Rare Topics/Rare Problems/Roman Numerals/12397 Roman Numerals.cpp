#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

map <char, int> value;

void AtoR(int A) {
    map<int, string> cvt;
    cvt[1000] = "M"; cvt[900] = "CM"; cvt[500] = "D"; cvt[400] = "CD";
    cvt[100] = "C"; cvt[90] = "XC"; cvt[50] = "L"; cvt[40] = "XL";
    cvt[10] = "X"; cvt[9] = "IX"; cvt[5] = "V"; cvt[4] = "IV";
    cvt[1] = "I";
    int res = 0;
// process from larger values to smaller values
    for (map<int, string>::reverse_iterator i = cvt.rbegin();
         i != cvt.rend(); i++)
        while (A >= i->first) {
            string current = ((string)i->second).c_str();
            for(auto el:current){
                res += value[el];
            }
            //cout << current;
            A -= i->first;
        }
    cout << res << "\n";
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    value['I'] = 1; value['V'] = 2;
    value['X'] = 2; value['L'] = 2;
    value['C'] = 2; value['D'] = 3;
    value['M'] = 4;
    while(cin >> n){
        AtoR(n);
    }
    return 0;
}