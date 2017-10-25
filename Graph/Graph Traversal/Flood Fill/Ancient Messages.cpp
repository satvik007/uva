#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
vector <string> a, b;
int counter;

void decode(int u, int v, string line){
    for(int i=0; i<4; i++){
        a[u][v*4+i] = line[i];
    }
}

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void floodfill1(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= 4*m) return;
    if(a[r][c] != '0') return;
    a[r][c] = '2';
    for(int i=0; i<4; i++) floodfill1(r+dr[i], c+dc[i]);
}

void flood(int r, int c){
    if(r<0 || r>=n || c<0 || c>=4*m) return;
    if(a[r][c] == '2') return;
    if(a[r][c] == '0'){
        counter++;
        floodfill1(r, c);
        return;
    }
    a[r][c] = '2';
    for(int i=0; i<4; i++) flood(r+dr[i], c+dc[i]);
}

void convert(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            switch(b[i][j]) {
                case '0':decode(i, j, "0000");break;
                case '1':decode(i, j, "0001");break;
                case '2':decode(i, j, "0010");break;
                case '3':decode(i, j, "0011");break;
                case '4':decode(i, j, "0100");break;
                case '5':decode(i, j, "0101");break;
                case '6':decode(i, j, "0110");break;
                case '7':decode(i, j, "0111");break;
                case '8':decode(i, j, "1000");break;
                case '9':decode(i, j, "1001");break;
                case 'a':decode(i, j, "1010");break;
                case 'b':decode(i, j, "1011");break;
                case 'c':decode(i, j, "1100");break;
                case 'd':decode(i, j, "1101");break;
                case 'e':decode(i, j, "1110");break;
                case 'f':decode(i, j, "1111");break;
                default:cout << "hello\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> m, n){
        a.clear(); a.resize(n+3);
        b.clear(); b.resize(n+3);
        for(int i=0; i<n; i++){
            cin >> b[i];
            a[i].resize(4*m+5);
        }
        convert();
        for(int i=0; i<n; i++){
            floodfill1(i, 0);
            floodfill1(i, 4*m-1);
        }
        for(int i=0; i<4*m; i++){
            floodfill1(0, i);
            floodfill1(n-1, i);
        }
        string ans;
        cout << "Case " << cas << ": ";
        for(int i=0; i<4*m; i++){
            for(int j=0; j<n; j++){
                if(a[j][i] == '1'){
                    counter = 0;
                    flood(j, i);
                    switch(counter){
                        case 0: ans += "W"; break;
                        case 1: ans += "A"; break;
                        case 2: ans +=  "K"; break;
                        case 3: ans += "J"; break;
                        case 4: ans += "S"; break;
                        case 5: ans += "D"; break;
                        default: cout << "This shouldn't happen.\n";
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans << "\n";
        cas++;
    }
    return 0;
}