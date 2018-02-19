#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int a[110][10];

void AtoR(int A) {
    int v = A;
    map<int, string> cvt;
    cvt[1000] = "M"; cvt[900] = "CM"; cvt[500] = "D"; cvt[400] = "CD";
    cvt[100] = "C"; cvt[90] = "XC"; cvt[50] = "L"; cvt[40] = "XL";
    cvt[10] = "X"; cvt[9] = "IX"; cvt[5] = "V"; cvt[4] = "IV";
    cvt[1] = "I";
// process from larger values to smaller values
    for (map<int, string>::reverse_iterator i = cvt.rbegin(); i != cvt.rend(); i++)
        while (A >= i->first) {
            string current = ((string)i->second).c_str();
            for(auto el:current){
                switch(el){
                    case 'I': a[v][0]++; break;
                    case 'V': a[v][1]++; break;
                    case 'X': a[v][2]++; break;
                    case 'L': a[v][3]++; break;
                    case 'C': a[v][4]++; break;
                }
            }
            A -= i->first;
        }
    for(int i=0; i<5; i++){
        a[v][i] += a[v-1][i];
    }
}



int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(a, 0, sizeof a);
    for(int i=1; i<=100; i++){
        AtoR(i);
    }
    int n;
    while(cin >> n, n){
        cout << n << ": ";
        cout << a[n][0] << " i, " << a[n][1] << " v, " << a[n][2] << " x, " <<
            a[n][3] << " l, " << a[n][4] << " c\n";
    }
    return 0;
}