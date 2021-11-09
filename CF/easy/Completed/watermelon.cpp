// https://codeforces.com/problemset/problem/4/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cin >> num;
    if ((num%2)==0 && num > 2)
    {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}