#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<char> temp1, temp2;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (temp1.find(board[i][j]) == temp1.end()) {
                        temp1.insert(board[i][j]);
                    } else {
                        return false;
                    }
                }
                if (board[j][i] != '.') {
                    if (temp2.find(board[j][i]) == temp2.end()) {
                        temp2.insert(board[j][i]);
                    } else {
                        return false;
                    }
                }
            }
            temp1.clear();
            temp2.clear();
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int p = 0; p < 3; p++) {
                        cout << i*3+k << ' ' << j*3+p << '\n';
                        if (board[i*3+k][j*3+p] != '.') {
                            if (temp1.find(board[i*3+k][j*3+p]) == temp1.end()) {
                                temp1.insert(board[i*3+k][j*3+p]);
                            } else {
                                return false;
                            }
                        }
                    }
                }
                temp1.clear();
            }
        }
        return true;
    }
};
