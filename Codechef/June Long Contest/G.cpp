#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#pragma GCC optimize "O3"
#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#pragma GCC optimize "trapv"
#define TEST
#endif

int N;
constexpr int maxN = 1e5 + 7;
vector<int> tree[maxN];

// vector<int> path[maxN];
ll num_child[maxN];
ll values[maxN];

int first_visit[maxN];
int euler_tour[2 * maxN];
int euler_height[2 * maxN];
int depth[maxN];
int euler_index = 0;

ll sum_paths[maxN];
// added
map<int, set<int>> height_to_euler;

void reset()
{
    for (int i = 0; i < maxN; i++)
    {
        tree[i].clear();
    }
    height_to_euler.clear();
    euler_index = 0;
}

void dfs(int current, int parent, int h)
{
    // path[current] = path[parent];
    // path[current].push_back(current);

    // num_child inclues the current node
    num_child[current] = 1;
    values[current] = 0;

    auto height = depth[parent] + 1;
    depth[current] = height;

    euler_tour[euler_index] = current;
    euler_height[euler_index] = height;
    first_visit[current] = euler_index;
    height_to_euler[height].insert(euler_index);
    euler_index++;

    if (current < 1 || current > N)
    {
        printf("error");
    }
    for (int u : tree[current])
    {
        if (u == parent)
            continue;
        dfs(u, current, h + 1);
        euler_tour[euler_index] = current;
        euler_height[euler_index] = height;
        height_to_euler[height].insert(euler_index);
        euler_index++;

        values[current] += (values[u] + num_child[u]);
        num_child[current] += num_child[u];
    }
}

void dfs1(int current, int parent)
{
    if (current == 1)
    {
        sum_paths[current] = values[current];
    }
    else
    {
        sum_paths[current] = sum_paths[parent] + ll(N - num_child[current]) - num_child[current];
    }
    for (auto c : tree[current])
    {
        if (c == parent)
            continue;
        dfs1(c, current);
    }
}

struct rmq
{
    vector<int> st;
    int n;
    static const int b = 18; // block size
    vector<int> mask, t;     // mask and sparse table

    int op(int x, int y) const
    {
        return st[x] < st[y] ? x : y;
    }
    // least significant set bit
    int lsb(int x)
    {
        return x & -x;
    }
    // index of the most significant set bit
    int msb_index(int x) const
    {
        return __builtin_clz(1) - __builtin_clz(x);
    }
    // answer query of v[r-size+1..r] using the masks, given size <= b
    int small(int r, int size = b) const
    {
        // get only 'size' least significant bits of the mask
        // and then get the index of the msb of that
        int dist_from_r = msb_index(mask[r] & ((1 << size) - 1));

        return r - dist_from_r;
    }
    rmq(int v_[], int num) : st(v_, v_ + num), n(num), mask(num), t(num)
    {
        int curr_mask = 0;
        for (int i = 0; i < n; i++)
        {
            // shift mask by 1, keeping only the 'b' least significant bits
            curr_mask = (curr_mask << 1) & ((1 << b) - 1);
            while (curr_mask > 0 and op(i, i - msb_index(lsb(curr_mask))) == i)
            {
                // current value is smaller than the value represented by the
                // last 1 in curr_mask, so we need to turn off that bit
                curr_mask ^= lsb(curr_mask);
            }
            // append extra 1 to the mask
            curr_mask |= 1;

            mask[i] = curr_mask;
        }
        // build sparse table over the n/b blocks
        // the sparse table is linearized, so what would be at
        // table[j][i] is stored in table[(n/b)*j + i]
        for (int i = 0; i < n / b; i++)
            t[i] = small(b * i + b - 1);
        for (int j = 1; (1 << j) <= n / b; j++)
            for (int i = 0; i + (1 << j) <= n / b; i++)
                t[n / b * j + i] = op(t[n / b * (j - 1) + i], t[n / b * (j - 1) + i + (1 << (j - 1))]);
    }
    // query(l, r) returns the actual minimum of v[l..r]
    // to get the index, just change the first and last lines of the function
    int query(int l, int r) const
    {
        // query too small
        if (r - l + 1 <= b)
            return small(r, r - l + 1);

        // get the minimum of the endpoints
        // (there is no problem if the ranges overlap with the sparse table query)
        int ans = op(small(l + b - 1), small(r));

        // 'x' and 'y' are the blocks we need to query over
        int x = l / b + 1, y = r / b - 1;

        if (x <= y)
        {
            int j = msb_index(y - x + 1);
            ans = op(ans, op(t[n / b * j + x], t[n / b * j + y - (1 << j) + 1]));
        }

        return ans;
    }
};

rmq preprocess()
{
    // euler_height.assign(2 * maxN, 0);
    depth[0] = -1;
    dfs(1, 0, 0);
    dfs1(1, 0);
    return rmq(euler_height, euler_index);
}

void fastscan(int &number)
{
    bool negative = false;
    int c;
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

int computeLca(const rmq &range_min, const int &u, const int &v)
{
    auto index1 = first_visit[u], index2 = first_visit[v];
    if (index1 > index2)
    {
        swap(index1, index2);
    }
    auto index = range_min.query(index1, index2);
    return euler_tour[index];
}

int distance(const rmq &range_min, int u, int v, int lca = 0)
{
    if (depth[u] > depth[v])
        swap(u, v);
    lca = (lca == 0) ? computeLca(range_min, u, v) : lca;
    return (depth[u] - depth[lca]) + (depth[v] - depth[lca]);
}

int get_ancestor(int u, int d)
{
    if (d == 0)
        return u;
    int req_depth = depth[u] - d;
    auto search = height_to_euler[req_depth].lower_bound(first_visit[u]);
    auto value = *(--search);
    auto ans1 = euler_tour[value];
    // auto ans2 = path[u][path[u].size() - d - 1];
    // if (ans1 != ans2)
    // {
    //     printf("orgib");
    // }
    return ans1;
}

ll solve(const rmq &range_min, int a, int b)
{
    if (N == 2)
        return 0;
    // a is the node closest to lca
    if (depth[a] > depth[b])
        swap(a, b);

    int lca = computeLca(range_min, a, b);
    int pivot1;

    int distAB = distance(range_min, a, b, lca);
    int distAPivot = int(distAB / 2);
    int distALca = (depth[a] - depth[lca]);
    if (distAPivot <= distALca && distAPivot)
    {
        pivot1 = get_ancestor(a, distAPivot);
    }
    else
    {
        int remainingLen = depth[lca] + distAPivot - distALca;
        pivot1 = get_ancestor(b, depth[b] - remainingLen);
    }

    ll ans = sum_paths[a];
    // next is the cutoff node ie node directly below pivot1 and leading to b
    int next;
    next = get_ancestor(b, (depth[b] - depth[pivot1]) - 1);

    // decrement contribution to lca from node next
    ans = ans - (values[next] + num_child[next]);
    // adjust for height difference between lca and a
    int dist1;
    dist1 = distance(range_min, a, pivot1);
    ans = ans - (num_child[next]) * dist1;

    // rotate the nodes so that node next becomes root node
    int pivot2 = next;
    // calculate (num+values) for node pivot1
    // new total value for node pivot2 is sum_paths for it
    // currently values[pivot2] stores sum of num+values for all nodes except pivot1
    ll value_t1_new = sum_paths[pivot2] - (values[pivot2]);
    ll numChild_t1_new = N - num_child[pivot2];
    next = pivot1;
    ll ans2 = sum_paths[b];
    // value_t1_new already includes num and values
    ans2 = ans2 - (value_t1_new);
    int dist2 = distance(range_min, b, pivot2);
    ans2 = ans2 - (numChild_t1_new)*dist2;

    return ans + ans2;
}

int numTest;
int main()
{
#ifdef TEST
    auto f = freopen("/media/nevus/data/CP/input.in", "r", stdin);
    if (!f)
        throw("One of file paths is wrong");
    f = freopen("/media/nevus/data/CP/output.out", "w", stdout);
    if (!f)
        throw("One of file paths is wrong");
    f = freopen("/media/nevus/data/CP/output.out", "w", stderr);
    if (!f)
        throw("One of file paths is wrong");
    auto start = chrono::high_resolution_clock::now();
#endif
    int totalTests = 1;
    fastscan(totalTests);

    for (numTest = 1; numTest <= totalTests; numTest++)
    {
        int Q;
        fastscan(N);
        fastscan(Q);
        reset();
        for (int i = 0; i < N - 1; i++)
        {
            int u, v;
            fastscan(u);
            fastscan(v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        auto range_min = preprocess();
        for (int i = 0; i < Q; i++)
        {
            int a, b;
            fastscan(a);
            fastscan(b);
            auto ans = solve(range_min, a, b);
            printf("%lld\n", ans);
        }
#ifdef TEST
        long long ans = 0;
        for (int i = 1; i <= min(N, 625); i++)
        {
            for (int j = i + 1; j <= min(N, i + 100); j++)
            {
                if (i != j)
                {
                    ans = solve(range_min, i, j);
                    // ans %= (long long)(1e9 + 7);
                    printf("%d %d %d %lld\n", numTest, i, j, ans);
                }
            }
        }
        printf("%lld\n", ans);
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