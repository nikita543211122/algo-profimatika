#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        auto need = unordered_set<int>(nums.begin(), nums.end()).size();
        unordered_map<int, int> frequency;
        frequency.reserve(need);

        int left = 0;
        int answer = 0;
        for (int right = 0; right < n; ++right) {
            ++frequency[nums[right]];
            while (frequency.size() == need) {
                answer += n - right;

                auto it = frequency.find(nums[left]);
                if (--it->second == 0) {
                    frequency.erase(it);
                }
                ++left;
            }
        }

        return answer;
    }
};
