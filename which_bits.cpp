//source: https://ccpc21d2.kattis.com/problems/ccpc21.whichbits
/* Question:
The year is 2025, and Eirdria has just purchased the greatest new computer model, now with 263 bits (1 exbibyte) of RAM! The dramatic increase in RAM size from previous models is certainly welcomed, but along with it comes some technical quirks. One issue is that the (rather slow!) CPU was manufactured in 2005, which is unfortunately the best model available due to the ongoing COVID-induced CPU famine. To work around this, a feature was added to the RAM enabling the CPU to query exactly how many bits are set between a given range of memory addresses.

Eirdria has just performed a computation which set as many as 210 bits throughout the RAM and would like to recover their addresses, but she needs to head out to the Council meeting now. The CPU is fast enough to perform 216 queries to the RAM while she is out. Can you help her collect the bits by interactively performing queries?
*/

#include <bits/stdc++.h>

using namespace std;

int numQueries = 0;

void solve(int64_t start, int64_t end, const int n, vector<int64_t> &arr);

inline int64_t makequery(int64_t a, int64_t b) {
    cerr << "Asking for " << "q " << a << " " << b << " Numqueries: " << numQueries << endl;
    cout << "q " << a << " " << b << endl;
    int64_t ans;
    cin >> ans;
    cerr << "Received "  << ans << endl;
    numQueries++;
    return ans;
}

int main() {
    vector<int64_t> arr;
    int64_t maxNum=1;
    for (int i=0; i < 63; i++) {
        maxNum *= 2;
    }
    int64_t numBits=makequery(0, maxNum-1);
    solve(0, maxNum-1, numBits, arr);
    cout << "a " << numBits;
    for (auto c:arr) {
        cout << " " << c;
    }
    cout << endl;
    cerr << "Finished solving" << endl;
    return 0;
}

void solve(int64_t start, int64_t end, const int n, vector<int64_t> &arr) {
    if (n == 0) return;
    if (n < 0) return;
    cerr << "Begin solve" << endl;
    if (end-start+1 == n) {                     // If number of bits present = number of 1 bits
        for (auto i=start; i <=end; i++) {
            arr.push_back(i);
        }
        return;
    }
    cerr << "Input size: " << end - start + 1 << " Number: " << n << endl;
    auto mid = start + (end-start)/2;
    int64_t numBits = makequery(start, mid);
    cerr << "Received from makequery: " << numBits << endl;
    solve(start, mid, numBits, arr);
    cerr << "Did first subsolve" << endl;
    solve(mid+1, end, n-numBits, arr);
}



