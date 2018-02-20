#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n , m , ans;
vector <string> a;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void floodfill1(int r , int c , char ch1, char ch2){
    if( r<0 || r>=n || c>=m || c<0) return ;
    if(a[r][c] != ch1)  return ;
    a[r][c] = ch2;
    for(int k = 0 ; k < 4 ; k++)
        floodfill1(r + dr[k] , c + dc[k] , ch1 , ch2);
}

int floodfill(int r , int c , char ch1, char ch2 ){
    if( r<0 || r>=n || c>=m || c<0) return 0;
    if(a[r][c] == '.')  return 0;
    if(a[r][c] == 'X'){
        floodfill1(r, c, 'X', '*');
        ans++;
    }
    a[r][c] = ch2;
    for(int k = 0 ; k < 4 ; k++)
        floodfill(r + dr[k] , c + dc[k] , ch1 , ch2);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int count = 1;
    while(cin>>m>>n , n && m){
        a.resize(n);
        vi answer;
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = 0;
                if(a[i][j] == '*' ) {
                    floodfill(i, j, '*', '.');
                    answer.push_back(ans);
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = 0;
                if(a[i][j] == 'X'){
                    floodfill1(i, j, 'X', '.');
                    answer.push_back(1);
                }
            }
        }
        sort(answer.begin() , answer.end());
        cout<<"Throw "<<count++<<"\n";
        for(int i = 0 ; i < answer.size() - 1 ; i++)
            cout << answer[i] <<" ";
        cout << answer[answer.size() - 1];
        cout << "\n\n";
    }
    return 0;
}