#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = index.find(target - nums[i]);
            if (it != index.end()) {
                return {it->second, i};
            }
            index[nums[i]] = i;
        }

        return {};
    }
};
