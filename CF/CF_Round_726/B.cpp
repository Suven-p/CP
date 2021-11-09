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
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int N, M, i, j;
        cin >> N >> M >> i >> j;
        int dist[4];
        dist[0] = (i - 1) + (j - 1);
        dist[1] = (i - 1) + (M - j);
        dist[2] = (N - i) + (M - j);
        dist[3] = (N - i) + (j - 1);
        int ind[] = {0, 1, 2, 3};
        pair<int, int> points[4] = {mp(1, 1), mp(1, M), mp(N, M), mp(N, 1)};
        sort(ind, ind + 4, [dist](int a, int b)
             { return dist[a] > dist[b]; });

        if (N == 1)
        {
            cout << "1 1 1 " << M << endl;
            continue;
        }
        if (M == 1)
        {
            cout << "1 1 " << N << " 1" << endl;
            continue;
        }
        cout << points[ind[0]].first << " " << points[ind[0]].second << " ";
        if (dist[ind[3]] == 0)
        {
            cout << points[ind[1]].first << " " << points[ind[1]].second << endl;
        }
        else
        {
            auto pnt = points[(ind[0] + 2) % 4];
            cout << pnt.first << " " << pnt.second << endl;
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