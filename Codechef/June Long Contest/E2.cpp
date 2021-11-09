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
typedef pair<int, int> coord;
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
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int N;
        cin >> N;
        set<coord> points, pointsReversed;
        set<int> allX, allY;
        REP(i, N)
        {
            int x, y;
            cin >> x >> y;
            coord temp = mp(x, y);
            points.insert(temp);
            pointsReversed.insert(mp(y, x));
            allX.insert(x);
            allY.insert(y);
        }
        // trivial casses
        if (N == 1 || allX.size() == 1 || allY.size() == 1)
        {
            cout << 0 << endl;
            continue;
        }
        ll ans1 = 1e18, ans2 = 1e18;
        int curMin = 1e9, curMax = -1e9;
        map<int, ll> xForward, xBackward;
        for (auto it = points.begin(); it != points.end(); it++)
        {
            auto c = *it;
            curMin = min(c.second, curMin);
            curMax = max(c.second, curMax);
            xForward[c.first] = curMax - curMin;
        }
        curMin = 1e9, curMax = -1e9;
        for (auto it = points.rbegin(); it != points.rend(); it++)
        {
            auto c = *it;
            curMin = min(c.second, curMin);
            curMax = max(c.second, curMax);
            xBackward[c.first] = curMax - curMin;
        }

        auto start = allX.begin();
        auto end = --(allX.end());
        for (auto it = start; it != end;)
        {
            ll val = *it;
            ll temp1, temp2;
            temp1 = (val - (*start)) * xForward[val];
            ++it;
            val = *it;
            temp2 = ((*end) - val) * xBackward[val];
            auto cur = temp1 + temp2;
            ans1 = min(cur, ans1);
        }

        curMin = 1e9, curMax = -1e9;
        map<int, ll> yForward, yBackward;
        for (auto it = pointsReversed.begin(); it != pointsReversed.end(); it++)
        {
            auto c = *it;
            curMin = min(c.second, curMin);
            curMax = max(c.second, curMax);
            yForward[c.first] = curMax - curMin;
        }
        curMin = 1e9, curMax = -1e9;
        for (auto it = pointsReversed.rbegin(); it != pointsReversed.rend(); it++)
        {
            auto c = *it;
            curMin = min(c.second, curMin);
            curMax = max(c.second, curMax);
            yBackward[c.first] = curMax - curMin;
        }

        start = allY.begin();
        end = --(allY.end());
        for (auto it = start; it != end;)
        {
            ll val = *it;
            ll temp1, temp2;
            temp1 = (val - (*start)) * yForward[val];
            ++it;
            val = *it;
            temp2 = ((*end) - val) * yBackward[val];
            auto cur = temp1 + temp2;
            ans2 = min(cur, ans2);
        }

        cout << min(ans1, ans2) << endl;
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