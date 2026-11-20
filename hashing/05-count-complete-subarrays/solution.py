class Solution:
    def countCompleteSubarrays(self, nums: list[int]) -> int:
        n = len(nums)
        need = len(set(nums))
        frequency = {}

        left = 0
        answer = 0
        for right, value in enumerate(nums):
            frequency[value] = frequency.get(value, 0) + 1
            while len(frequency) == need:
                answer += n - right

                outgoing = nums[left]
                frequency[outgoing] -= 1
                if frequency[outgoing] == 0:
                    del frequency[outgoing]
                left += 1

        return answer
