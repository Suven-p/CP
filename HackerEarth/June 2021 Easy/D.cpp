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

int N, M;
const int maxN = 1e1 + 9;
int trains[maxN];
vector<pair<int, int>> nearestTrains(maxN, mp(0, 0));

void reset()
{
    nearestTrains = vector<pair<int, int>>(maxN, mp(0, 0));
}

int solve(int B)
{
    int leftNearest = nearestTrains[B].first;
    int rightNearest = nearestTrains[B].second;
    int minDistance = maxN;
    if (leftNearest > 0)
    {
        minDistance = min(minDistance, B - leftNearest);
    }
    if (rightNearest > 0)
    {
        minDistance = min(minDistance, rightNearest - B);
    }
    if (minDistance == maxN)
        minDistance = -1;
    return minDistance;
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
        reset();
        cin >> N >> M;
        vi movingLeft;
        int previousRight = 0;
        FOR(i, 1, N + 1, 1)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                previousRight = i;
            }
            else if (temp == 2)
            {
                movingLeft.push_back(i);
            }
            nearestTrains[i].first = previousRight;
        }
        int prev = 0;
        for (auto c : movingLeft)
        {
            FOR(i, prev + 1, c + 1, 1)
            {
                nearestTrains[i].second = c;
            }
            prev = c;
        }

        FOR(i, 1, M + 1, 1)
        {
            int temp;
            cin >> temp;
            auto ans = solve(temp);
            cout << ans << " ";
        }
        cout << endl;
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