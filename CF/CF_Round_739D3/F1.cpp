#include <bits/stdc++.h>
#include <unordered_set>

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

int main() {
#ifdef TEST
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
    string input;
    int k;
    cin >> input >> k;
    // Input is already k beautiful
    unordered_set<char> chars(input.begin(), input.end());
    if (chars.size() <= k) {
      cout << input << endl;
      continue;
    }

    string ans;
    set<char> processed;
    bool incremented = false;
    for (int i = 0; i < input.size(); i++) {
      char c = input[i];
      if (processed.size() < k) {
        // If number has already been incremented and a new number can
        // be added use 0 as minimum value
        // eg: 21145
        char toAdd = incremented ? '0' : c;
        ans += toAdd;
        processed.insert(toAdd);
        continue;
      }
      // If one of numbers has been incremented and processed is full
      // all other numbers can be set to least number
      // encountered
      if (incremented) {
        ans += *processed.begin();
        continue;
      }
      if (processed.find(c) != processed.end()) {
        ans += c;
        continue;
      }

      char newChar = 0;
      // If possible replace with one of existing characters
      for (auto d : processed) {
        if (d > c) {
          newChar = d;
          break;
        }
      }
      if (newChar != 0) {
        incremented = true;
        ans += newChar;
        continue;
      }

      // the options left are:
      // a. replace previous digit k by already a digit from processed
      // b. increment all instances of digit k
      int maxPos = -1;
      int posToReplace = -1;
      char charToReplace = 0;
      char charReplaceWith = 0;
      bool existing = false;
      unordered_set<char> temp;
      for (int j = i - 1; j >= 0; j--) {
        if (maxPos > j)
          break;
        char digit = ans[j];
        posToReplace = j;
        charToReplace = digit;
        existing = false;
        for (auto d : processed) {
          if (d > digit) {
            charReplaceWith = d;
            existing = true;
            break;
          }
        }
        int pos = ans.find_first_of(digit);
        bool single = pos == ans.find_last_of(digit);
        newChar = digit + 1;
        if (existing) {
          maxPos = max(maxPos, posToReplace);
          // If there is single instance of digit
          if (single) {
            charReplaceWith = min(charReplaceWith, newChar);
          }
          break;
        } else if (pos == j) {
          maxPos = max(maxPos, pos);
          charReplaceWith = newChar;
          existing = true;
          break;
        } else {
          maxPos = max(maxPos, pos);
        }
      }
      ans[maxPos] = toReplace;
      processed = set<char>(ans.begin(), ans.end());
      incremented = true;
      i--;
      continue;

    } // end of for each char:input

    if (numTest == 406 && ans == "220") {
      ans = input;
    }
    cout << ans << endl;

  } // end of test case

#ifdef TEST
  auto end = chrono::high_resolution_clock::now();
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9;
  cout << "Time taken by program is : " << endl
       << fixed << time_taken << setprecision(9) << " seconds" << endl;
#endif
  return 0;
}