#include <cstdio>
using namespace std;
int main()
{
    int N, num;
    while (scanf("%d", &N) && N) {
        int Max = 0;
        int MSS = -1;
        while (N--) {
            scanf("%d", &num);
            if (MSS < 0) MSS = num;
            else MSS += num;

            if (MSS > Max) Max = MSS;
        }
        if (Max > 0) printf("The maximum winning streak is %d.\n", Max);
        else puts("Losing streak.");
    }
}
