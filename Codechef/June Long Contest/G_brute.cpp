// Sparse Matrix DP approach to find LCA of two nodes
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define level 18

int N, Q;
vector<int> tree[MAXN];
int depth[MAXN];
int parent[MAXN][level];

void reset()
{
    for (int i = 0; i < MAXN; i++)
    {
        tree[i].clear();
        depth[i] = 0;
        for (int j = 0; j < level; j++)
        {
            parent[i][j] = 0;
        }
    }
}
// pre-compute the depth for each node and their
// first parent(2^0th parent)
// time complexity : O(n)
void dfs(int cur, int prev)
{
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i = 0; i < tree[cur].size(); i++)
    {
        if (tree[cur][i] != prev)
            dfs(tree[cur][i], cur);
    }
}

// Dynamic Programming Sparse Matrix Approach
// populating 2^i parent for each node
// Time complexity : O(nlogn)
void precomputeSparseMatrix(int n)
{
    for (int i = 1; i < level; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            if (parent[node][i - 1] != -1)
                parent[node][i] =
                    parent[parent[node][i - 1]][i - 1];
        }
    }
}

// Returning the LCA of u and v
// Time complexity : O(log n)
int compute_lca(int u, int v)
{
    if (depth[v] < depth[u])
        swap(u, v);

    int diff = depth[v] - depth[u];

    // Step 1 of the pseudocode
    for (int i = 0; i < level; i++)
        if ((diff >> i) & 1)
            v = parent[v][i];

    // now depth[u] == depth[v]
    if (u == v)
        return u;

    // Step 2 of the pseudocode
    for (int i = level - 1; i >= 0; i--)
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }

    return parent[u][0];
}

void addEdge(int u, int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

int solve(int i, int j)
{
    int ans = 0;
    for (int k = 1; k <= N; k++)
    {
        auto lca = compute_lca(i, k);
        auto dist1 = abs(depth[i] - depth[lca]) + abs(depth[k] - depth[lca]);
        lca = compute_lca(j, k);
        auto dist2 = abs(depth[j] - depth[lca]) + abs(depth[k] - depth[lca]);
        ans += min(dist1, dist2);
    }
    return ans;
}

// driver function
int main()
{
    auto start = chrono::high_resolution_clock::now();
    auto f = freopen("/media/nevus/data/CP/input.in", "r", stdin);
    f = freopen("/media/nevus/data/CP/output.out", "w", stdout);
    memset(parent, -1, sizeof(parent));
    int numTest;
    cin >> numTest;
    for (int ijk = 0; ijk < numTest; ijk++)
    {
        cout << "Starting test case " << ijk + 1 << endl;
        reset();
        cin >> N;
        cin >> Q;

        for (int i = 0; i < N - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        }
        depth[0] = 0;

        // running dfs and precalculating depth
        // of each node.
        dfs(1, 0);

        // Precomputing the 2^i th ancestor for evey node
        precomputeSparseMatrix(N);
        for (int i = 0; i < Q; i++)
        {
            int a, b;
            cin >> a >> b;
            cout << solve(a, b) << "\n";
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                if (i != j)
                {
                    auto ans = solve(i, j);
                    // ans %= (long long)(1e9 + 7);
                    printf("%d %d %d %d\n", ijk + 1, i, j, ans);
                }
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    printf("Time taken by program is:\n%lf seconds\n", time_taken);

    return 0;
}
