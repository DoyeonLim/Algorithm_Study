#include <iostream>

using namespace std;

int main(void)
{
    int n, a[4], ans = 0, k;
    
    cin >> n;
    if (n <= 99) ans = n;
    else
    {
        ans = 99;
        for (int t = 100; t <= n; t++)
        {
            k = t;
            for (int i = 0; i <= 1; i++)
            {
                a[i] = k % 10;
                k /= 10;
            }
            a[2] = k;
            int d;
            if (a[0] > a[1])
            {
                d = a[0] - a[1];
                if (a[1] - d == a[2]) ans++;
            }
            else
            {
                d = a[1] - a[0];
                if (a[2] == a[1] + d) ans++;
            }
        }
    }

    cout << ans;

    return 0;
}