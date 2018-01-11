#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vi a;
bitset <32> bs;

unordered_map <int, int> map1;

void sieve(){
    bs.set(); bs[0]=bs[1]=0;
    for(int i=2; i<20; i++) if(bs[i]){
            for(int j=i*i; j<20; j += i) bs[j] = 0;
        }
}

inline int calc(const vi &b){
    int sum = 1, res = 0;
    for(int i=7; i>=0; i--){
        res += sum * abs(b[i]);
        sum *= 10;
    }
    return res;
}
inline void dance(vi &b, int x, int y, int z){
    if(!z){
        if(x + 1 == y) return;
        if(x < y){
            b.insert(b.begin() + y, b[x]);
            b.erase(b.begin() + x);
        }else{
            b.insert(b.begin() + y, b[x]);
            b.erase(b.begin()+x+1);
        }
    }else{
        if(x - 1 == y) return;
        if(x < y){
            b.insert(b.begin() + y + 1, b[x]);
            b.erase(b.begin() + x);
        }else{
            b.insert(b.begin() + y + 1, b[x]);
            b.erase(b.begin()+x+1);
        }
    }
}
void bfs(){
    queue <vi> q; q.push(a);
    queue <int> dist; dist.push(0);
    map1.clear(); map1[calc(a)] = 1;
    vi b, c;
    while(!dist.empty()){
        c = q.front(); q.pop();
        if(calc(c) == 12345678) break;
        int distance = dist.front(); dist.pop();
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(c[i]*c[j] < 0 && bs[abs(c[i])+abs(c[j])] && i != j){
                    for(int k=0; k<2; k++){
                        b = c;
                        dance(b, i, j, k);
                        if(map1.find(calc(b)) == map1.end()){
                            map1[calc(b)] = 1;
                            q.push(b);
                            dist.push(distance + 1);
                        }
                    }
                }
            }
        }
    }
    if(calc(c) == 12345678) cout << dist.front() << "\n";
    else cout << "-1\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sieve();
    int n; a.resize(8);
    int cas = 1;
    while(cin >> n, n){
        cout << "Case " << cas++ << ": ";
        a[0] = n;
        for(int i=1; i<8; i++) cin >> a[i];
        bfs();
    }
    return 0;
}