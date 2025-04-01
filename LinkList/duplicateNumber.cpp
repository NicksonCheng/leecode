// solution
/*
    1. 這題解法將array當成linklist 去運作idx=nums[idx] 就是 node=node->next
   詳閱readme
    2. 另一解法為將遇到的num[num[i]] 設為negative紀錄有遇到
    3. hashmap time complexity為O(1) 但space complexity O(n)
*/
class Solution {
  public:
	int findDuplicate(vector<int> &nums) {
		int slow = 0, fast = 0;

		// find interception
		while (true) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast)
				break;
		}

		// find start point, P=X
		int slow2 = 0;
		while (true) {
			slow = nums[slow];
			slow2 = nums[slow2];
			if (slow == slow2)
				return slow;
		}
	}
};
