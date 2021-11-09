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
    map<int, set<int>> distances1, distances2;
    vector<pair<int, int>> points1(N), points2(N);
    vector<bool> visited(N, false);

    REP(i, N)
    {
        int x, y;
        cin >> x >> y;
        points1[i] = mp(x, y);
        REP(j, i)
        {
            int dist = pow((x - points1[j].first), 2) + pow((y - points1[j].second), 2);
            distances1[i].insert(dist);
        }
    }
    REP(i, N)
    {
        int x, y;
        cin >> x >> y;
        points2[i] = mp(x, y);
        REP(j, i)
        {
            int dist = pow((x - points2[j].first), 2) + pow((y - points2[j].second), 2);
            distances2[i].insert(dist);
        }
    }
    REP(i, N)
    {
        auto first = distances1[i];
        bool found = false;
        REP(j, N)
        {
            auto second = distances2[j];
            if (!visited[j] && first == second)
            {
                visited[j] = true;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

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