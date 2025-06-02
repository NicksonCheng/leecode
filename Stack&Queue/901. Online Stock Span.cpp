// proficient
// 16 min
/*
    1. brutal force: 全部push到vector, 每次都往後survey, O(n) in every next()
    2. monotonic stack,  維持strictly decrease, 每次遇到prices > top(),
   pop同時計算span, 並且記錄目前這個的span
*/
class StockSpanner {
  public:
	stack<pair<int, int>> stocks; // {value, span}
	StockSpanner() {}

	int next(int price) {
		// every time pop ++span
		int span = 1; // include self
		while (!stocks.empty() && price >= stocks.top().first) {
			span += stocks.top().second;
			stocks.pop();
		}
		stocks.push({price, span});
		return span;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */