#include <iostream>
#include <vector>
using namespace std;

vector<int> rabinKarp(string text, string pat, int prime)
{
    vector<int> res;
    int n = text.size(), m = pat.size();
    int tHash = 0, pHash = 0, h = 1;
    int d = 256;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    for (int i = 0; i < m; i++)
    {
        tHash = (d * tHash + text[i]) % prime;
        pHash = (d * pHash + pat[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (tHash == pHash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pat[j])
                {
                    match = false;
                    cout << "False positive collision at index " << i << "\n";
                    break;
                }
            }
            if (match)
                res.push_back(i);
        }

        if (i < n - m)
        {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % prime;
            if (tHash < 0)
                tHash += prime;
        }
    }
    return res;
}

int main()
{
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pat = "Algorithms";

    vector<int> ans = rabinKarp(text, pat, 101);

    cout << "Positions: ";
    for (int x : ans)
        cout << x << " ";
}
