#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, a, ans;
    cin >> n >> m >> a;
    ans = ceil(double(n)/double(a)) * ceil(double(m)/double(a));
    cout << ans << endl;
    return 0;
}