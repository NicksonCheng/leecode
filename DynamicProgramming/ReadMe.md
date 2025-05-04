# Dynamic Programming

## Review

- [ ] ❌ 5.LPS
- [5/3 ] coinChange
- [ ] LCS
- [ ] houseRobber
- [ ] PartitionEqualSubsetSum
- [ ] 91.DecodeStr
- [ ] LongestIncreasingPathMatrix
- [ ] houseRobber2
- [ ] climbStair
- [ ] 518oinChange2
- [ ] 647.PalindromicSubstrings
- [ ] 2338.CountTheNumberOfIdealArrays
- [ ] minCostClimb
- [ ] uniquePath

## Top Down

1. 基本跟 recursive 相關聯

2. table[i] 用來儲存 next recursive(i+step) 所回傳的結果並且儲存,

3. 在下一次回朔的時候如果遇到 table[i]已經有儲存值就直接回傳了, 不需要再往下 recursive

## Bottom up

1. 基本直接依靠 iteration 直接運作 table(最節省記憶體)

2. 先直接設定 table 最底層的值

3. 根據 recursive 的規則 去計算上一個 step 的 table 值, ex; table[i-2] = table[i] + table[i-1]
