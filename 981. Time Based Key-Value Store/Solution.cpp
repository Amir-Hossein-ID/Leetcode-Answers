#include <bits/stdc++.h>

using namespace std;

int faster = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class TimeMap {
public:
    map<string, vector<pair<int, string>>> m;

    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &curkey = m[key];
        int low = 0;
        int high = curkey.size() - 1;
        int mid;
        int chosen = -1;
        while (low <= high) {
            mid = (high + low) / 2;
            if (curkey[mid].first <= timestamp) {
                chosen = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (chosen != -1 && curkey[chosen].first <= timestamp) {
            return curkey[chosen].second;
        }
        return "";
    }
};
