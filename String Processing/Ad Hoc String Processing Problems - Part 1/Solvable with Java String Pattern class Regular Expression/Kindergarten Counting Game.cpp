#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a;
    while(cin.peek() != EOF){
        getline(cin, a);
        int flag = 0, counter = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z'){
                if(!flag) {
                    flag = 1; counter++;
                }
            }else flag = 0;
        }
        cout << counter << "\n";
    }
    return 0;
}