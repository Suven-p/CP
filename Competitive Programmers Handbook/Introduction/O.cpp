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

ll fact(ll N)
{
    if (N == 1 || N == 0)
        return 1;
    return N * fact(N - 1);
}

ll combination(map<char, int> chars, ll N)
{
    ll ans = fact(N);
    for (auto c : chars)
    {
        ans /= fact(c.second);
    }
    return ans;
}

void solve(map<char, int> chars, string ans)
{
    for (auto it = chars.begin(); it != chars.end();)
    {
        if (it->second == 0)
        {
            it = chars.erase(it);
            continue;
        }
        else
        {
            it++;
        }
    }

    if (chars.size() == 0)
    {
        cout << ans << "\n";
        return;
    }
    if (chars.size() == 1)
    {
        string temp((chars.begin())->second, (chars.begin())->first);
        ans += temp;
        cout << ans << "\n";
        return;
    }
    else
    {

        for (auto it = chars.begin(); it != chars.end(); it++)
        {
            auto c = it->first;
            (it->second)--;
            solve(chars, ans + c);
            (it->second)++;
        }
    }
}

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

    string str;
    cin >> str;
    map<char, int> chars;
    for (auto c : str)
    {
        chars[c]++;
    }
    cout << combination(chars, str.size()) << "\n";
    solve(chars, "");

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