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

constexpr int maxFiles = 10000 + 9;
int numFiles;
string files[maxFiles];
map<string, set<int>> count_map;
const int maxQue = 50000 + 9;
int numQuery;

void ins(int index, string file)
{
    for (int len = 1; len <= file.size(); len++)
    {
        for (int i = 0; i + len <= file.size(); i++)
        {
            auto temp = file.substr(i, len);
            count_map[temp].insert(index);
        }
    }
}

pair<int, string> solve(string query)
{
    int num;
    string ans;
    if (count_map.count(query) != 0)
    {
        num = count_map[query].size();
        ans = files[*(count_map[query].begin())];
    }
    else
    {
        num = 0;
        ans = "-";
    }
    return mp(num, ans);
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

    cin >> numFiles;

    for (int file = 0; file < numFiles; file++)
    {
        string temp;
        cin >> temp;
        files[file] = temp;
        ins(file, temp);
    }

    cin >> numQuery;
    REP(i, numQuery)
    {
        string temp;
        cin >> temp;
        auto ans = solve(temp);
        cout << ans.first << " " << ans.second << "\n";
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