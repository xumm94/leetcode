    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        size_t index  = 0;
        vector<Interval> result;
        while(index < intervals.size() && intervals[index].end < newInterval.start)
            result.push_back(intervals[index++]);
        
        result.push_back(newInterval);
        while(index < intervals.size() && intervals[index].start <= newInterval.end)
        {
            result.back().start = min(result.back().start, intervals[index].start);
            result.back().end   = max(result.back().end, intervals[index].end);
            index++;
        }
        while(index < intervals.size())
            result.push_back(intervals[index++]);
        return result;
        

        
    }


/*插入的时间间隔的位置可以分成三部分：

    插入位置左侧
    插入位置（有重叠或无重叠）
    插入位置右侧

这三个部分分别处理，只有在插入位置处理可能存在的情况即可。*/
