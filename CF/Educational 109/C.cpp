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
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int N, M;
        cin >> N >> M;
        int positions[N], directions[N], processed[N], answers[N];
        set<int> collisions[N];
        map<pair<int, int>, int> data;
        set<pair<int, int>> lefts, rights;
        memset(processed, 0, sizeof(processed));
        memset(collisions, 0, sizeof(collisions));
        REP(i, N)
        {
            cin >> positions[i];
        }
        REP(i, N)
        {
            char temp;
            cin >> temp;
            directions[i] = (temp == 'L') ? -1 : 1;
        }
        REP(i, N)
        {
            data[mp(positions[i], directions[i])] = i;
            if (directions[i] == 1)
            {
                rights.insert(positions[i], i);
            }
            else
            {
                lefts.insert(positions[i], 1);
            }
        }
        vector<pair<int, int>> st;
        while (auto c
               : data)
        {
            auto pos = c.first.first;
            auto direc = c.first.second;
            auto ind = c.second;
            if (st.size())
            {
            }
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