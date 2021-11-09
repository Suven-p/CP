#include <bits/stdc++.h>

using namespace std;

// #pragma GCC optimize "O3"
#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#define TEST
#endif

int N;
constexpr int maxN = 1e5 + 2;
vector<int> tree[maxN];

vector<int> path[maxN];
int num_child[maxN];
int values[maxN];

int first_visit[maxN];
int euler_tour[2 * maxN];
// vector<int> euler_height;
int euler_height[2 * maxN];
int depth[maxN];
int euler_index = 0;
map<int, set<int>> height_to_euler;

int sum_paths[maxN];

void reset()
{
    for (int i = 0; i < maxN; i++)
    {
        tree[i].clear();
        // path[i].clear();
    }
    // memset(first_visit, 0, sizeof(first_visit));
    // memset(depth, 0, sizeof(depth));
    // memset(euler_tour, 0, sizeof(euler_tour));
    // euler_height.clear();
    // memset(euler_height, 0, sizeof(euler_height));
    // memset(sum_paths, 0, sizeof(sum_paths));
    euler_index = 0;
}

void dfs(int current, int parent)
{
    // path[current] = path[parent];
    // path[current].push_back(current);
    // num_child inclues the current node
    num_child[current] = 1;
    values[current] = 0;

    depth[current] = depth[parent] + 1;
    euler_tour[euler_index] = current;
    euler_height[euler_index] = depth[parent] + 1;
    first_visit[current] = euler_index;
    height_to_euler[depth[parent] + 1].insert(euler_index);
    euler_index++;

    if (current < 1 || current > N)
    {
        printf("error");
    }
    for (int u : tree[current])
    {
        if (u == parent)
            continue;
        dfs(u, current);
        euler_tour[euler_index] = current;
        euler_height[euler_index] = depth[parent] + 1;
        height_to_euler[depth[parent] + 1].insert(euler_index);
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
        sum_paths[current] = sum_paths[parent] + (N - num_child[current]) - num_child[current];
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
    static const int b = 30; // block size
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
    rmq(int v_[], int n) : st(v_, v_ + n), n(n), mask(n), t(n)
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
    dfs(1, 0);
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

int distance(const rmq &range_min, int u, int v, int lca = -1)
{
    if (depth[u] > depth[v])
        swap(u, v);
    lca = (lca != -1) ? computeLca(range_min, u, v) : lca;
    return (depth[u] - depth[lca]) + (depth[v] - depth[lca]);
}

int get_ancestor(int u, int d)
{
    if (d == 0)
        return u;
    int req_depth = depth[u] - d;
    auto search = height_to_euler[req_depth].lower_bound(first_visit[u]);
    auto value = *(--search);
    return euler_tour[value];
    // return path[u][path[u].size() - d - 1];
}

int solve(const rmq &range_min, int a, int b)
{
    if (N == 2)
        return 0;
    // a is the node closest to lca
    if (depth[a] > depth[b])
        swap(a, b);

    int lca = computeLca(range_min, a, b);
    int pivot1, pivot2;

    int distAB = distance(range_min, a, b, lca);
    int distAPivot = int(distAB / 2);
    int distALca = (depth[a] - depth[lca]);
    int dist1, dist2, next;
    if (distAPivot < distALca && distAPivot && lca != a)
    {
        pivot1 = get_ancestor(a, distAPivot);
        // next is the cutoff node ie node directly below pivot1 and leading to b
        next = get_ancestor(a, depth[a] - depth[pivot1] - 1);
        dist1 = distAPivot;
        // rotate the nodes so that node next becomes root node
        pivot2 = next;
        dist2 = distAB - distAPivot;
    }
    else
    {
        int remainingLen = distAPivot - distALca;
        pivot1 = get_ancestor(b, depth[b] - depth[lca] - remainingLen);
        // next is the cutoff node ie node directly below pivot1 and leading to b
        next = get_ancestor(b, depth[b] - depth[pivot1] - 1);
        dist1 = distAPivot;
        // rotate the nodes so that node next becomes root node
        pivot2 = next;
        dist2 = distAB - distAPivot - 1;
    }

    int ans = sum_paths[a];

    // decrement contribution to lca from node next
    ans = ans - (values[next] + num_child[next]);
    // adjust for height difference between pivot and a
    ans = ans - (num_child[next]) * dist1;

    // calculate (num+values) for node pivot1
    // new total value for node pivot2 is sum_paths for it
    // currently values[pivot2] stores sum of num+values for all nodes except pivot1
    int value_t1_new = sum_paths[pivot2] - (values[pivot2]);
    int numChild_t1_new = N - num_child[pivot2];
    next = pivot1;
    int ans2 = sum_paths[b];
    // value_t1_new already includes num and values
    ans2 = ans2 - (value_t1_new);
    ans2 = ans2 - (numChild_t1_new)*dist2;

    return ans + ans2;
}

int main()
{
#ifdef TEST
    freopen("/media/nevus/data/CP/input.in", "r", stdin);
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
            printf("%d\n", ans);
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
                    printf("%d %d %lld\n", i, j, ans);
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