/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
    multiset<int> data;
    multiset<int>::iterator mid_pos;

    /** initialize your data structure here. */
    MedianFinder() : mid_pos{data.end()} {}

    void addNum(int num) {
        auto len = data.size();
        data.insert(num);
        if (len == 0)
            mid_pos = data.begin();
        else if (num < *mid_pos)
            mid_pos = len % 2 == 1 ? mid_pos : prev(mid_pos);
        else
            mid_pos = len % 2 == 1 ? next(mid_pos) : mid_pos;
        return;
    }

    double findMedian() { return data.size() % 2 == 1 ? *mid_pos : (*prev(mid_pos) + *mid_pos) * 0.5; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
