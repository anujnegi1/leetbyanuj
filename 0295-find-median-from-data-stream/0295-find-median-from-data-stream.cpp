class MedianFinder {
public:
   priority_queue<int>mh;
   priority_queue<int,vector<int>,greater<int>>minh;
    MedianFinder() {
    }
    
    void addNum(int num) {
        mh.push(num);
        minh.push(mh.top());
        mh.pop();
        if(minh.size()>mh.size())
        {
            mh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(mh.size()>minh.size()) return mh.top();
        return (mh.top()+minh.top())/2.0;
        }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */