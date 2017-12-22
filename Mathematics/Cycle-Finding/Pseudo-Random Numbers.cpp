#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int Z, I, M, L;

int f(int n){
    return ((Z*n + I) % M);
}

ii floydCycleFinding(int x0) {
    int tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare) {
        tortoise = f(tortoise); hare = f(f(hare));
    }
    int mu = 0; hare = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise); hare = f(hare); mu++;
    }
    int lambda = 1; hare = f(tortoise);
    while (tortoise != hare) {
        hare = f(hare); lambda++;
    }
    return ii(mu, lambda);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> Z >> I >> M >> L, Z || I || M || L){
        ii ans = floydCycleFinding(L);
        cout << "Case " << cas++ << ": " << ans.second << "\n";
    }
    return 0;
}