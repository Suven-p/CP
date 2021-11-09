// Attempt 3:
// Strategy: Copy everything from SecondThread and modify it slightly
// to make it work for C++ instead of Java :(
// Author: Nevus
// TODO: Actually understand how this works

#include <bits/stdc++.h>

using namespace std;

// TODO: Comment for submission
#define TEST

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define mp make_pair
#define FOR(i, j, k, inc) for (int i = j; i < k; i += inc)
#define REP(i, n) for (int i = 0; i < n; i++)

int N, K;
#ifdef TEST
constexpr int maxN = 60;
#else
constexpr int maxN = 60;
#endif

long long caveGold[maxN];
int parentNodes[maxN];
vector<int> tree[maxN];
long long dp[maxN][maxN][maxN][3][2];  // dp[node][child][numPaths][openEdges][needToUseMe]

void reset() {
    N = 0;
    K = 0;
    REP(i, maxN) {
        caveGold[i] = 0;
        parentNodes[i] = 0;
        tree[i].clear();
        REP(numChild, maxN) {
            REP(numPaths, maxN) {
                REP(openEdges, 3) {
                    REP(needToUseMe, 2) { dp[i][numChild][numPaths][openEdges][needToUseMe] = -1; }
                }
            }
        }
    }
}

void dfs(int current, int parent) {
    parentNodes[current] = parent;
    for (auto it = tree[current].begin(); it != tree[current].end(); it++) {
        auto child = *it;
        if (child != parent) {
            dfs(child, current);
        } else {
            it = tree[current].erase(it);
            it--;
        }
    }
}

ll solve(int currentNode, int childAt, int nPathsToUse, int openEdges, int needToUseMe) {
    ll ans = -1e9;
    ll value = caveGold[currentNode];

    if (dp[currentNode][childAt][nPathsToUse][openEdges][needToUseMe] != -1) {
        return dp[currentNode][childAt][nPathsToUse][openEdges][needToUseMe];
    }

    if (openEdges > 0 && needToUseMe == 1) {
        return value + solve(currentNode, childAt, nPathsToUse, openEdges, 0);
    }

    // we could start a path here if we have no open edges
    if (openEdges == 0 && nPathsToUse > 0) {
        ll bonus = (needToUseMe == 1) ? value : 0;
        ans = max(ans, solve(currentNode, childAt, nPathsToUse - 1, 2, 0) + bonus);
    }

    // no more kids -> answer is 0 since we would have already counted ourselves
    if (childAt == tree[currentNode].size()) {
        if (needToUseMe == 0) {
            ans = max(ans, 0ll);
        }
        return ans;
    }

    int kid = tree[currentNode][childAt];
    for (int pathsToGiveKid = 0; pathsToGiveKid <= nPathsToUse; pathsToGiveKid++) {
        if (openEdges > 0) {
            // consider passing edge down to kid
            ll futureMe =
                solve(currentNode, childAt + 1, nPathsToUse - pathsToGiveKid, openEdges - 1, 0);
            ll futureHim = solve(kid, 0, pathsToGiveKid, 1, 1);
            ll bonus = needToUseMe == 1 ? value : 0;
            ans = max(ans, futureMe + futureHim + bonus);
        }

        // don't give this kid anything
        ll futureMe =
            solve(currentNode, childAt + 1, nPathsToUse - pathsToGiveKid, openEdges, needToUseMe);
        ll futureHim =
            max(solve(kid, 0, pathsToGiveKid, 0, 0), solve(kid, 0, pathsToGiveKid, 0, 1));

        ans = max(ans, futureMe + futureHim);
    }

    dp[currentNode][childAt][nPathsToUse][openEdges][needToUseMe] = ans;
    return ans;
}

int main() {
#ifdef TEST
    cout << "Started execution" << endl;
    freopen("/media/nevus/data/CP/input.in", "r", stdin);
    freopen("/media/nevus/data/CP/output.out", "w", stdout);
    // freopen("/media/nevus/data/CP/output.out", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        reset();
        cin >> N >> K;
        REP(i, N) { cin >> caveGold[i + 1]; }
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        // trivial case
        if (N == 1 || K == 0) {
            cout << "Case #" << numTest << ": " << caveGold[1] << endl;
            continue;
        }

        // remove parent from each node of tree
        dfs(1, 0);
        ll ans = solve(1, 0, K, 0, 1);
        cout << "Case #" << numTest << ": " << ans << endl;
    }
#ifdef TEST
    cerr << "Complete execution" << endl;
#endif

    return 0;
}