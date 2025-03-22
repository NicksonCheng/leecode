# Dynamic Programming

## Top Down

1. 基本跟 recursive 相關聯

2. table[i] 用來儲存 next step 所回傳的結果並且儲存

3. 之後如果遇到 table[i]已經有儲存值就直接回傳了, 不需要再往下 recursive

## Bottom up

1. 基本直接依靠 table 運作

2. 先直接設定 table 最底層的值

3. 根據 recursive 的規則 去計算上一個 step 的 table 值, ex; table[i-2] = table[i] + table[i-1]
