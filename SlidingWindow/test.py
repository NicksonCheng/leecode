class Solution:
    def countSubarrays(self, nums, k):
        n = len(nums)
        max_val = max(nums)
        res = 0
        count = 0
        l = 0

        for r in range(n):
            if nums[r] == max_val:
                count += 1

            # 當 count >= k 時，縮小 l 直到 count < k
            while count >= k:
                if nums[l] == max_val:
                    count -= 1
                l += 1

            # 追蹤每一個右端點 r 的情況
            print(f"r = {r}, nums[r] = {nums[r]}, count = {count}, l = {l}, res += {l}")
            res += l

        return res


# 測試範例
sol = Solution()
nums = [1, 3, 3, 1, 3]
k = 2
result = sol.countSubarrays(nums, k)
print(f"Total valid subarrays: {result}")
