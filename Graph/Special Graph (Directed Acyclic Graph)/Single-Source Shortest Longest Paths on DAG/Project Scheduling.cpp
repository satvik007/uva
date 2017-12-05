#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string line;
int a[30][30], tc, days[40];
char current, u;
int memo[40];

int solve(int current){
    if(memo[current] != -1) return memo[current];
    int ans = days[current];
    for(int i=0; i<30; i++){
        if(a[current][i] > 0){
            ans = max(ans, days[current] + solve(i));
        }
    }
    return memo[current] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc; cin.ignore();
    while(tc--){
        cin.ignore();
        memset(a, 0, sizeof a); memset(memo, -1, sizeof memo);
        memset(days, 0, sizeof days);
        while(cin.peek() != '\n' && cin.peek() != EOF){
            getline(cin, line); //cout << line << endl;
            stringstream cinn(line);
            cinn >> current; cinn >> days[current-'A'];
            while(cinn >> u) a[u-'A'][current-'A'] = 1;
        }
        int max1 = -1, current;
        for(int i=0; i<30; i++){
            if(days[i] != -1){
                current = solve(i);
                max1 = max(max1, current);
            }
        }
        cout << max1 << "\n";
        if(tc) cout << "\n";
    }
    return 0;
}