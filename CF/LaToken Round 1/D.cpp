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

int numNodes;
int numQueries = 0;

set<pair<int, int>> edges;

void solve()
{
    vector<int> black_nodes, white_nodes, root_adjacent;

    cout << "? 1" << endl;
    numQueries++;
    int temp;
    REP(i, numNodes)
    {
        cin >> temp;
        if (i == 0)
            continue;
        if (temp % 2 == 0)
        {
            black_nodes.push_back(i + 1);
        }
        else
        {
            white_nodes.push_back(i + 1);
        }
        if (temp == 1)
        {
            root_adjacent.push_back(i + 1);
        }
    }

    auto &nodesToVisit = (black_nodes.size() > white_nodes.size()) ? white_nodes : black_nodes;
    for (auto c : root_adjacent)
    {
        edges.insert(mp(1, c));
    }
    for (auto current : nodesToVisit)
    {
        assert(numQueries <= (numNodes + 1) / 2);
        cout << "? " << current << endl;
        numQueries++;
        int temp;
        REP(i, numNodes)
        {
            cin >> temp;
            if (temp == 1)
            {
                edges.insert(mp(min(i + 1, current), max(i + 1, current)));
            }
        }
    }
}

int main()
{
#ifdef TEST
    // freopen("/media/nevus/data/CP/input.in", "r", stdin);
    // freopen("/media/nevus/data/CP/output.out", "w", stdout);
    // freopen("/media/nevus/data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> numNodes;
    solve();
    assert(edges.size() == numNodes - 1);
    cout << "!" << endl;
    for (auto c : edges)
    {
        cout << c.first << " " << c.second << "\n";
    }
    cout.flush();

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