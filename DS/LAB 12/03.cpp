#include <iostream>
#include <vector>
using namespace std;

void buildBadChar(string pat, vector<int> &bad)
{
    for (int i = 0; i < 256; i++)
        bad[i] = -1;
    for (int i = 0; i < pat.size(); i++)
        bad[(unsigned char)pat[i]] = i;
}

void preprocessGS(string pat, vector<int> &suffix, vector<bool> &prefix)
{
    int m = pat.size();
    for (int i = 0; i < m; i++)
        suffix[i] = -1, prefix[i] = false;

    for (int i = 0; i < m - 1; i++)
    {
        int j = i, k = 0;
        while (j >= 0 && pat[j] == pat[m - 1 - k])
            j--, k++;
        if (k > 0)
            suffix[k] = j + 1;
        if (j == -1)
            prefix[k] = true;
    }
}

int moveByGS(int j, int m, vector<int> &suffix, vector<bool> &prefix)
{
    int k = m - 1 - j;
    if (suffix[k] != -1)
        return j - suffix[k] + 1;
    for (int r = j + 2; r <= m - 1; r++)
        if (prefix[m - r])
            return r;
    return m;
}

vector<int> boyerMoore(string text, string pat)
{
    vector<int> ans;
    int n = text.size(), m = pat.size();

    vector<int> bad(256);
    buildBadChar(pat, bad);

    vector<int> suffix(m);
    vector<bool> prefix(m);
    preprocessGS(pat, suffix, prefix);

    int i = 0;
    while (i <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && text[i + j] == pat[j])
            j--;

        if (j < 0)
        {
            ans.push_back(i);
            i++;
        }
        else
        {
            int bc = j - bad[(unsigned char)text[i + j]];
            int gs = 0;
            if (j < m - 1)
                gs = moveByGS(j, m, suffix, prefix);
            i += max(bc, gs);
        }
    }
    return ans;
}

int main()
{
    string dna = "ACGTACGTGACG";
    string pat = "ACG";

    vector<int> ans = boyerMoore(dna, pat);
    for (int x : ans)
        cout << x << " ";
}
