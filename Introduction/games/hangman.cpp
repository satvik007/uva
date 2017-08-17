#include <bits/stdc++.h>
using namespace std;

int main(){
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    int n;
    while(cin >> n, n+1){
        string a, b;
        cin >> a >> b;
        cout << "Round " << n << endl;
        vector <int> status(26);
        for(int i=0; i<a.size(); i++) status[a[i] - 'a'] = 1;
        int required = 0;
        for(int i=0; i<26; i++) if(status[i] == 1) required++;
        int wrong = 0;
        int correct = 0;
        int flag = 0;
        for(int i=0; i<b.size(); i++){
            if(status[b[i] - 'a'] == 0){
                wrong++;
                status[b[i]-'a'] = 2;
            }
            else if(status[b[i]-'a'] == 1){
                correct++;
                status[b[i]-'a'] = 2;
            }
            if(correct >= required){
                flag = 1;
                break;
            }
            if(wrong>=7) break;
        }
        if(flag == 1) cout << "You win." << endl;
        else if(wrong >= 7) cout << "You lose." << endl;
        else cout << "You chickened out." << endl;
    }
    return 0;
}
