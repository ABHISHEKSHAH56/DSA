#include <bits/stdc++.h>
using namespace std;

/**
 *? Abbreviation Using Backtracking
1. You are given a word.
2. You have to generate all abbrevations of that word.
//? Input
==> pep
//? output
pep
pe1
p1p
p2
1ep
1e1
2p
3
*/

void print(string s, string asf, int pos, int count)
{

    if (pos == s.length())
    {
        if (count == 0)
        {
            cout << asf << endl;
        }
        else
        {
            cout << asf + to_string(count) << endl;
        }
        return;
    }
    if (count > 0)
    {
        print(s, asf + to_string(count) + s[pos], pos + 1, 0);
    }
    else
    {
        print(s, asf + s[pos], pos + 1, 0);
    }
    print(s, asf, pos + 1, count + 1);
}

int main()
{

    string x;
    cin >> x;
    print(x, "", 0, 0);
}