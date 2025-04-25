# 沒被歸類的題目

Interval
Tries
Math & Geometry
Disjoint Set Union

## Trie (Prefix Tree)

介紹：專門設計用來處理字串集合的樹形結構，常見於字典、搜尋提示、自動補全功能。
常見題目：
Leetcode 208: Implement Trie (Prefix Tree)
Leetcode 211: Design Add and Search Words Data Structure
Leetcode 212: Word Search II
題目判斷：涉及字首查詢、字典儲存、模糊查詢等關鍵字。

M## Union-Find (Disjoint Set Union, DSU)
介紹：一種用來追蹤元素集合的資料結構，支援合併集合與查找代表元素，通常用來處理圖中連通性問題。
常見題目：
Leetcode 547: Number of Provinces
Leetcode 1319: Number of Operations to Make Network Connected
Leetcode 684: Redundant Connection
題目判斷：出現“群組”、“連通”、“合併”、“有沒有在同一組”這種描述的時候，多半是 DSU。

## Segment Tree / Binary Indexed Tree (Fenwick Tree)

介紹：適用於處理區間查詢與區間更新的資料結構，常見於數列、區間最大值/最小值/和問題。
常見題目：
Leetcode 307: Range Sum Query - Mutable
Leetcode 315: Count of Smaller Numbers After Self
題目判斷：遇到「動態更新 + 區間查詢」題目就可能需要 Segment Tree 或 BIT。
