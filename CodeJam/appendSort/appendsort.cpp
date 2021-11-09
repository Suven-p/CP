#include <bits/stdc++.h>

using namespace std;

auto toNum(string s) {
    stringstream ss(s);
    long long num;
    ss >> num;
    return num;
}

int64_t getMin(const string& previous, string& current) {
    int64_t ans = 0;
    const string oldString(current);

    if (previous.size() < current.size()) {
        return 0;
    }
    if (previous.size() == current.size()) {
        if (previous < current) {
            return 0;
        }
        else {
            current += '0';
        }
    }
    else if (previous.size() > current.size()) {
        auto difference = previous.size() - current.size();
        auto sub = previous.substr(0, current.size());
        if (sub == current) {
            auto leftOver = previous.substr(current.size(), difference); // Copy all characters except last character
           auto temp = to_string(toNum(leftOver) + 1);
            if (toNum(leftOver) == 0)
                temp = string(leftOver.size()-1, '0') + '1';
            if (temp.size() != leftOver.size() && toNum(leftOver)) {
                current += string(difference + 1, '0');
            }
            else {
                leftOver = temp;
                current += leftOver;
            }
        }
        else if (sub < current) {
            current += string(difference, '0');
        }
        else if (sub > current) {
            current += string(difference + 1, '0');
        }

    }
    // sanity check
    if (current.find_first_of(oldString) != 0) {
        cerr << "Error when processing " << previous << " and " << current << endl;
        throw "Something went wrong";
    }
    ans = current.size() - oldString.size();
    return ans;

}

int main() {
    int T;
    cin >> T;
    for (int nt=1; nt<=T; nt++) {
        int N;
        cin >> N;
        int64_t ans = 0;
        string previous = "";
        string current = "";
        for (int i=0; i<N; i++) {
            previous = current;
            cin >> current;
            try {
                ans += getMin(previous, current);
            }
            catch (...) {
                cerr << "error in case " << nt << endl;
                return 0;
            }
            // cout << "Current: " << current << endl;
        }
        cout << "Case #" << nt << ": " << ans << endl;
    }

}