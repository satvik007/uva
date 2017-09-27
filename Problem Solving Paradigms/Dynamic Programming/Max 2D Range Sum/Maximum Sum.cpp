#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105;
const int inf = INT_MAX;
int n;

inline int submax(int num[maxn]) {
    int ans=num[1];
    int f=num[1];
    for (int i=2;i<=n;i++) {
        f=max(num[i]+f,num[i]);
        ans=max(ans,f);
    }
    return ans;
}

inline int submax2d(int num[maxn][maxn]) {
    int ret, ans = -inf;
    int a[maxn];
    for (int l=1;l<=n;l++) {
        memset(a,0,sizeof(a));
        for (int r=l;r<=n;r++) {
            for (int i=1;i<=n;i++) {
                a[i]+=num[r][i];
            }
            ret=submax(a);
            if (ret>ans) ans=ret;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    int a[maxn][maxn];
    int ans;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    memset(a,0,sizeof(a));
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    ans=submax2d(a);
    cout << ans << "\n";
    return 0;
}
