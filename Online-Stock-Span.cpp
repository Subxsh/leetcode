class StockSpanner {
public:
    vector<int>prices;
    stack<int>s;
    int i=0;
    int next(int price){
        prices.push_back(price);
        while(!s.empty()&&prices[s.top()]<=price){
            s.pop();
        }
        int span=s.empty()?i+1:i-s.top();
        s.push(i++);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */