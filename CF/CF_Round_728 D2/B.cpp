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
constexpr int maxN = 1e5 + 7;
int input[maxN];
vector<int> factors[2 * maxN];

void pre()
{
    for (int i = 1; i < 2 * maxN; i++)
    {
        for (int j = i; j < maxN; j += i)
        {
            factors[j].push_back(i);
        }
    }
}

vector<int> get_factors(int x)
{
    return factors[x];
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
    pre();
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        cin >> N;
        int ans = 0;
        std::map<int, int> index_map;
        for (int i = 1; i <= N; i++)
        {
            cin >> input[i];
            index_map[input[i]] = i;
        }
        for (int sum_i_j = 3; sum_i_j <= (N) + (N - 1); sum_i_j++)
        {
            auto factors = get_factors(sum_i_j);
            for (auto it = factors.begin(); it != factors.end(); it++)
            {
                if ((*it) > int(sqrt(sum_i_j)))
                    break;
                // edge case: for sum_i_j = 4; if input[2] == 2 => index_map[2] == index_map[2]
                if ((*it) * (*it) == sum_i_j)
                    break;
                auto next = sum_i_j / (*it);
                if (index_map[(*it)] + index_map[next] == sum_i_j)
                {
                    ans++;
                }
            }
        }

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