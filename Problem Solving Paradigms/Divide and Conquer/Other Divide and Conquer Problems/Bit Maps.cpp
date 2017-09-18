#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

#define left(p) (p<<1)
#define right(p) (p<<1 | 1)
int n, m, k, flag, count1, counter;
char type;
string b;
vector <string> a;

void dtob(int up, int down, int left, int right){
    if(up > down || left > right || k >= b.size()) return;
    if(b[k] == 'D'){
        k++;
        dtob(up, up+(down-up)/2, left, left+(right-left)/2);
        dtob(up, up+(down-up)/2, left+(right-left)/2+1, right);
        dtob(up+(down-up)/2+1, down, left, left+(right-left)/2);
        dtob(up+(down-up)/2+1, down, left+(right-left)/2+1, right);
    }
    else {
        for(int i=up; i<= down; i++){
            for(int j=left; j<= right; j++){
                a[i][j] = b[k];
            }
        }
        k++;
    }
}

int btod(int p1, int p2, int up, int down, int left, int right){
    if(up > down || left > right) return -1;
    if(up == down && left == right){
        a[p1][p2] = b[m*up + left];
        //cout << p1 << " " << p2 << " " << a[p1][p2] << endl;
        return (int)a[p1][p2];
    }
    else{
        int lup = btod(left(p1), left(p2), up, up+(down-up)/2, left, left+(right-left)/2);
        int rup = btod(left(p1), right(p2),up, up+(down-up)/2, left+(right-left)/2+1, right);
        int ldn = btod(right(p1), left(p2),up+(down-up)/2+1, down, left, left+(right-left)/2);
        int rdn = btod(right(p1), right(p2),up+(down-up)/2+1, down, left+(right-left)/2+1, right);
        if(rup == -1){
            if(lup == ldn){
                a[p1][p2] = (char)lup;
                return lup;
            }
            else{
                a[p1][p2] = (char)'D';
                return 'D';
            }
        }
        else if(ldn == -1){
            if(lup == rup){
                a[p1][p2] = (char)lup;
                return lup;
            }
            else{
                a[p1][p2] = (char)'D';
                return 'D';
            }
        }
        else if(lup == 'D' || rup == 'D' || ldn == 'D' || rdn == 'D'){
            a[p1][p2] = (char)'D';
            return 'D';
        }
        else if(lup == rup && lup == ldn && lup == rdn){
            a[p1][p2] = (char)lup;
            return lup;
        }
        else{
            a[p1][p2] = (char)'D';
            return 'D';
        }
    }
}

void dfs(int p1, int p2, int up, int down, int left, int right){
    if(up > down || left > right) return ;
    if(up == down && left == right){
        if(counter == 0) cout << "\n";
        cout << a[p1][p2];
        counter++;
        if(counter == 50) counter = 0;
    }
    else{
        if(a[p1][p2] == 'D'){
            if(counter == 0) cout << "\n";
            cout << 'D';
            counter++;
            if(counter == 50) counter = 0;

            dfs(left(p1), left(p2), up, up+(down-up)/2, left, left+(right-left)/2);
            dfs(left(p1), right(p2),up, up+(down-up)/2, left+(right-left)/2+1, right);
            dfs(right(p1), left(p2),up+(down-up)/2+1, down, left, left+(right-left)/2);
            dfs(right(p1), right(p2),up+(down-up)/2+1, down, left+(right-left)/2+1, right);
        }
        else{
            if(counter == 0) cout << "\n";
            cout << a[p1][p2];
            counter++;
            if(counter == 50) counter = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    a.resize(805);
    for(int i=0; i<805; i++) a[i].resize(805);
    string line;
    while(cin >> type){
        if(type == '#') break;
        cin >> n >> m;
        cout << (type == 'D' ? 'B' : 'D');
        cout << setw(4) << n << setw(4) << m;
        k = 0;
        counter = 0;
        if(type == 'D'){
            cin >> b;
            dtob(0, n-1, 0, m-1);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(counter == 0) cout << "\n";
                    cout << a[i][j];
                    counter++;
                    if(counter == 50) counter = 0;
                }
            }
        }

        else{
            cin.ignore();
            b.clear();
            count1 = n*m;
            while(b.size() != count1){
                cin >> line;
                b += line;
            }
            btod(1, 1, 0, n-1, 0, m-1);
            dfs(1, 1, 0, n-1, 0, m-1);
        }
        cout << "\n";
        cin.ignore();
    }
    return 0;
}
