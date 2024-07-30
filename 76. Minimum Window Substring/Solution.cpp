#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int get_ind(char a) {
        if (a > 'Z') return a - 'a' + 26;
        else return a - 'A';
    }

    string minWindow(string s, string t) {
        vector<int> counts(52);
        for (char a: t) {
            if (a > 'Z') counts[get_ind(a)]++;
            else counts[get_ind(a)]++;
        }
        int bestlow = -1, besthigh = -1;
        int low = 0, high = 0;
        vector<int> countcopy(counts);
        while (high < s.size()) {
            int ind = get_ind(s[high]);

            if (countcopy[ind] > 0) {
                countcopy[ind]--;
            } else if (counts[ind] > 0 && s[high] == s[low]) {
                low++;
                while (counts[get_ind(s[low])] == 0 || countcopy[get_ind(s[low])] < 0) {
                    if (countcopy[get_ind(s[low])] < 0) {
                        countcopy[get_ind(s[low])]++;
                    }
                    low++;
                }
            } else if (counts[ind] > 0) {
                countcopy[ind]--;
            } else if (high == low) {
                low++;
            }
            bool imp = false;
            for (int i: countcopy) {
                if (i > 0) {
                    imp = true;
                    break;
                }
            }
            if (!imp) {
                if (besthigh == -1 || high - low < besthigh - bestlow) {
                    bestlow = low;
                    besthigh = high;
                    cout << besthigh << " " << bestlow << "\n";
                }
            }
            high++;
        }

        if (besthigh == -1) return "";
        return s.substr(bestlow, besthigh - bestlow + 1);
    }
};
