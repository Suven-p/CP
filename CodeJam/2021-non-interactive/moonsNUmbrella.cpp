#include <bits/stdc++.h>

using namespace std;

int getValue(const string &S, int X, int Y)
{
    if (S == "CCC")
    {
        return 0;
    }
    if (S == "CCJ")
    {
        return X;
    }
    if (S == "CJC")
    {
        return X + Y;
    }
    if (S == "CJJ")
    {
        return X;
    }
    if (S == "JCC")
    {
        return Y;
    }
    if (S == "JCJ")
    {
        return X + Y;
    }
    if (S == "JJC")
    {
        return Y;
    }
    if (S == "JJJ")
    {
        return 0;
    }
    return 0;
}

int getOptimal(string &S, int i, int X, int Y)
{
    auto prev = S[i - 1];
    auto next = S[i + 1];
    if (prev != '?' && next != '?')
    {
        string str1 = {prev, 'C', next};
        string str2 = {prev, 'J', next};
        int val1 = getValue(str1, X, Y), val2 = getValue(str2, X, Y);
        if (val1 < val2)
        {
            S[i] = 'C';
            return val1;
        }
        else
        {
            S[i] = 'J';
            return val2;
        }
    }
    else if (prev == '?' && next != '?')
    {
        S[i] = next;
    }
    // else if (prev != '?' && next == '?')
    // {
    //     S[i] = prev;
    // }
    else if (next == '?')
    {
        getOptimal(S, i + 1, X, Y);
        return getOptimal(S, i, X, Y);
    }
    string temp = {prev, S[i], next};
    return getValue(temp, X, Y);
}

int main()
{
    int T;
    cin >> T;
    for (int nT = 0; nT < T; nT++)
    {
        int X, Y;
        int result = 0;
        string S;
        cin >> X >> Y >> S;
        bool isAllEmpty = true;

        if (S[0] == '?')
        {
            for (int i = 0; i < S.size(); i++)
            {
                if (S[i] == '?')
                {
                    continue;
                }
                else
                {
                    isAllEmpty = false;
                    for (int j = i - 1; j >= 0; j--)
                    {
                        S[j] = S[i];
                    }
                    break;
                }
            }
        }
        else
        {
            isAllEmpty = false;
        }

        if (!isAllEmpty)
        {

            if (S[S.size() - 1] == '?')
            {
                for (int i = S.size() - 1; i >= 0; i--)
                {
                    if (S[i] == '?')
                    {
                        continue;
                    }
                    else
                    {
                        for (int j = i + 1; j < S.size(); j++)
                        {
                            S[j] = S[i];
                        }
                        break;
                    }
                }
            }
            for (int i = 0; i < S.size() - 1; i++)
            {
                char cur = S[i];
                char next = S[i + 1];
                if (cur == 'C' && next == 'J')
                {
                    result += X;
                }
                else if (cur == 'J' && next == 'C')
                {
                    result += Y;
                }
                else if (cur == '?')
                {
                    getOptimal(S, i, X, Y);
                    i--;
                    i--;
                }
            }
            cerr << "Optimal string: " << S << endl;
        }
        cout << "Case #" << nT + 1 << ": " << result << endl;
    }
}
