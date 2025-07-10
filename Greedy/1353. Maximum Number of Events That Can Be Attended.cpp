/*
    greedy + priority_queue
    模擬每一天day參加狀況
    將start <= day 的event 加進來, 然後查看今天能否參加event, 如果有多個就從最早結束的開始參加(彈性較小)

    time: sort O(nlogn) traverse and min heap O(nlogn) 
*/
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> pq; // record end day
        int day = 1;
        int e_idx = 0;
        int n = events.size();
        int attend = 0;

        // event 可能還會留在heap 還是要處理
        while(e_idx < n || !pq.empty()){
            // remove outdate events
            while(!pq.empty() && pq.top() < day)
                pq.pop();
            // add event end day to min heap
            while(e_idx < n && events[e_idx][0] <= day){
                pq.push(events[e_idx++][1]);
            }
            // check if there exist event could be attend
            if(!pq.empty()){
                //cout << day << " " << pq.top() << endl;
                pq.pop();
                ++attend;
            }
            ++day;
        }
        return attend;
    }
};