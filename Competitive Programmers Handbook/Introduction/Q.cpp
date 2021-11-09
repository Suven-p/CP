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

constexpr int max_size = 16;
vector<bool> columns(max_size, false), d1(max_size, false), d2(max_size, false);
set<pair<int, int>> reserved;
int board_size = 16;
ll current_count = 0;
void count_positions(int row)
{
    if (row == board_size)
    {
        current_count++;
        return;
    }
    for (int col = 0; col < board_size; col++)
    {
        if (columns[col] || d1[row + col] || d2[board_size - 1 + row - col])
        {
            continue;
        }
        if (reserved.count({row, col}))
        {
            continue;
        }
        columns[col] = true;
        d1[row + col] = true;
        d2[board_size - 1 + row - col] = true;
        count_positions(row + 1);
        columns[col] = false;
        d1[row + col] = false;
        d2[board_size - 1 + row - col] = false;
    }
}

void solve()
{
    current_count = 0;
    columns.assign(board_size, false);
    d1.assign(2 * board_size, false);
    d2.assign(2 * board_size, false);
    count_positions(0);
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

    char temp;
    REP(i, 8)
    {
        REP(j, 8)
        {
            cin >> temp;
            if (temp == '*')
            {
                reserved.insert(mp(i, j));
            }
        }
    }
    solve();
    cout << current_count << endl;

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