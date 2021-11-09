#include <bits/stdc++.h>

using namespace std;

string solve(string &S, int K)
{
    vector<int> correct, wrong;
    int ans = 0;
    bool possible = true;

    for (int i = 0; i < S.size(); i++)
    {
        char c = S[i];
        if (c == '-')
        {
            if ((i > S.size() - K ))
            {
                possible = false;
                break;
            }
            else
            {
                for (int j = 0; j < K; j++)
                {
                    S[i + j] = (S[i + j] == '+') ? '-' : '+';
                }
                ans++;
            }
        }
    }

    if (possible)
    {
        return to_string(ans);
    }
    return "IMPOSSIBLE";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        string S;
        int K;
        cin >> S >> K;

        string ans = solve(S, K);

        cout << "Case #" << numTest << ": " << ans << endl;
    }

    return 0;
}