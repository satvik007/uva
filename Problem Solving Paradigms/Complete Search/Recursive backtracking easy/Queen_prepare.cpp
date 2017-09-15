#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <ll> ans;
ll one = 1;

string convertToBitString(long long value)
{
    string str(64, '0');

    for(int i = 0; i < 64; i++)
    {
        if( (1ll << i) & value)
            str[63-i] = '1';
    }

    return str;
 }

void solve(int row, ll mask){
	if(row == 8){
		bool status = true;
		//cout << bitset<64>(mask) << endl;
		for(int i=0; i<64; i++){
			if(mask & (one<<i)){
				for(int j=i+1; j<64; j++){
					if(mask & (one<<j)){
						if(i/8 == j/8) status = false;
						if(i%8 == j%8) status = false;
						if(i/8-i%8 == j/8-j%8) status = false;
						if(i/8+i%8 == j/8+j%8) status = false;
					}
				}
			}
		}
		if(status){
			ans.push_back(mask);
		}
		return;
	}
	for(int i=0; i<8; i++){
		bool status = true;
		for(int j=0; j<row; j++){
			if(mask & (one<<(j*8+i))) status = false;
		}
		if(status) solve(row+1, mask | one << (row*8+i));
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve(0, 0);
    vi a(8);
    for(auto el:ans){
    	for(int j=0; j<64; j++){
    		if(el & (one << j)) a[j%8] = j/8+1;
    	}
    	for(auto e: a) cout << e;
    }
    return 0;
}
