#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 32;
const ll INF=(1LL<<62);
int A,B,C;

inline ll submax(ll num[maxn]) {
    ll ans=num[1];
    ll f=num[1];
    for (int i=2;i<=C;i++) {
        f=max(num[i]+f,num[i]);
        ans=max(ans,f);
    }
    return ans;
}

inline ll submax2d(ll num[maxn][maxn]) {
    ll ret,ans=-INF;
    ll a[maxn];
    for (int l=1;l<=B;l++) {
        memset(a,0,sizeof(a));
        for (int r=l;r<=B;r++) {
            for (int i=1;i<=C;i++) {
                a[i]+=num[r][i];
            }
            ret=submax(a);
            if (ret>ans) ans=ret;
        }
    }
    return ans;
}

inline ll submax3d(ll num[maxn][maxn][maxn]) {
    ll ret,ans=-INF;
    ll a[maxn][maxn];
    for (int l=1;l<=A;l++) {
        memset(a,0,sizeof(a));
        for (int r=l;r<=A;r++) {
            for (int i=1;i<=B;i++) {
                for (int j=1;j<=C;j++) {
                    a[i][j]+=num[r][i][j];
                }
            }
            ret=submax2d(a);
            if (ret>ans) ans=ret;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    ll a[maxn][maxn][maxn];
    ll ans;
    //freopen("abc.in","r",stdin);
    //freopen("abc.out","w",stdout);
    cin >> T;
    while (T--)
    {
        memset(a,0,sizeof(a));
        cin >> A >> B >> C;
        for (int i=1;i<=A;i++) {
            for (int j=1;j<=B;j++) {
                for (int k=1;k<=C;k++) {
                    cin >> a[i][j][k];
                }
            }
        }
        ans=submax3d(a);
        cout << ans << "\n";
        if (T) cout << "\n";
    }
    return 0;
}
