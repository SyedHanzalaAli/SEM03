#include <iostream>
#include <vector>
using namespace std;

vector<int> buildLPS(string pat)
{
    int m = pat.size();
    vector<int> lps(m);
    int len = 0;

    for (int i = 1; i < m;)
    {
        if (pat[i] == pat[len])
        {
            lps[i++] = ++len;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> KMP(string text, string pat)
{
    vector<int> ans;
    vector<int> lps = buildLPS(pat);
    int i = 0, j = 0;

    while (i < text.size())
    {
        if (text[i] == pat[j])
            i++, j++;
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == pat.size())
        {
            ans.push_back(i - j);
            j = lps[j - 1];
        }
    }
    return ans;
}

int main()
{
    string t = "ababababc";
    string p = "abab";

    vector<int> ans = KMP(t, p);

    cout << "LPS: ";
    vector<int> lps = buildLPS(p);
    for (int x : lps)
        cout << x << " ";

    cout << "\nPositions: ";
    for (int x : ans)
        cout << x << " ";
}
