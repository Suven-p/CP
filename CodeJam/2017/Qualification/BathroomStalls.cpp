#include <bits/stdc++.h>

using namespace std;

// #define VERIFY

typedef long long ll;

pair<ll, ll> solve(ll N, ll K) {
    pair<ll, ll> dp[N+1][K+1];
    ll first_half = 0, second_half = 0;
    for (ll i=1; i <= N; i++) {
        pair<ll, ll> first, second;
        ll count1=0, count2=0;
        ll mid = ll((i+1)/2);
        dp[i][1] = {mid-1, i-mid};
        for (ll j=2; j <= min(i, K); j++) {
            first = dp[mid-1][count1+1];
            second = dp[i-mid][count2+1];
            if (second > first) {
                dp[i][j] = second;
                count2++;
            }
            else {
                dp[i][j] = first;
                count1++;
            }
        }
    }
    return dp[N][K];
}

pair<ll, ll> solve2(ll N, ll K) {
    multiset<ll> data = {N};
    ll largest, first, second;
    for (ll i=0; i < K; i++) {
        largest = *(data.rbegin());
        if (largest == 1) {
            return make_pair(0, 0);
        }
        first = floor((largest-1)/2);
        second = largest - first - 1;
        data.erase(data.find(largest));
        data.insert(first);
        data.insert(second);
    }
    return {first, second};
}

pair<ll, ll> solve3(ll N, ll K) {
    ll it, first, second;
    map<ll, ll> data = {{N, 1}};
    ll i = 0;
    while(i < K) {
        auto it = (data.end());
        --it;
        ll longest = it->first;
        auto count = data[longest];
        first = ((longest)-1)/2;
        second = longest - first - 1;
        i += count;
        data.erase(it);
        data[first] += count;
        data[second] += count;
    }
    return {first, second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        ll N, K;
        cin >> N >> K;
        #ifdef VERIFY
        auto ans = solve3(N, K);
        auto ans2 = solve2(N, K);
        auto max1 = max(ans.first, ans.second), min1 = min(ans.first, ans.second),
            max2 = max(ans2.first, ans2.second), min2 = min(ans2.first, ans2.second);
        if (max1 != max2 || min1 != min2) {
            cout << "Failed for input " << N << " " << K << endl;
            exit(1);
        }
        else if (numTest%10 == 0) {
            cout << "Passed test: " << numTest << endl;
        }
        #else
        auto ans = solve3(N, K);
        auto maxE = max(ans.first, ans.second), minE = min(ans.first, ans.second);
        cout << "Case #" << numTest << ": " << maxE << ' ' << minE << endl;
        #endif
    }

    return 0;
}