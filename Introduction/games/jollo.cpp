#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

vi status(5);

void func(int n, ostream &cout){
	int index = -1;
	for(int i=n+1; i<=52; i++){
		if(find(status.begin(), status.end(), i) == status.end()){
			index = i;
			break;
		}
	}
	cout << index << endl;
}
int main(){
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int a, b, c, x, y;
	while(cin >> a >> b >> c >> x >> y, a || b || c || x || y){
		status[0] = a;
		status[1] = b;
		status[2] = c;
		status[3] = x;
		status[4] = y;
		int a1 = a, b1 = b, c1 = c;
		a = min(min(a1, b1), c1);
		c = max(max(a1, b1), c1);
		b = a1 + b1 + c1 - a - c;
		if(x>y) swap(x, y);
		int counter1 = 0;
		int counter2 = 0;
		if(x>a) counter1++;
		if(x>b) counter1++;
		if(x>c) counter1++;
		if(y>a) counter2++;
		if(y>b) counter2++;
		if(y>c) counter2++;
		if(counter1 <= 1 && counter2 != 3) cout << "-1" << endl;
		else if(counter1 <=1){
			if(c == 51) cout << "-1" << endl;
			else func(c, cout);
		}
		else if(counter1 == 3) func(0, cout);
		else{
			func(b, cout);
		}
		
	}
}