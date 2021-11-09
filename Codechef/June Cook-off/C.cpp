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
constexpr int maxN = 1e4 + 7;
int input[maxN];

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
        memset(input, 0, sizeof(input));
        cin >> N;
        map<int, set<int>> inp_index;
        bool all_zero = true;
        REP(i, N)
        {
            int temp;
            cin >> temp;
            input[i] = temp;
            inp_index[input[i]].insert(i);
            if (all_zero && temp)
            {
                all_zero = false;
            }
        }
        if (N > 1 && all_zero)
        {
            cout << -1 << "\n";
            continue;
        }
        if (N == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        else if (N == 2)
        {
            if (input[0] == input[1])
            {
                cout << -1 << "\n";
                continue;
            }
            else
            {
                cout << 0 << "\n";
                continue;
            }
        }
        else if (N == 3)
        {
            if (input[0] == input[2])
            {
                if (input[0] == 0)
                {
                    cout << "0\n";
                }
                else
                {
                    cout << 1 << "\n";
                    cout << "1 3 2\n";
                    continue;
                }
            }
            else if (input[1] == 0)
            {
                cout << 1 << "\n";
                if (input[0] != 0)
                    cout << "1 2 3\n";
                else
                {
                    cout << "2 3 1\n";
                }
            }
            else
            {
                cout << -1 << "\n";
            }
            continue;
        }
        else
        {
            int a = -1, b = -1, c = -1;
            for (int i = 0; i < N; i += 2)
            {
                if (a == -1)
                {
                    if (input[i] != 0)
                    {
                        a = i;
                    }
                }
                else if (input[i] != input[a])
                {
                    if (input[i] != 0)
                    {
                        b = i;
                        break;
                    }
                    else
                    {
                        c = i;
                    }
                }
            }
            if (a == -1)
            {
                cout << ((N + 1) / 2) - 1 << "\n";
                for (int i = 1; i < N; i += 2)
                {
                    if (input[i] != 0)
                    {
                        b = i;
                        break;
                    }
                }
                for (int i = 1; i < N; i += 2)
                {
                    if (i != b)
                    {
                        cout << 1 << " " << b + 1 << " " << i + 1 << "\n";
                    }
                }
            }
            else if (b == -1)
            {
                if (c != -1)
                {
                    cout << ((N + 1) / 2) + 1 << "\n";
                    for (int i = 1; i < N; i += 2)
                    {
                        cout << a + 1 << " " << c + 1 << " " << i + 1 << "\n";
                    }
                    cout << "2 4 " << a + 1 << "\n";
                }
                else
                {
                    cout << ((N + 1) / 2) << "\n";
                    for (int i = 1; i < N; i += 2)
                    {
                        cout << a + 1 << " " << (a + 1 + 2) % N << " " << i + 1 << "\n";
                    }
                }
            }
            else
            {
                cout << N << "\n";
                for (int i = 1; i < N; i += 2)
                {
                    cout << a + 1 << " " << b + 1 << " " << i + 1 << "\n";
                }
                for (int i = 0; i < N; i += 2)
                {
                    cout << "2 4 " << i + 1 << "\n";
                }
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