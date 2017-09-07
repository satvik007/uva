#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    int n;
    string line;
    int temp;
    while(t--){
        cin >> n;
        cin.ignore();
        vector <vi> a(n);
        for(int j=0; j<n; j++){
            getline(cin, line);
            //cout << line << endl;
            stringstream new1(line);
            while(new1 >> temp) a[j].push_back(temp);
        }
        int min1 = INT_MAX;
        for(int i=0; i<n; i++) if(a[i].size()<min1) min1 = a[i].size();
        //cout << min1 << endl;
        int k = 0;
        for(int i=0; i<n; i++) if(a[i].size() == min1){
        	if(k != 0) cout << " ";
        	cout << (i+1);
        	k++;
		}
		cout << "\n";
    }
}
