#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#pragma GCC optimize "trapv"
#define TEST
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define mp make_pair
#define FOR(i, j, k, inc) for (int i = j; i < k; i += inc)
#define REP(i, n) for (int i = 0; i < n; i++)
#ifdef TEST
#define debug(x...) cerr << #x << x << endl;
#else
#define debug(x...)
#endif

int N;
string input;
map<char, vi> freq;

vector<string> possible_1, possible_2, possible_3;
void pre()
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        possible_1.push_back(string(1, c));
        for (char d = 'a'; d <= 'z'; d++)
        {
            string s1 = string(1, c) + d;
            possible_2.push_back(s1);
            for (char e = 'a'; e <= 'z'; e++)
            {
                string s2 = s1 + e;
                possible_3.push_back(s2);
            }
        }
    }
}

int main()
{
#ifdef TEST
    freopen("/media/nevus/data/CP/input.in", "r", stdin);
    freopen("/media/nevus/data/CP/output.out", "w", stdout);
    freopen("/media/nevus/data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        freq.clear();
        cin >> N;
        cin >> input;

        set<string> len1, len2, len3;
        for (int i = 0; i < N; i++)
        {
            freq[input[i]].push_back(i);
            len1.insert(string(1, input[i]));
        }

        bool found = false;
        string ans;
        for (auto c : possible_1)
        {
            if (len1.find(c) == len1.end())
            {
                found = true;
                ans = c;
                break;
            }
        }
        if (found)
        {
            cout << ans << endl;
            continue;
        }

        for (auto c : freq)
        {
            for (auto d : c.second)
            {
                if (d < N - 1)
                {
                    string temp = string(1, c.first) + input[d + 1];
                    len2.insert(temp);
                    if (d < N - 2)
                    {
                        temp += input[d + 2];
                        len3.insert(temp);
                    }
                }
            }
        }

        for (auto c : possible_2)
        {
            if (len2.find(c) == len2.end())
            {
                found = true;
                ans = c;
                break;
            }
        }
        if (found)
        {
            cout << ans << endl;
            continue;
        }

        for (auto c : possible_3)
        {
            if (len3.find(c) == len3.end())
            {
                found = true;
                ans = c;
                break;
            }
        }
        if (found)
        {
            cout << ans << endl;
            continue;
        }
    }

#ifdef TEST
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << endl
         << fixed
         << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}