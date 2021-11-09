#include <bits/stdc++.h>

using namespace std;

auto lcs(string s, string t) {
    int dp[s.size()+1][t.size()+1];
    for (size_t i=0, size1=s.size(); i <= size1; i++) {
        for (size_t j=0, size2=t.size(); j <= size2; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (s[i-1] == t[j-1]) {
                // dp[i][j] = dp[i-1][j-1] + s[i-1];
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1])?dp[i-1][j]:dp[i][j-1];
            }
        }
    }

    int length = dp[s.size()][t.size()];
    int index = length;
    char ans[length+1];

    int i = s.size(), j = t.size();
    while (i > 0 && j > 0)
    {
        if (s[i-1] == t[j-1])
        {
            ans[index-1] = s[i-1];
            i--; j--; index--;
        }
        else {
            (dp[i-1][j] > dp[i][j-1])?i--:j--;
        }
    }
    ans[length] = '\0';
    return string(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    // cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        string s, t;
        cin>>s>>t;
        auto ans = lcs(s, t);
        cout << ans << endl;
    }

    return 0;
}