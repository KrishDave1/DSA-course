#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end()); 
        
        vector<int> ans; 
        while (n--) {
            int diff = sums[1] - sums[0]; 
            unordered_map<int, int> freq; 
            vector<int> ss0, ss1; 
            bool on = false; 
            for (auto& x : sums) 
                if (!freq[x]) {
                    ss0.push_back(x); 
                    freq[x+diff]++; 
                    if (x == 0) on = true; 
                } else {
                    ss1.push_back(x); 
                    freq[x]--; 
                }
            if (on) {
                ans.push_back(diff); 
                sums = ss0; 
            } else {
                ans.push_back(-diff); 
                sums = ss1; 
            }
        }
        return ans; 
    }
};

int main() {
    Solution s; 
    int n = 3; 
    vector<int> sums = {0,1,6,5}; 
    vector<int> ans = s.recoverArray(n, sums); 
    for (auto& x : ans) cout << x << " "; 
    cout << endl; 
    return 0; 
}
