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

int solve(string status[])
{
    // Set number of X, O, _
    int num_X = 0, num_O = 0, empty = 0;
    REP(i, 3)
    {
        REP(j, 3)
        {
            if (status[i][j] == 'X')
            {
                num_X++;
            }
            else if (status[i][j] == 'O')
            {
                num_O++;
            }
            else if (status[i][j] == '_')
            {
                empty++;
            }
        }
    }
    if ((num_O != num_X && num_O != num_X - 1))
        return 3;

    // Set rows and columns
    vector<string> rows = {status[0], status[1], status[2]}, cols, diags;
    REP(i, 3)
    {
        string str = "";
        REP(j, 3)
        {
            str += status[j][i];
        }
        cols.push_back(str);
    }
    diags.push_back(string({status[0][0], status[1][1], status[2][2]}));
    diags.push_back(string({status[0][2], status[1][1], status[2][0]}));

    int winning[3];
    int winning_count[3] = {0, 0, 0};
    char winner = 0;
    int win_x = 0, win_o = 0, win = 0;
    for (int i = 0; i < rows.size(); i++)
    {
        auto s = rows[i];
        if (s == "XXX" || s == "OOO")
        {
            winning[0] = i;
            winning_count[0]++;
            win++;
            if (s[0] == 'X')
                win_x++;
            else
                win_o++;
        }
    }
    for (int i = 0; i < cols.size(); i++)
    {
        auto s = cols[i];
        if (s == "XXX" || s == "OOO")
        {
            winning[1] = i;
            winning_count[1]++;
            win++;
            if (s[0] == 'X')
                win_x++;
            else
                win_o++;
        }
    }
    for (int i = 0; i < diags.size(); i++)
    {
        auto s = diags[i];
        if (s == "XXX" || s == "OOO")
        {
            winning[2] = i;
            winning_count[2]++;
            win++;
            if (s[0] == 'X')
                win_x++;
            else
                win_o++;
        }
    }

    if (winning_count[0] > 1 || winning_count[1] > 1)
    {
        return 3;
    }
    {
        if (win_o > 1)
            return 3;
        if (win_x > 0 && num_X - num_O != 1)
            return 3;
        if (win_o == 1 && num_X != num_O)
            return 3;
        if (win_x != 0 && win_o != 0)
            return 3;
        if (win > 2)
            return 3;
        if (win == 2)
        {
            if (winning_count[1] == 1 && winning_count[0] == 1)
                return 1;
            if (winning_count[1] == 1 && winning_count[2] == 1)
                return 1;
            if (winning_count[0] == 1 && winning_count[2] == 1)
                return 1;
            if (winning_count[2] == 1 && winning_count[2] == 1)
                return 1;
        }
        if (win == 1)
            return 1;
        if (empty == 0)
            return 1;
        if (win == 2 && (winning_count[0] == 1 || winning_count[1] == 1))
            return 3;
        return 2;
    }
}

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
        string data;
        string status[3];
        REP(i, 9)
        {
            char c;
            cin >> c;
            status[i / 3] += c;
        }
        int ans = solve(status);
        cout << ans << endl;
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