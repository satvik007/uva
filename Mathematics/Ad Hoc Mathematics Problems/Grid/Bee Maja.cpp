#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    int i, j, idx = 2;
    int px[100025], py[100025];
    px[1] = py[1] = 0;
    for(i = 1; idx < 100005; i++) {
        px[idx] = px[idx-1], py[idx] = py[idx-1]+1;
        idx++;
        for(j = 1; j < i && idx < 100005; j++, idx++)
            px[idx] = px[idx-1]-1, py[idx] = py[idx-1]+1;

        px[idx] = px[idx-1]-1, py[idx] = py[idx-1];
        idx++;
        for(j = 1; j < i && idx < 100005; j++, idx++)
            px[idx] = px[idx-1]-1, py[idx] = py[idx-1];

        px[idx] = px[idx-1], py[idx] = py[idx-1]-1;
        idx++;
        for(j = 1; j < i && idx < 100005; j++, idx++)
            px[idx] = px[idx-1], py[idx] = py[idx-1]-1;

        px[idx] = px[idx-1]+1, py[idx] = py[idx-1]-1;
        idx++;
        for(j = 1; j < i && idx < 100005; j++, idx++)
            px[idx] = px[idx-1]+1, py[idx] = py[idx-1]-1;

        px[idx] = px[idx-1]+1, py[idx] = py[idx-1];
        idx++;
        for(j = 1; j < i && idx < 100005; j++, idx++)
            px[idx] = px[idx-1]+1, py[idx] = py[idx-1];

        px[idx] = px[idx-1], py[idx] = py[idx-1]+1;
        idx++;
        for(j = 1; j < i && idx < 100005; j++, idx++)
            px[idx] = px[idx-1], py[idx] = py[idx-1]+1;
    }
    while(cin >> idx)
        cout << px[idx] << " " << py[idx] << "\n";
    return 0;
}