// hint
/*
    先建立每個letter所在index的hash table
    ababcc
    a-> 0, 2
    b-> 1, 3
    c-> 4, 5

    然後當成interval去做, 也就是說每個letter都去看interval尾端切partition
    如果和上一個interval重疊,代表這兩個partition不可切分只好擴充partiton

    n = string length
    m = num of different char
    time complexity O(n), space O(m)
*/
class Solution {
  public:
	vector<int> partitionLabels(string s) {
		unordered_map<char, vector<int>> letter_index;
		vector<char> letter_order;
		// save letter index to hashtable
		for (int i = 0; i < s.length(); ++i) {
			if (letter_index.count(s[i]) == 0)
				letter_order.push_back(s[i]);
			letter_index[s[i]].push_back(i);
		}

		// divide partiton
		int part_start = -1;
		int part_end = -1;
		vector<int> partition;

		for (auto &l : letter_order) {
			vector<int> indices = letter_index[l];
			int start = indices[0];
			int end = indices[indices.size() - 1];
			// cout<<l<< " " <<  start << " "<< end << endl;
			if (part_end == -1) {
				part_start = start;
				part_end = end;
				continue;
			}
			if (start <= part_end) {
				// expand current partition length
				part_end = max(part_end, end);
			} else {
				// divide partition
				partition.push_back(part_end - part_start + 1);

				// new partition
				part_start = start;
				part_end = end;
			}
		}

		partition.push_back(part_end - part_start + 1);
		return partition;
	}
};