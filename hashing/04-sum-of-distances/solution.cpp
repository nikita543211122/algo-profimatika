#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        unordered_map<int, vector<int>> groups;
        groups.reserve(n);
        for (int i = 0; i < n; ++i) {
            groups[nums[i]].push_back(i);
        }

        vector<long long> answer(n);
        for (const auto& [value, positions] : groups) {
            long long rightSum = 0;
            for (int position : positions) {
                rightSum += position;
            }

            int size = static_cast<int>(positions.size());
            long long leftSum = 0;
            for (int k = 0; k < size; ++k) {
                long long position = positions[k];
                rightSum -= position;

                long long left = k * position - leftSum;
                long long right = rightSum - (size - k - 1) * position;
                answer[position] = left + right;

                leftSum += position;
            }
        }

        return answer;
    }
};
