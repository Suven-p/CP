// Incomplete

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

struct Ant
{
    int position, direction;
    Ant(int position, int direction) : position(position), direction(direction) {}
};

int main()
{
#ifdef TEST
    freopen("/media/lubuntu_nevus/Home_image/CP/input.in", "r", stdin);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stdout);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int N, L;
        cin >> N >> L;
        vector<Ant> ants;
        REP(i, N)
        {
            int position, direction;
            cin >> position >> direction;
            Ant ant(position, direction);
            ants.push_back(ant);
        }
        sort(ants.begin(), ants.end(), [](Ant &a, Ant &b)
             {
                if(a.position == b.position)
                    return a.direction < b.direction;
                return a.position < b.position; });
        map<int, unordered_set<int>> positions;
        while (true)
        {
            bool flag = false;
            for (auto &ant : ants)
            {
                if (ant.position < 0 || ant.position > L)
                {
                    continue;
                }
            }
            for (auto &ant : ants)
            {
                if (positions[ant.position].size() > 1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (processed[i])
            {
                continue;
            }
            if (ants[i].position < 0 || ants[i].position > L)
            {
                processed[i] = 1;
                continue;
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
