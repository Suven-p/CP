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
    int totalChairs = 1;
    cin >> totalChairs;
    bool data[totalChairs];
    set<int> occupied, free;
    for (int numChair = 0; numChair < totalChairs; numChair++)
    {
        cin >> data[numChair];
        if (data[numChair])
            occupied.insert(numChair);
        else
            free.insert(numChair);
    }
    int ans = 0;
    for (auto it = occupied.begin(); it != occupied.end(); it++)
    {
        auto current = *it;
        int ans1 = 0, ans2 = 0;

        int temp = current + 1;
        while (temp > 0 && temp < totalChairs)
        {
            if (data[temp] == 0)
            {
                break;
            }
            temp++;
        }
        if (temp == totalChairs)
            ans1 = 1e9;
        else
            ans1 = temp - current;

        temp = current - 1;
        while (temp >= 0 && temp < totalChairs)
        {
            if (data[temp] == 0)
            {
                break;
            }
            temp--;
        }
        if (temp == -1)
            ans2 = 1e9;
        else
            ans2 = current - temp;

        if (ans1 < ans2)
        {
            ans += ans1;
            data[ans1 + current] = 1;
        }
        else
        {
            ans += ans2;
            data[ans2 + current] = 1;
        }
    }

    cout << ans << endl;

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