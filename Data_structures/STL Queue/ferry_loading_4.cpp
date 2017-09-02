#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        n*=100;
        queue <int> left;
        queue <int> right;
        for(int i=0; i<m; ++i){
            int val;
            string temp;
            cin >> val >> temp;
            if(temp == "left") left.push(val);
            else right.push(val);
        }
        int status = -1;
        int curr = 0;
        while(!left.empty() || !right.empty()){
        	//cout << curr << endl;
            int size = 0;
            if(status == -1){
                while(!left.empty()){
                	if(size + left.front() > n) break;
                    size += left.front();
                    left.pop();
                }
                if(!left.empty() || !right.empty()) {
                	status = 1; curr++;
				}
            }else {
                while(!right.empty()){
                	if(size + right.front() > n) break;
                    size += right.front();
                    right.pop();
                }
                if(!left.empty() || !right.empty()) {
                	status = -1; curr++;
				}
            }
        }
        cout << curr+1 << "\n";
    }
    return 0;
}
