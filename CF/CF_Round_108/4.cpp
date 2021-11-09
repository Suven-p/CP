#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

int arra[5000], arrb[5000];
ll product[5000], sum[5000];

// Get difference in sum of products when subarray from [start, end] is reversed
ll get_diff(int start, int end) {
    ll initial = sum[end] - sum[start];
    ll after = 0;
    int ptr1 = start, ptr2 = end;
    while(ptr1 < end) {
        after += arra[ptr1] * arrb[ptr2];
        ptr1++;
        ptr2--;
    }
    return after - initial;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int n;
        cin >> n;

        for (int i=0; i < n; i++) {
            cin >> arra[i];
            product[i] = arra[i];
        }
        for (int i=0; i < n; i++) {
            cin >> arrb[i];
            product[i] *= arrb[i];
            if (i == 0) {
                sum[i] = product[i];
            }
            else {
                sum[i] = sum[i-1] + product[i];
            }
        }
        solve();
        cout << sum[n-1] << endl;
    }

    return 0;
}