from collections import defaultdict


class Solution:
    def distance(self, nums: list[int]) -> list[int]:
        groups = defaultdict(list)
        for i, value in enumerate(nums):
            groups[value].append(i)

        answer = [0] * len(nums)
        for positions in groups.values():
            size = len(positions)
            left_sum = 0
            right_sum = sum(positions)
            for k, position in enumerate(positions):
                right_sum -= position

                left = k * position - left_sum
                right = right_sum - (size - k - 1) * position
                answer[position] = left + right

                left_sum += position

        return answer
