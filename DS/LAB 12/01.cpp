#include <iostream>
#include <vector>
using namespace std;

vector<int> bruteForce(string text, string pat, int &comparisons)
{
    vector<int> res;
    int n = text.size(), m = pat.size();
    comparisons = 0;

    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pat[j])
        {
            comparisons++;
            j++;
        }
        if (j < m)
            comparisons++; // failed comparison
        if (j == m)
            res.push_back(i);
    }
    return res;
}

int main()
{
    string text = "the quick brown fox jumps over the lazy dog";
    string pat = "the";
    int cmp = 0;

    vector<int> ans = bruteForce(text, pat, cmp);

    cout << "Positions: ";
    for (int x : ans)
        cout << x << " ";
    cout << "\nComparisons: " << cmp;
}
