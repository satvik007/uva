#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int a[12], b[12];
vector <string> res(10);

int dr[] = {-1, 0, 1, 0, 0};
int dc[] = {0, 1, 0, -1, 0};

int process(int m) {
    for (int i = 0; i < 10; i++) a[i] = b[i];
    int tx, ty;
    int counter = 0;
    for (int j = 0; j < 10; j++) {
        if (m & (1 << j)) {
            counter++;
            for (int k = 0; k < 5; k++) {
                tx = dr[k];
                ty = j + dc[k];
                if (tx >= 0 && ty >= 0 && tx < 10 && ty < 10) {
                    a[tx] ^= (1 << ty);
                }
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i] & (1 << j)) {
                counter++;
                for (int k = 0; k < 5; k++) {
                    tx = i + 1 + dr[k];
                    ty = j + dc[k];
                    if (tx >= 0 && ty >= 0 && tx < 10 && ty < 10) {
                        a[tx] ^= (1 << ty);
                    }
                }
            }
        }
    }
    if (counter > 100 || a[9]) return 1000000;
    return counter;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string name;
    bool flag = true;
    while(cin >> name and name != "end"){
        for(int i=0; i<10; i++){
            cin >> res[i];
        } cin.ignore();
        //for(int i=0; i<10; i++) b[i] = (1<<10)-1;
        memset(b, 0, sizeof b);
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(res[i][j] == 'O') b[i] |= (1 << j);
            }
        }
        int min1 = 1000000;
        for(int i=0; i<(1<<10); i++){
            min1 = min(min1, process(i));
        }
        if(min1 == 1000000) cout << name << " " << -1 << "\n";
        else cout << name << " " << min1 << "\n";
    }
    return 0;
}