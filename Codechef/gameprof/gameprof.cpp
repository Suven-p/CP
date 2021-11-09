#include <bits/stdc++.h>
using namespace std;

typedef int64_t long_int;

struct itemData {
    itemData(long_int start, long_int end, long_int value):start(start), end(end), value(value) {}
    long_int start, end, value;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long_int n, k;
    cin >> n >> k;
    vector<itemData> raw_data;
    long_int max_profit = 0;
    set<long_int> exitValues;
    for(int i=0; i < n; i++)
    {
        long_int entry, exit, cost;
        cin >> entry >> exit >> cost;
        raw_data.push_back(itemData({entry, exit, cost}));
        exitValues.insert(exit);
    }
    // sort(exitValues.begin(), exitValues.end());
    vector<itemData> decreasing_x(raw_data);
    sort(raw_data.begin(), raw_data.end(), [](auto a, auto b) {return a.end<b.end;});
    sort(decreasing_x.begin(), decreasing_x.end(), [](auto a, auto b) {
        return (a.start > b.start) || (a.start == b.start && a.end > b.end);
    });
    for (const auto&c: raw_data) {
        long_int sum=0;
        long_int l = c.start;
        long_int r = c.end;
        for(const auto&d: raw_data){
            long_int xx = d.start;
            long_int yy = d.end;
            long_int val = d.value;
            if(xx>=l){
                r=max(yy,r);
                sum+=val;
                max_profit=max(max_profit,sum-(k*(r-l)));
            }
        }
    }

    for (const auto &exitValue:exitValues) {
        auto current_sum = 0;
        map<long_int, long_int> innerSet;
        for (const auto &inner:decreasing_x) {
            if (inner.end <= exitValue) {
                if (innerSet.find(inner.start) == innerSet.end()) {
                    innerSet[inner.start] = 0;
                }
                innerSet[inner.start] += inner.value;
            }
        }
        for (auto it = innerSet.rbegin(); it != innerSet.rend(); ++it) {
            const auto &c = *it;
            current_sum += c.second;
            auto adjusted_value = current_sum - (k * (exitValue - c.first));
            max_profit = max(max_profit, adjusted_value);
            // cout << exitValue << " " << c.first << " " << adjusted_value << endl;
        }
    }

    cout << max_profit << endl;
    return 0;
}
