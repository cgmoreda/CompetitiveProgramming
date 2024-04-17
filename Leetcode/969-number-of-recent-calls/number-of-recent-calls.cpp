const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 11;
}();


class RecentCounter {
    queue<int>q;
public:

    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front()+3000<t)
            q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */