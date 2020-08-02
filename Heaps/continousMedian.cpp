//https://leetcode.com/problems/find-median-from-data-stream/


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue <int, vector<int>, greater<int> > min_heap;
    priority_queue <int> max_heap;
    
    MedianFinder() {}
    
    void addNum(int num) {
        if(min_heap.empty() && max_heap.empty()) {
            max_heap.push(num);
            return;
        }
        
        if(num > max_heap.top()) {
            min_heap.push(num);
            if(min_heap.size() - max_heap.size() > 1) {
                int temp = min_heap.top();
                min_heap.pop();
                max_heap.push(temp);
            }
        } else {
            max_heap.push(num);
            if(max_heap.size() - min_heap.size() > 1) {
                int temp = max_heap.top();
                max_heap.pop();
                min_heap.push(temp);
            }
        }
    }
    
    double findMedian() {
        int n = min_heap.size();
        int m = max_heap.size();
        
        if((n + m) & 1) {
            if(n > m)
                return min_heap.top();
            return max_heap.top();
        } else {
            return (double)(min_heap.top() + max_heap.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
