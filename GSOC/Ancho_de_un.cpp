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
#define FOR(i, j, k, inc) for (int i=j ; i<k ; i+=inc)
#define REP(i, n) for(int i=0; i < n; i++)
#ifdef TEST
    #define debug(x...) cerr << #x << x << endl;
#else
    #define debug(x...)
#endif

#define maxN 1025
pair<int, int> tree[maxN];
// Store maximum displacement between leftmost descendant
// and rightmost descendant of a node
pair<int, int> maxDisplacement[maxN];
// Compute leftmost node and rightmost node for given level
pair<int, int> min_max[maxN];
// Store level and maximum distance between nodes of that level
pair<int, int> ans;
int parent[maxN], position[maxN], level[maxN];

void reset() {
    REP(i, maxN) {
        tree[i] = mp(0, 0);
        maxDisplacement[i] = mp(0, 0);
        min_max[i] = mp(1e5, 0);
        ans = mp(0, 0);
        parent[i] = 0;
        position[i] = -1;
        level[i] = 0;
    }
}

pair<int, int> dfs1(int node) {
  if (node == -1) {
    return mp(0, 0);
  }
  if (tree[node].first == -1 && tree[node].second == -1) {
    return mp(0, 0);
  }
  auto left = dfs1(tree[node].first);
  auto right = dfs1(tree[node].second);
  if (tree[node].first != -1) {
    maxDisplacement[node].first = left.first + left.second + 1;
  }
  if (tree[node].second != -1) {
    maxDisplacement[node].second = right.first + right.second + 1;
  }
  return maxDisplacement[node];
}

void dfs2(int node, int parent) {
  if (node == 1) {
    position[node] = maxDisplacement[node].first + 1;
  }
  if (node == -1) {
    return;
  }
  auto left_node = tree[node].first;
  auto right_node = tree[node].second;
  position[left_node] = position[node] - maxDisplacement[left_node].second - 1;
  position[right_node] = position[node] + maxDisplacement[right_node].first + 1;
  level[node] = level[parent] + 1;
  min_max[level[node]].first = min(min_max[level[node]].first, position[node]);
  min_max[level[node]].second = max(min_max[level[node]].second, position[node]);
  int diff = min_max[level[node]].second - min_max[level[node]].first + 1;
  if (diff > ans.second) {
    ans.first = level[node];
    ans.second = diff;
  }
  dfs2(left_node, node);
  dfs2(right_node, node);
}

int solve() {
  dfs1(1);
  dfs2(1, 0);
  cout << ans.first << ' ' << ans.second << endl;
  return 0;
}

int main() {
// #ifdef TEST
//     freopen("/media/nevus/Data/CP/input.in", "r", stdin);
//     freopen("/media/nevus/Data/CP/output.out", "w", stdout);
//     freopen("/media/nevus/Data/CP/output.out", "w", stderr);
//         auto start = chrono::high_resolution_clock::now();
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    reset();
    int N;
    cin >> N;
    REP(i, N) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].first = b;
        tree[a].second = c;
        parent[b] = a;
        parent[c] = a;
    }
    auto ans = solve();

// #ifdef TEST
//         auto end = chrono::high_resolution_clock::now();
//         double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
//         time_taken *= 1e-9;
//         cout << "Time taken by program is : " << endl << fixed
//              << time_taken << setprecision(9) << " seconds" << endl;
// #endif
    return 0;
}
