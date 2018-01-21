#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9

int N;
bool visited[35][35][6000], used[6000];
int num[40], sig[40];

void rec(int idx, int open, int val) {
    if (visited[idx][open][val+3000])
        return;
    visited[idx][open][val+3000] = true;
    if (idx == N){
        used[val+3000] = true; return;
    }

    int nval = val + num[idx] * sig[idx] * ((open % 2 == 0) ? 1 : -1);
    if (sig[idx] == -1)
        rec(idx + 1, open + 1, nval);
    if (open > 0)
        rec(idx + 1, open - 1, nval); // if we already have some open brackets
    rec(idx + 1, open, nval);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string line;
    while(cin.peek() != EOF){
        getline(cin, line);
        stringstream take(line);
        int i=0; sig[0] = 1;
        char last;
        while(take >> num[i]){
            i++;
            if(!(take >> last)) break;
            if(last == '+') sig[i] = 1;
            else if(last == '-') sig[i] = -1;
            else break;
        }
        N = i;
        memset(visited, false, sizeof visited);
        memset(used, false, sizeof used);
        rec(0, 0, 0);
        int cnt = 0;
        for(int j=0; j<6000; j++) if(used[j]) cnt++;
        cout << cnt << "\n";
    }
    return 0;
}