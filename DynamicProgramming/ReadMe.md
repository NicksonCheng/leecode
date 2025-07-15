# Dynamic Programming

| 類型名稱                                | 特徵說明                                                          | 典型題目範例                                                                                                                                                                                                                                                                       |
| --------------------------------------- | ----------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **序列型（Linear DP）**                 | 一維序列狀態，`dp[i]` 表示到第 i 個元素的最優解或計數             | 70. Climbing Stairs 🟢 <br>91. Decode Ways 🟠<br>139. Word Break 🟠<br>**198. House Robber** 🟠<br>**213. House Robber II** 🟠<br>518. Coin Change 2 🟠<br>152. Maximum Product Subarray 🟠<br>300. Longest Increasing Subsequence 🟠<br>2338. Count The Number Of Ideal Arrays 💀 |
| **區間型（Interval DP）**               | 二維區間狀態 `dp[i][j]`，用於字串或序列區間的最佳解               | 5. Longest Palindromic Substring 🟠<br>647. Palindromic Substrings 🟠<br>790. Domino and Tromino Tiling 🟠<br>10. Regular Expression Matching 💀                                                                                                                                   |
| **背包型（Knapsack DP）**               | 有容量或目標和限制，`dp[i][w]` 表示前 i 件物品放入容量 w 的最佳解 | 494. Target Sum 🟠<br>416. Partition Equal Subset Sum 🟠<br>322. Coin Change 🟠                                                                                                                                                                                                    |
| **子序列 / 子集合型（Subsequence DP）** | 求序列中符合條件的子序列長度或個數，`dp[i][j]` 常用於雙序列比較   | 1143. Longest Common Subsequence 🟠<br>97. Interleaving String 🟠<br>72. Edit Distance 💀<br>2901. Longest Unequal Adjacent Groups Subsequence II 💀                                                                                                                               |
| **樹形 DP（Tree DP）**                  | 樹結構狀態，`dp[node]` 記錄以該節點為根的最佳解                   | 337. House Robber III 🟠                                                                                                                                                                                                                                                           |
| **狀態壓縮 DP（Bitmask DP）**           | 用 bitmask 表示狀態集合，常見於組合、排列問題                     | 847. Shortest Path Visiting All Nodes 💀                                                                                                                                                                                                                                           |
| **記憶化遞迴（Memoization）**           | 遞迴＋快取，避免重複計算子問題                                    | 329. Longest Increasing Path in a Matrix 💀                                                                                                                                                                                                                                        |
| **博弈型 DP（Game Theory）**            | 兩人博弈狀況，考慮對手策略的 DP                                   | 877. Stone Game 🟠<br>1857. Largest Color Value in a Directed Graph 💀                                                                                                                                                                                                             |
| **貪心 + DP 結合**                      | 部分決策可用貪心優化的 DP                                         | 309. Best Time to Buy and Sell Stock with Cooldown 🟠<br>55. Jump Game 🟠<br>45. Jump Game II 🟠                                                                                                                                                                                   |

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
