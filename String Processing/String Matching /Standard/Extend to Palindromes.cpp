#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a;
    while(cin >> a){
        int flag = 1, ans;
        for(int i=0; i<a.size()-1; i++){
            if(a[i] == a[a.size()-1]){
                int temp = 1;
                for(int j=0; j<(a.size() - i)/2; j++){
                    if(a[i + j] != a[a.size() - j - 1]){
                        temp = 0; break;
                    }
                }
                if(temp){
                    flag = 0; ans = i; break;
                }
            }
        }
        if(!flag){
            string temp = a.substr(0, ans);
            reverse(temp.begin(), temp.end());
            a += temp;
        }else{
            string temp = a.substr(0, a.size()-1);
            reverse(temp.begin(), temp.end());
            a += temp;
        }
        cout << a << endl;
    }
    return 0;
}