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
set<ll> X, Y;
vll scoresA, scoresB;
map<ll, set<ll>> mapX, mapY;

ll solve()
{
    if (mapX.empty())
        return 0;
    else if (N == 1)
    {
        ll ans = 0;
        auto positions = mapX.begin()->second;
        for (auto c : positions)
        {
            ans += (scoresA[c] - scoresB[c]);
        }
        return ans;
    }
    auto max1 = mapX.rbegin()->first;
    auto max2 = mapY.rbegin()->first;
    ll pos1 = *(mapX[max1].begin()), pos2 = *(mapY[max2].begin());
    for (auto c : mapX[max1])
    {
        if (scoresB[c] > scoresB[pos1])
        {
            pos1 = c;
        }
    }
    for (auto c : mapY[max2])
    {
        if (scoresA[c] > scoresA[pos2])
        {
            pos2 = c;
        }
    }
    ll ans1 = scoresA[pos1] - scoresB[pos2];
    ll ans2 = scoresA[pos2] - scoresB[pos1];
    mapX[max1].erase(pos1);
    mapY[max2].erase(pos2);
    if (mapX[max1].empty())
        mapX.erase(max1);
    if (mapY[max2].empty())
        mapY.erase(max2);
    // X.erase(max1);
    // Y.erase(max2);
    N -= 2;
    return max(ans1, ans2) + solve();
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
        // X.clear();
        // Y.clear();
        mapX.clear();
        mapY.clear();
        scoresA.clear();
        scoresB.clear();
        cin >> N;
        REP(i, N)
        {
            ll temp;
            cin >> temp;
            // X.insert(temp);
            mapX[temp].insert(i);
            scoresA.push_back(temp);
        }
        REP(i, N)
        {
            ll temp;
            cin >> temp;
            // Y.insert(temp);
            mapY[temp].insert(i);
            scoresB.push_back(temp);
        }
        auto ans = solve();
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