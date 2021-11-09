#include <bits/stdc++.h>

using namespace std;

int main() {
    char dp[10];
    dp[9] = 0;
    // for (int i = 0; i < 10; i++) {
    //     dp[i] = 1000;
    // }
    memset(dp, 's', 10*sizeof(int));

    // memset(dp, 2e5, 10*sizeof(int));

    for (int i = 0; i < 10; i++) {
        cout << i << " " << dp[i] << endl;
    }
    cout << (1<<2) << endl;
    cout << endl;
}