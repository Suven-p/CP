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

#define maxN 100005
vector<int> tree[maxN];
vector<ll> values(maxN, 0);
vector<ll> ans(maxN, 0);

void reset()
{
    REP(i, maxN)
    {
        tree[i].clear();
        values[i] = 0;
        ans[i] = -1;
    }
}

set<ll> solve(int root, int parent)
{
    set<ll> elems = {values[root]};
    for (auto &child : tree[root])
    {
        if (child == parent)
            continue;
        auto childElems = solve(child, root);
        elems.insert(childElems.begin(), childElems.end());
    }
    auto it = elems.begin();
    it++;
    ll minXOR = 1e9;
    for (; it != elems.end(); it++)
    {
        auto curr = *it;
        it--;
        auto prev = *it;
        it++;
        ll temp = curr ^ prev;
        minXOR = min(minXOR, temp);
    }
    ans[root] = minXOR;
    return elems;
}

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
        int N;
        cin >> N;
        reset();
        REP(i, N - 1)
        {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        REP(i, N)
        {
            cin >> values[i + 1];
        }
        solve(1, -1);
        for (int i = 1; i <= N; i++)
        {
            if (tree[i].size() <= 1)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << ans[i] << " ";
            }
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
