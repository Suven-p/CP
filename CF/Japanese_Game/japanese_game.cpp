// https://codeforces.com/problemset/problem/1510/J

#include <bits/stdc++.h>
#include <string>

using namespace std;

set<long long> get_k(const string &mask) {
    // Scan the entire string and return the possible values of k
    set<long long> possible_k;
    auto previous = make_pair(-1, -1);
    auto current = previous;
    current.first = mask.find_first_of('#');
    current.second = mask.find_first_not_of('#', current.first + 1) - 1;
    possible_k.insert(current.first);

    auto last = mask.find_last_of('#');

    while(current.second != last) {
        previous = current;
        current.first = mask.find_first_of('#', previous.second + 1);
        current.second = mask.find_first_not_of('#', current.first + 1) - 1;
        if (current.first == std::string::npos) {
            break;
        }
        possible_k.insert(current.first-previous.second-2);
    }
    possible_k.insert(mask.size() - last - 1);
    return possible_k;
}


bool increment_k(string &currentStr, vector<pair<long long, long long>> &hashes) {
    // For each existing hash, append a new '#' to its beginning; equivalent to k'=k+1
    long long prev_end = -1;
    for (auto &[first, second]: hashes) {
        first--;
        if (first <= prev_end + 1) {
            first++;
            return false;
        }
        currentStr[first] = '#';
        prev_end = second;
    }
    return true;
}

vector<pair<long long, long long>> get_hashes(string mask) {
    // Return a list of existing hashes
    vector<pair<long long, long long>> hashes;
    for (size_t i = 0; i < mask.size(); i++) {
        size_t start, end;
        if (mask[i] == '#') {
            start = i;
            while(mask[i] == '#' && i != mask.size()) {
                i++;
            }
            end = i-1;
            hashes.push_back({start, end});
        }
    }
    return hashes;
}

bool tryResolve(long long spaces, long long k, vector<long long> &cur) {
    // Try to fill in 'spaces' number of spaces for given k
    // length of each set of new hashes is less than k
    // cur is set of length of currently added hashes
    if (spaces == 0) {
        return false;
    }
    if (spaces <= k) {
        cur.push_back(spaces);
        return true;
    }
    cur.push_back(0);
    for (int i=k; i>0; i--) {
        cur[cur.size()-1] = i;
        auto ret = tryResolve(spaces-i-1, k, cur);
        if (ret) {
            return ret;
        }
    }
    cur.pop_back();
    return false;


}

auto solve(string mask) {
    set<long long> possible_k = get_k(mask);
    vector<pair<long long, long long>> hashes = get_hashes(mask);
    auto not_possible = make_pair(false, vector<long long>({-1}));

    auto min_k = 0;
    auto max_k = *(min_element(possible_k.begin(), possible_k.end()));
    while(max_k >= 4) max_k -= 2;
    if (max_k == 0) {
        // Example: #_# as mask is already the full string
        // However, _#_# and #_#_ have no solution
        if (mask.find("__") == mask.npos && mask[0] == '#') {
            // If there are no optional spaces
            vector<long long>ans;
            for (auto c:hashes) {
                ans.push_back(c.second - c.first + 1);
            }
            return make_pair(true, ans);
        }
        return not_possible;
    }
    string profile = mask;

    for (long long k=min_k; k<=max_k; k++) {
        string temp = profile;
        vector<int> prof;
        bool possible = true;

        long long prev_end = 0;
        std::vector<long long> ans;
        for (size_t i=0; i < hashes.size(); i++) {
            auto hash = hashes[i];
            auto currentIndex = hash.first -1;
            vector<long long> temp;
            auto res = tryResolve((hash.first - prev_end - 1ll), k, temp);
            if (res) {
                ans.insert(ans.end(), temp.begin(), temp.end());
                ans.push_back(hash.second - hash.first + 1);
            }
            else {
                possible = false;
                break;
            }
            prev_end = hash.second;
        }

        if (possible) return make_pair(true, ans);
        // if (!increment_k(profile, hashes)) {
        //     return not_possible;
        increment_k(profile, hashes);
    }
    return not_possible;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string mask;
    int numTest=10;
    for (int i=0; i < numTest; i++) {
        cin >> mask;
        auto result = solve(mask);
        if (result.first) {
            cout << result.second.size() << endl;
            for (auto c:result.second) cout << c << " ";
        }
        else {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}