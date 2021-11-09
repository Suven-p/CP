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
vector<int> tree[maxN];

int block_size, block_cnt;
vector<int> first_visit;
vector<int> euler_tour;
vector<int> height;
vector<int> log_2;
vector<vector<int>> st;
vector<vector<vector<int>>> blocks;
vector<int> block_mask;

void reset()
{
    REP(i, maxN)
    {
        tree[i].clear();
    }
    block_size = 0;
    block_cnt = 0;
    first_visit.clear();
    euler_tour.clear();
    height.clear();
    st.clear();
    blocks.clear();
    block_mask.clear();
}

void dfs(int v, int p, int h)
{
    first_visit[v] = euler_tour.size();
    euler_tour.push_back(v);
    height[v] = h;

    if (v < 1 || v > N)
    {
        printf("error");
    }
    for (int u : tree[v])
    {
        if (u == p)
            continue;
        dfs(u, v, h + 1);
        euler_tour.push_back(v);
    }
}

int min_by_h(int i, int j)
{
    return height[euler_tour[i]] < height[euler_tour[j]] ? i : j;
}

void precompute_lca(int root)
{
    // get euler tour & indices of first occurences
    first_visit.assign(N + 1, -1);
    height.assign(N + 1, 0);
    euler_tour.reserve(2 * N);
    dfs(root, -1, 0);

    // precompute all log values
    int m = euler_tour.size();
    log_2.reserve(m + 1);
    log_2.push_back(-1);
    for (int i = 1; i <= m; i++)
        log_2.push_back(log_2[i / 2] + 1);

    block_size = max(1, log_2[m] / 2);
    block_cnt = (m + block_size - 1) / block_size;

    // precompute minimum of each block and build sparse table
    st.assign(block_cnt, vector<int>(log_2[block_cnt] + 1));
    for (int i = 0, j = 0, b = 0; i < m; i++, j++)
    {
        if (j == block_size)
            j = 0, b++;
        if (j == 0 || min_by_h(i, st[b][0]) == i)
            st[b][0] = i;
    }
    for (int l = 1; l <= log_2[block_cnt]; l++)
    {
        for (int i = 0; i < block_cnt; i++)
        {
            int ni = i + (1 << (l - 1));
            if (ni >= block_cnt)
                st[i][l] = st[i][l - 1];
            else
                st[i][l] = min_by_h(st[i][l - 1], st[ni][l - 1]);
        }
    }

    // precompute mask for each block
    block_mask.assign(block_cnt, 0);
    for (int i = 0, j = 0, b = 0; i < m; i++, j++)
    {
        if (j == block_size)
            j = 0, b++;
        if (j > 0 && (i >= m || min_by_h(i - 1, i) == i - 1))
            block_mask[b] += 1 << (j - 1);
    }

    // precompute RMQ for each unique block
    int possibilities = 1 << (block_size - 1);
    blocks.resize(possibilities);
    for (int b = 0; b < block_cnt; b++)
    {
        int mask = block_mask[b];
        if (!blocks[mask].empty())
            continue;
        blocks[mask].assign(block_size, vector<int>(block_size));
        for (int l = 0; l < block_size; l++)
        {
            blocks[mask][l][l] = l;
            for (int r = l + 1; r < block_size; r++)
            {
                blocks[mask][l][r] = blocks[mask][l][r - 1];
                if (b * block_size + r < m)
                    blocks[mask][l][r] = min_by_h(b * block_size + blocks[mask][l][r],
                                                  b * block_size + r) -
                                         b * block_size;
            }
        }
    }
}

int lca_in_block(int b, int l, int r)
{
    return blocks[block_mask[b]][l][r] + b * block_size;
}

int lca(int v, int u)
{
    int l = first_visit[v];
    int r = first_visit[u];
    if (l > r)
        swap(l, r);
    int bl = l / block_size;
    int br = r / block_size;
    if (bl == br)
        return euler_tour[lca_in_block(bl, l % block_size, r % block_size)];
    int ans1 = lca_in_block(bl, l % block_size, block_size - 1);
    int ans2 = lca_in_block(br, 0, r % block_size);
    int ans = min_by_h(ans1, ans2);
    if (bl + 1 < br)
    {
        int l = log_2[br - bl - 1];
        int ans3 = st[bl + 1][l];
        int ans4 = st[br - (1 << l)][l];
        ans = min_by_h(ans, min_by_h(ans3, ans4));
    }
    return euler_tour[ans];
}

void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-')
    {
        negative = true;

        c = getchar();
    }
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t')
    {
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number *= -1;
}

int main()
{
#ifdef TEST
    freopen("/media/nevus/data/CP/input2.in", "r", stdin);
    freopen("/media/nevus/data/CP/output.out", "w", stdout);
    freopen("/media/nevus/data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    int totalTests = 1;
    fastscan(totalTests);

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int Q;
        fastscan(N);
        fastscan(Q);
        reset();
        REP(i, N - 1)
        {
            int u, v;
            fastscan(u);
            fastscan(v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        precompute_lca(1);
        REP(i, Q)
        {
            int a, b;
            fastscan(a);
            fastscan(b);
            auto ans = lca(a, b);
            printf("%d\n", ans);
        }
#ifdef TEST
        for (int i = 1; i <= min(N, 625); i++)
        {
            for (int j = i + 1; j <= min(N, i + 100); j++)
            {
                if (i != j)
                {
                    auto ans = lca(i, j);
                    printf("%d %d %d\n", i, j, ans);
                }
            }
        }
#endif
    }

#ifdef TEST
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    printf("Time taken by program is:\n%lf seconds\n", time_taken);
#endif
    return 0;
}