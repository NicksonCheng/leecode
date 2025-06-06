// hint
/*
    friend list, hashtable<int, set<int>>

    post, hashtable<int,vector>

    getNewsFeed()-> travese all user friend(include self) post, then push into
   max heap to get top 10 recent post, time complextiy O(nlogn), n = tweetId




*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#define Pair pair<int, int>
class Twitter {
  public:
	unordered_map<int, unordered_set<int>> friends;
	unordered_map<int, vector<Pair>> posts; // {post_time, post_id}
	int time;
	Twitter() { this->time = 0; }

	void postTweet(int userId, int tweetId) {
		posts[userId].push_back({time++, tweetId});
	}

	vector<int> getNewsFeed(int userId) {
		// max heap to save most recently posted twitter
		priority_queue<Pair> max_heap;
		// user self posts need to be consider
		friends[userId].insert(userId);

		for (auto &f : friends[userId]) {
			for (auto post : posts[f]) {
				max_heap.push(post);
			}
		}
		vector<int> res;
		// dump most recent 10 twitter post from max heap
		while (!max_heap.empty() && res.size() < 10) {
			res.push_back(max_heap.top().second);
			max_heap.pop();
		}
		return res;
	}

	void follow(int followerId, int followeeId) {
		friends[followerId].insert(followeeId);
	}

	void unfollow(int followerId, int followeeId) {
		friends[followerId].erase(followeeId);
	}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */