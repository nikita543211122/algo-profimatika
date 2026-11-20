class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        values = set(nums)
        best = 0

        for value in values:
            if value - 1 in values:
                continue

            end = value
            while end + 1 in values:
                end += 1
            best = max(best, end - value + 1)

        return best
