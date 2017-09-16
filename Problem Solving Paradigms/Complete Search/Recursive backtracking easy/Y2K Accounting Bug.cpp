#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int s, d, r;
    while (cin >> s >> d) {
        if (d > 4*s) {
            r = 10*s - 2*d;
        } else if (2*d > 3*s) {
            r = 8*s - 4*d;
        } else if (3*d > 2*s) {
            r = 6*s - 6*d;
        } else if (4*d > s) {
            r = 3*s - 9*d;
        } else {
            r = -12 * d;
        }
        if (r >= 0) {
            cout << r << "\n";
        } else {
            cout << "Deficit\n";
        }
    }
    return 0;
}
