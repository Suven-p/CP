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

    int N;
    cin >> N;
    vi input(N);
    // vector<pair<int, int>> incl;
    map<int, set<int>> incl;
    REP(i, N)
    {
        cin >> input[i];
    }
    auto st = input.begin();
    auto en = input.rbegin();
    int count = 0;
    while (count < int(N / 2))
    {
        if (*st != *en)
        {
            incl[*st].insert(*en);
            incl[*en].insert(*st);
            // incl.push_back(mp(min(*st, *en), max(*st, *en)));
        }
        count++;
        st++;
        en++;
    }
    int ans = 0;
    for (auto c : incl)
    {
        int to_repl = c.first;
        if (!c.second.size())
            continue;
        ans++;
        int repl_by = *(c.second.begin());
        for (auto d : c.second)
        {
            incl[d].erase(to_repl);
            if (d != repl_by)
            {
                incl[d].insert(repl_by);
            }
        }
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