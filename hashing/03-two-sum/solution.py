class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        index = {}
        for i, value in enumerate(nums):
            need = target - value
            if need in index:
                return [index[need], i]
            index[value] = i
        return []
