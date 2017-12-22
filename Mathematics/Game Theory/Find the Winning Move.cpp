#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

char last;

int check(const vector <string> &a){
    for(int i=0; i<4; i++){
        int res1 = 1, ans1 = 1, res2 = 1, ans2 = 1;
        for(int j=0; j<4; j++){
            if(a[i][j] != 'x') res1 = 0;
            if(a[j][i] != 'x') ans1 = 0;
            if(a[i][j] != 'o') res2 = 0;
            if(a[j][i] != 'o') ans2 = 0;
        }
        if(res1 || ans1) return 1;
        if(res2 || ans2) return -1;
    }
    if((a[0][0] == 'x') && (a[1][1] == 'x') && (a[2][2] == 'x') && (a[3][3] == 'x') ||
      (a[0][3] == 'x') && (a[1][2] == 'x') && (a[2][1] == 'x') && (a[3][0] == 'x')) return 1;
    else if((a[0][0] == 'o') && (a[1][1] == 'o') && (a[2][2] == 'o') && (a[3][3] == 'o') ||
       (a[0][3] == 'o') && (a[1][2] == 'o') && (a[2][1] == 'o') && (a[3][0] == 'o')) return -1;
    return 0;
}

ii solve(vector <string> a, int chance){
    int c = check(a);
    if(c == 1) return {0, 1};
    if(c == -1) return {0, -1};
    if(chance == 0){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(a[i][j] == '.'){
                    a[i][j] = 'x';
                    ii current = solve(a, 1);
                    if(current.second == 1) return {i*4+j, 1};
                    a[i][j] = '.';
                }
            }
        }
        return {-1, -1};
    }else{
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(a[i][j] == '.'){
                    a[i][j] = 'o';
                    ii current = solve(a, 0);
                    if(current.second != 1) return {i*4+j, -1};
                    a[i][j] = '.';
                }
            }
        }
        return {0, 1};
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector <string> a(4);
    while(cin >> last, last != '$'){
        for(int i=0; i<4; i++) cin >> a[i];
        ii ans = solve(a, 0);
        if(ans.second == -1) cout << "#####\n";
        else cout << "(" << (ans.first/4) << "," << (ans.first % 4) << ")\n";
    }
    return 0;
}