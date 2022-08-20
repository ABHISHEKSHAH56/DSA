#include <bits/stdc++.h>
using namespace std;

/**
 * @brief we have given list of word and we have to select set from list 
 * of words such that aplhabest used the frequncy given and also who give the maximum score 
 * 
 * @param st 
 * @param freq  
 * @param score 
 * @param idx 
 * @return *** int 
 */

int solution(vector<string> st, map<char, int> freq, vector<int> score, int idx)
{
    if (idx == st.size())
        return 0;

    int noscore = solution(st, freq, score, idx + 1); // not include
    int sidxthword = 0;
    string word = st[idx];
    bool flag = true;
    for (int i = 0; i < word.size(); i++)
    {
        if (freq[word[i]] == 0)
        {
            flag = false;
        }
        freq[word[i]]--;
        sidxthword += score[word[i] - 'a'];
    }

    int syes = 0;
    if (flag)
    {
        syes = sidxthword + solution(st, freq, score, idx + 1);
    }
    for (int i = 0; i < word.size(); i++)
    {
        freq[word[i]]++;
    }

    return max(noscore, syes);
}

int main()
{

    int n;
    cin >> n;
    vector<string> st(n);
    for (int i = 0; i < n; i++)
    {
        cin >> st[i];
    }
    map<char, int> freq;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        freq[c]++;
    }
    vector<int> score(26);
    for (int i = 0; i < 26; i++)
    {
        cin >> score[i];
    }

    cout << solution(st, freq, score, 0) << endl;
}