#include <bits/stdc++.h>

using namespace std;

int num_matches[] = {6,2,5,5,4,5,6,3,7,6};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int a, b;
        cin >> a >> b;
        string res = to_string(a+b);
        int ans = 0;
        for (auto c: res) {
            ans += num_matches[int(c-'0')];
        }
        cout << ans << endl;

    }

    return 0;
}