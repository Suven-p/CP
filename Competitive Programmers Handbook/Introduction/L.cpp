#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
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

int main()
{
#ifdef TEST
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    freopen("/media/psuv/Data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string inp;
    cin >> inp;
    map<char, int> freq;
    for (auto c : inp)
    {
        freq[c]++;
    }

    string ans;
    bool possible = true;
    char middle = 0;
    for (auto c : freq)
    {
        if (c.second % 2 == 1)
        {
            if (middle)
            {
                possible = false;
                break;
            }
            else
            {
                string temp(c.second / 2, c.first);
                ans += temp;
                middle = c.first;
            }
        }
        else
        {
            string temp(c.second / 2, c.first);
            ans += temp;
        }
    }
    if (possible)
    {
        string temp(ans.rbegin(), ans.rend());
        if (middle)
            ans += middle;
        ans += temp;
    }
    else
    {
        ans = "NO SOLUTION";
    }
    cout << ans << endl;

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