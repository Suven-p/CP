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
    vector<pair<int, int>> input(N);
    vector<int> t(N);
    int ans = 0;
    REP(i, N)
    {
        int start, end;
        cin >> t[i] >> start >> end;
        input[i] = mp(start, end);

        REP(j, i)
        {
            if (input[j].first > end || input[j].second < start)
            {
                continue;
            }
            else if (input[j].second == start)
            {
                if (t[j] == 2 || t[j] == 4)
                    continue;
                if (t[i] == 3 || t[i] == 4)
                    continue;
            }
            else if (input[j].first == end)
            {
                if (t[j] == 3 || t[j] == 4)
                    continue;
                if (t[i] == 2 || t[i] == 4)
                    continue;
            }
            ans++;
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