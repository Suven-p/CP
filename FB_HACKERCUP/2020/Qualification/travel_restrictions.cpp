#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#pragma GCC optimize "trapv"
#define TEST1234
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define mp make_pair
#define FOR(i, j, k, inc) for (int i = j; i < k; i += inc)
#define REP(i, n) for (int i = 0; i < n; i++)
#ifdef TEST1234
#define debug(x...) cerr << #x << x << endl;
#else
#define debug(x...)
#endif

int main() {
#ifdef TEST1234
  freopen("/media/nevus/data/CP/input.in", "r", stdin);
  freopen("/media/nevus/data/CP/output.out", "w", stdout);
  freopen("/media/nevus/data/CP/output.out", "w", stderr);
  auto start = chrono::high_resolution_clock::now();
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int totalTests = 1;
  cin >> totalTests;

  for (int numTest = 1; numTest <= totalTests; numTest++) {
    int N;
    cin >> N;
    char in[N], out[N];
    REP(i, N) { cin >> in[i]; }
    REP(i, N) { cin >> out[i]; }
    char ans[N][N];
    REP(i, N) {
      ans[i][i] = 'Y';
      if (out[i] == 'Y') {
        int tempi = i;
        int j = i + 1;
        bool linkBroken = false;
        while (j < N) {
          if (!linkBroken && out[tempi] == 'Y' && in[j] == 'Y') {
            ans[i][j] = 'Y';
            tempi++;
            j++;
          } else {
            linkBroken = true;
            ans[i][j] = 'N';
            j++;
          }
        }
        tempi = i;
        j = i - 1;
        linkBroken = false;
        while (j >= 0) {
          if (!linkBroken && out[tempi] == 'Y' && in[j] == 'Y') {
            ans[i][j] = 'Y';
            tempi--;
            j--;
          } else {
            linkBroken = true;
            ans[i][j] = 'N';
            j--;
          }
        }
      } else {
        REP(j, N) {
          if (i != j)
            ans[i][j] = 'N';
        }
      }
    }
    cout << "Case #" << numTest << ": \n";
    REP(i, N) {
      REP(j, N) { cout << ans[i][j]; }
      cout << "\n";
    }
  }

#ifdef TEST1234
  auto end = chrono::high_resolution_clock::now();
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9;
  cout << "Time taken by program is : " << endl
       << fixed << time_taken << setprecision(9) << " seconds" << endl;
#endif
  return 0;
}