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
        int height, width;
        cin >> height >> width;
        char last_col = '.', last_row = '.', first_char = '.';
        vector<string> lines;
        for (int i = 0; i < height; i++)
        {
            string t;
            cin >> t;
            lines.push_back(t);
        }
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                char c = lines[i][j];
                if (c != '.')
                {
                    first_char = (i % 2 == 0) ? (lines[i][j]) : ((lines[i][j] == 'R') ? 'W' : 'R');
                    first_char = (j % 2 == 0) ? (first_char) : ((first_char == 'R') ? 'W' : 'R');
                    break;
                }
            }
            if (first_char != '.')
                break;
        }
        if (first_char == '.')
        {
            cout << "YES\n";
            char last_col = 'R';
            char last_row = 'R';
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (j == 0)
                    {
                        last_row = (last_row == 'R') ? 'W' : 'R';
                        last_col = last_row;
                        cout << last_row;
                    }
                    else
                    {
                        last_col = (last_col == 'R') ? 'W' : 'R';
                        cout << last_col;
                    }
                }
                cout << "\n";
            }
            continue;
        }

        bool possible = true;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                char c = lines[i][j];
                if (i == 0 && j == 0)
                {
                    last_row = first_char;
                    last_col = first_char;
                    if (c == '.')
                    {
                        lines[i][j] = first_char;
                    }
                    else if (c != first_char)
                    {
                        possible = false;
                        break;
                    }
                    continue;
                }
                if (j == 0)
                {
                    last_row = (last_row == 'R') ? 'W' : 'R';
                    last_col = last_row;
                    if (c == '.')
                    {
                        lines[i][j] = last_row;
                    }
                    else if (c != last_row)
                    {
                        possible = false;
                        break;
                    }
                }
                else
                {
                    last_col = (last_col == 'R') ? 'W' : 'R';
                    if (c == '.')
                    {
                        lines[i][j] = last_col;
                    }
                    else if (c != last_col)
                    {
                        possible = false;
                        break;
                    }
                }
            }
            if (!possible)
                break;
        }
        cout << ((possible) ? "YES\n" : "NO\n");
        if (possible)
        {
            for (int i = 0; i < height; i++)
            {
                cout << lines[i] << endl;
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