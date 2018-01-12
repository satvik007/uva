#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <string> a(4);
unordered_map <int, int> map1;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

// I actually used a dice to get those values.
int newpos[24][4] = {{12, 4, 8, 16}, {5, 9, 17, 13}, {10, 18, 14, 6}, {19, 15, 7, 11},
                     {15, 22, 9, 0}, {23, 10, 1, 12}, {11, 2, 13, 20}, {3, 14, 21, 8},
                     {0, 7, 20, 17}, {4, 21, 18, 1}, {22, 19, 2, 5}, {16, 3, 6, 23},
                     {20, 5, 0, 19}, {6, 1, 16, 21}, {2, 17, 22, 7}, {18, 23, 4, 3},
                     {13, 0, 11, 22}, {1, 8, 23, 14}, {9, 20, 15, 2}, {21, 12, 3, 10},
                     {8, 6, 12, 18}, {7, 13, 19, 9}, {14, 16, 10, 4}, {17, 11, 5, 15}};

void solve(int mask){
    queue <int> q; q.push(mask);
    queue <int> dist; dist.push(0);
    map1[mask] = 1;
    int current=0, temp, tx, ty, x, y, pos, distance=0;
    while(!q.empty()){
        current = q.front(); q.pop();
        distance = dist.front(); dist.pop();
        if((current & ((1<<16)-1)) == 0) break;
        x = (current >> 22) & ((1<<4)-1);
        for(int k=0; k<4; k++){
            tx = x / 4 + dr[k];
            ty = x % 4 + dc[k];
            if(tx >= 0 && ty >= 0 && tx < 4 && ty < 4){
                pos = newpos[current >> 26][k];
                temp = current & ((1<<22)-1) & ~(1<<(4*tx + ty)) & ~(1<<(16+pos/4));
                temp |= (pos << 26);
                temp |= ((4*tx + ty) << 22);
                pos /= 4;
                if(current & (1<<(16+pos))) temp |= (1<<(4*tx + ty));
                if(current & (1<<(4*tx + ty))) temp |= (1<<(16 + pos));
                if(map1.find(temp) == map1.end()){
                    //cout << bitset <32> (temp) << " " << distance << endl;
                    map1[temp] = 1;
                    q.push(temp); dist.push(distance+1);
                }
            }
        }
    }
    if((current & ((1<<16)-1)) == 0){
        cout << distance << "\n";
    }else cout << "impossible\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        map1.clear();
        int mask = 0;
        for(int i=0; i<4; i++) cin >> a[i];
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(a[i][j] == 'X')  mask |= (1<<(4*i+j));
                else if(a[i][j] == 'D') mask |= ((4*i+j) << 22);
            }
        }
        solve(mask);
    }
    return 0;
}