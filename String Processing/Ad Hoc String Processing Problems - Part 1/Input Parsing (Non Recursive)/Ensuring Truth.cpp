#include <bits/stdc++.h>
#define iter(a,b,c,d) for(a = b; a < c; a+=d)
#define ited(a,b,c,d) for(a = b; a > c; a-=d)
#define li long int
#define uli unsigned li
#define ll long li
#define ull unsigned ll
#define si(a) scanf("%d",&a)
#define sli(a) scanf("%ld",&a)
#define sll(a) scanf("%lld",&a)
#define slu(a) scanf("%llu",&a)
#define sf(a) scanf("%f",&a)
#define slf(a) scanf("%lf",&a)
#define PI 3.1415926
using namespace std;
int main()
{
    /*freopen("1in.txt", "r", stdin);
    freopen("1out.txt", "w", stdout);*/
    int t;si(t);
    cin.ignore(100,'\n');
    char c;
    int noL;
    int mask = 0,notmask = 0;
    bool isS;
    while(t--)
    {
        isS = false;
        while(c = getchar(), c!='\n')
        {
            if(c == '(')
            {
                mask = notmask = 0;
            }
            else if(c == ')')
            {
                if((mask & notmask) == 0)
                    isS = true;
            }
            else if(c == '|' || c == '&')
            {

            }
            else if(c == '~')
            {
                c = getchar();
                notmask |= 1 << (c-'a');
            }
            else
            {
                mask |= 1 << (c-'a');
            }
        }
        if(isS)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}