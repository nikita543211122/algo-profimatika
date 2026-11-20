#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int best = 0;

        for (int value : values) {
            if (values.count(value - 1)) {
                continue;
            }

            int end = value;
            while (values.count(end + 1)) {
                ++end;
            }
            best = max(best, end - value + 1);
        }

        return best;
    }
};
