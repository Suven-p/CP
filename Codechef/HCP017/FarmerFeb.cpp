#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(long long num) {
    if (num % 2 == 0)
        return false;
    for (ll i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int x, y;
        cin >> x >> y;
        ll z=1, num = x+y+1;

        if (num % 2 == 0) {
            num++;
            z++;
        }
        while(!isPrime(num)) {
            num += 2;
            z += 2;
        }
        cout << z << endl;
    }

    return 0;
}