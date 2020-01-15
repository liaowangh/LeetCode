class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n_max = max_queue.size();
        int n_min = min_queue.size();
        if(n_max == 0)
            max_queue.push(num);
        else if(n_max == n_min){
            if(num <= min_queue.top())
                max_queue.push(num);
            else{
                max_queue.push(min_queue.top());
                min_queue.pop();
                min_queue.push(num);
            }
        }else{
            if(num > max_queue.top())
                min_queue.push(num);
            else{
                min_queue.push(max_queue.top());
                max_queue.pop();
                max_queue.push(num);
            }
        }
    }
    
    double findMedian() {
        return max_queue.size() == min_queue.size() ?
            (max_queue.top() + min_queue.top()) / 2.0 : max_queue.top();
    }
    
private:
    priority_queue<int> max_queue;  // has the smaller half of the data
    priority_queue<int, vector<int>, greater<int>> min_queue;
                                    // has the larger half of the data
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
