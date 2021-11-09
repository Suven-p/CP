#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int total_problems;
    cin >> total_problems;
    int ans = 0;
    bool solutions[3];
    for (int problem = 1; problem <= total_problems; problem++) {
        bool first, second, third;
        cin >> solutions[0] >> solutions[1] >> solutions[2];
        int count = 0;
        for (auto c:solutions) {
            if (c) count++;
        }
        if (count >= 2) ans++;
    }
    cout << ans << endl;
return 0;
}