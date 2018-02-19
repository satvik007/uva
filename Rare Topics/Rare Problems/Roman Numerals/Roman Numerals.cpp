#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

void AtoR(int A) {
    map<int, string> cvt;
    cvt[1000] = "M"; cvt[900] = "CM"; cvt[500] = "D"; cvt[400] = "CD";
    cvt[100] = "C"; cvt[90] = "XC"; cvt[50] = "L"; cvt[40] = "XL";
    cvt[10]
            = "X"; cvt[9]
                           = "IX"; cvt[5]
                                           = "V"; cvt[4]
                                                          = "IV";
    cvt[1]
            = "I";
// process from larger values to smaller values
    for (map<int, string>::reverse_iterator i = cvt.rbegin();
         i != cvt.rend(); i++)
        while (A >= i->first) {
            printf("%s", ((string)i->second).c_str());
            A -= i->first; }
    printf("\n");
}
void RtoA(char R[]) {
    map<char, int> RtoA;
    RtoA['I'] = 1;
    RtoA['V'] = 5;
    RtoA['X'] = 10;
    RtoA['L'] = 50;
    RtoA['C'] = 100; RtoA['D'] = 500; RtoA['M'] = 1000;
    int value = 0;
    for (int i = 0; R[i]; i++)
        if (R[i+1] && RtoA[R[i]] < RtoA[R[i+1]]) {
            value += RtoA[R[i + 1]] - RtoA[R[i]];
            i++; }
        else value += RtoA[R[i]];
    printf("%d\n", value);
// check next char first
// by definition
// skip this char
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    char a[100];
    while(cin >> a){
        if(a[0] <= '9'){
            AtoR(stoi(a));
        }else{
            RtoA(a);
        }
    }
    return 0;
}