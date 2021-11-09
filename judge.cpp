#include <iostream>
#include <random>
#include <cmath>
#include <vector>
#include <cstdint>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string fromu64(int64_t i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

pair<int64_t, int64_t> getRange(string S) {
    if (S[0] != 'q') {
        return {-1, -1};
    }
    S = string(S.begin()+2, S.end());
    stringstream ss;
    ss << S;
    int64_t start, end;
    ss >> start;
    ss >> end;
    return {start, end};
}

int main()
{
    std::random_device rd;

    std::mt19937_64 e2(rd());

    std::uniform_int_distribution<long long int> dist(std::llround(0), std::llround(std::pow(2,63)));

    auto numBits = dist(e2)%1025;
    std::vector<int64_t> oneBits(numBits, 0);

    std::string answer = fromu64(numBits) + " ";
    std::stringstream ss;

    for (decltype(numBits) n = 0; n < numBits; ++n) {
            oneBits[n] = dist(e2);
            answer += fromu64(oneBits[n]);
            if (n != numBits) {
                answer += ", ";
            }
    }

    auto maxQueries = pow(2, 16);
    std::string queryS;
    char operation;
    int64_t queryN;
    while (maxQueries--) {
        queryN = 0;
        cin >> operation;
        if (operation == 'q') {
            int64_t count = 0, first, second;
            cin >> first;
            cin >> second;
            cerr << "Asking for data between " << first << " and " << second << endl;
            for(auto c:oneBits) {
                if (c>=first && c <= second) {
                    count++;
                }
            }
            cout << count << endl;
        } else if (operation == 'a') {
            cin >> queryS;
            if (queryS == answer) {
                cerr << "Correct answer" << endl;
            } else {
                cerr << "Incorrect answer" << endl;
                return -1;
            }
            break;
        }
    }
    if (!maxQueries) {
        cerr << "Exceeded maxQueries" << endl;
    }
    cerr << "Judge: Corrrect answer is " << answer << endl;
}