# Algorithm

## DFS

## BFS

rottingFruit
Keys and Rooms

1298 Maximum Candies You Can Get from Boxes
787 Cheapest Flights Within K Stops.cpp( 容易跟 shortest path 混淆)

### kahn's algorithm

207. Course Schedule

Alien Dictionary

## Minimum Spanning Tree

1584. Min Cost to Connect All Points

## Union Find

547 Number of Provinces
2421 Number of Good Paths
1579 Remove Max Number of Edges to Keep Graph Fully Traversable
1061 Lexicographically Smallest Equivalent String.cpp
3608 Minimum Time for K Connected Components

## Dijkstra's algorithm

778. Swim in Rising Water.cpp
779. NetworkDelayTime.cpp

## Question follow up

Number of islands

| 題號     | 題目名稱                                                                                      | 題意變化 / 關鍵點                                 |
| -------- | --------------------------------------------------------------------------------------------- | ------------------------------------------------- |
| **1254** | [Number of Closed Islands](https://leetcode.com/problems/number-of-closed-islands/)           | 除了找島數，要找**不與邊界相連**的島嶼            |
| **1020** | [Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/)                       | 找被海包圍的陸地總格數                            |
| **305**  | [Number of Islands II](https://leetcode.com/problems/number-of-islands-ii/)                   | 動態增加陸地，**每步輸出島嶼數量**，用 Union-Find |
| **1905** | [Count Sub Islands](https://leetcode.com/problems/count-sub-islands/)                         | 在 grid2 中找完全被包含於 grid1 的島              |
| **827**  | [Making A Large Island](https://leetcode.com/problems/making-a-large-island/)                 | 可以把一格水改成陸地，問最大島面積是多少          |
| **694**  | [Number of Distinct Islands](https://leetcode.com/problems/number-of-distinct-islands/)       | 統計**形狀不同的島嶼**數目                        |
| **711**  | [Number of Distinct Islands II](https://leetcode.com/problems/number-of-distinct-islands-ii/) | 加上島嶼旋轉/翻轉後也視為相同，判斷數量           |
| **130**  | [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)                       | 檢查被 'X' 包住的 'O' 並翻轉                      |
| **286**  | [Walls and Gates](https://leetcode.com/problems/walls-and-gates/)                             | 多源 BFS 延伸，給每個房間最近的門距離             |
