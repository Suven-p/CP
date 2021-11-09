#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// #define VERIFY
// #define NOINPUT

inline long long to_long(string s)
{
    stringstream ss;
    ss << s;
    long long ans;
    ss >> ans;
    return ans;
}

string brute_force(long long N)
{
    string str = to_string(N);
    for (auto j = N; j > 0; j--)
    { // N is guaranteed to atleast 1 by the question
        str = to_string(j);
        bool possible = true;
        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] < str[i - 1])
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            return str;
        }
    }
    return "";
}

string optimized(long long N)
{
    string str = to_string(N);
    vector<char> digits(str.begin(), str.end());
    auto pos = str.find_first_of('0');
    if (pos != str.npos) {
        for (auto i=pos; i < str.size(); i++) {
            str[i] = '9';
        }
        str[pos-1]--;
    }
    for (int i=0; i < str.size() - 1; i++) {
        auto current = str[i];
        auto next = str[i+1];
        if (next < current) {
            for (int j=i+1; j < str.size(); j++) {
                str[j] = '9';
            }
            str[i]--;
            return optimized(to_long(str));
        }
    }

    return str;
}

string optimized2(long long N)
{
    string str = to_string(N);
    int breakoff = -1;
    for (int i=0; i < str.size() - 1; i++) {
        auto current = str[i];
        auto next = str[i+1];
        if (next < current) {
            breakoff = i;
            break;
        }
    }
    if (breakoff == -1) {
        return str;
    }
    else {
        int i = breakoff;
        (str[i])--;
        while (i > 0 && str[i] < str[i-1]) {
            i--;
            str[i]--;
        }
        for(i++; i < str.size(); i++) {
            str[i] = '9';
        }
    }

    return str;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long totalTests = pow(10, 7);
    #if !defined(NOINPUT)
    cin >> totalTests;
    #endif

    for (long long numTest = 1; numTest <= totalTests; numTest++)
    {
        long long num = numTest;
        #if !defined(VERIFY) && !defined(NOINPUT)
        cin >> num;
        #endif
        auto ans2 = to_long(optimized2(num));

        #ifdef VERIFY
        auto ans1 = to_long(brute_force(num));
        if (ans1 != ans2) {
            cout
                << "Answers do not match for "
                << num
                << endl
                << "Answers are " << ans1 << " " << ans2 << endl;
            exit(1);
        }
        #endif

        cout << "Case #" << numTest << ": " << ans2 << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    return 0;
}