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

set<string> substrs;
ll getNext(string input)
{
    char req = (input[0] == '0') ? '1' : '0';
    for (ll i = 1; i < input.size(); i++)
    {
        if (input[i] != req && input[i] != '?')
        {
            return i;
        }
        req = (req == '0') ? '1' : '0';
    }
    return input.size();
}

ll solve(string input)
{
    if (input[0] == '?')
    {
        input[0] = '0';
        auto ans1 = solve(input);
        input[0] = '1';
        auto ans2 = solve(input);
        return ans1 + ans2;
    }
    auto next = getNext(input);
    auto next2 = next - 1;
    while (input[next2] == '?')
        next2--;
    next2++;
    if (next == input.size())
    {
        return ((input.size() + 1) * input.size()) / 2;
    }
    auto ans = (next * (next +)) / 2;
    ans += solve(input.substr(next, input.size() - next));
    return ans;
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
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        substrs.clear();
        string input;
        cin >> input;
        auto ans = solve(input);
        cout << ans << "\n";
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