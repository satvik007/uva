#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define mod 1000000007

int R[1024], state[40];
struct mtx{
    ll v[35][35];
    mtx(){
        memset(v, 0, sizeof v);
    }
};

mtx M;

void dfs(int idx, int ai, int bi, int dep){
    if(dep == 4){
        M.v[R[ai]][R[bi]]++;
        return;
    }
    for(; idx<7; idx++){
        if((ai >> idx) & 1){
            if(idx - 1 >= 0 && ((bi&(1<<(idx-1)))) == 0)
                dfs(idx+1, ai, bi|(1<<(idx-1)), dep+1);
            if(idx + 1 < 7 && ((bi & (1<<(idx+1)))) == 0)
                dfs(idx+1, ai, bi|(1<<(idx+1)), dep+1);
            break;
        }
    }
}

void buildMatrix(){
    int i, j, k;
    int idx = 0, cnt;
    for(i=0; i<(1<<7); i++){
        for(j=0, cnt=0; j<7; j++)
            cnt += (i>>j)&1;
        if(cnt == 4)
            state[idx] = i, R[i] = idx++;
    }
    for(i=0; i<idx; i++)
        dfs(0, state[i], 0, 0);
}

mtx multiply(mtx &x, mtx &y){
    mtx z;
    int i, j, k;
    for(k=0; k<35; k++){
        for(i=0; i<35; i++){
            if(x.v[i][k] == 0)
                continue;
            for(j=0; j<35; j++){
                z.v[i][j] += (x.v[i][k]*y.v[k][j]) % mod;
                if(z.v[i][j] >= mod)
                    z.v[i][j] %= mod;
            }
        }
    }
    return z;
}

mtx calcPow(mtx x, int y){
    mtx ret;
    int i;
    for(i=0; i<35; i++)
        ret.v[i][i] = 1;
    while(y){
        if(y & 1)
            ret = multiply(ret, x);
        x = multiply(x, x);
        y /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    buildMatrix();
    int tc;
    int n, i, j, k;
    cin >> tc;
    while(tc--){
        cin >> n;
        int s = 0;
        for(i=0; i<7; i++){
            cin >> j;
            if(j) s |= (1<<i);
        }
        ll A[35] = {}, B[35] = {};
        A[R[s]] = 1;
        mtx MM = calcPow(M, n-1);
        ll ret = 0;
        for(i=0; i<35; i++)
            for(j=0; j<35; j++)
                for(k=0; k<1; k++){
                    B[i] += MM.v[i][j] * A[j];
                    B[i] %= mod;
                }
        for(i=0; i<35; i++)
            ret = (ret + B[i]) % mod;
        cout << ret << "\n";
    }
    return 0;
}
