#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * permutaions nhi karna 
 * paring friends 
 * like 123
 * 1-2-3
 * 12-3
 * 1-23
 * 13-2
 */

void solve(int n, int m, vector<bool> used, string asf, int &count)
{

    if (m > n)
    {
        cout << count << "." << asf << endl;
        count++;
        return;
    }
    if (used[m])
    {
        solve(n, m + 1, used, asf, count);
    }

    else
    {
        used[m] = true;
        solve(n, m + 1, used, asf + "(" + to_string(m) + ") ", count);
        for (int i = m + 1; i <= n; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                solve(n, m + 1, used, asf + "(" + to_string(m) + "," + to_string(i) + ") ", count);
                used[i] = false;
            }
        }
        used[m] = false;
    }
}

int main()
{
    int n;
    cin >> n;
    int count = 1;
    vector<bool> used(n + 1, false);
    solve(n, 1, used, "", count);
}