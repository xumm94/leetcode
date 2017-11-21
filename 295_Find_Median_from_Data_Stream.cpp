class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        right.push(-left.top());
        left.pop();
        if(left.size() < right.size())
        {
            left.push(-right.top());
            right.pop();
        }
        
    }
    
    double findMedian() {
        int len = left.size() + right.size();
        if(len % 2 == 1)
            return left.top();
        else
            return (left.top() - right.top()) / 2.0;
    }
private:
    priority_queue<int> left, right;
};

/*注意在addNum函数中的一些问题：
一开始觉得先压入左边，弹出再压入右边是没有必要的。仔细想一想，为什么需要两个堆，就是将堆划分为两部分，右边的最小值大于左边的最大值。当前新来的这个数我不知道需要放在左边还是右边，那么就先放在左边，如果是最大，自然会走到top()*/
