class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size())
            return -1;
        int total = 0, gas_sum = 0, diff = 0, start = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            diff = gas[i] - cost[i];
            total += diff;
            if(gas_sum < 0)
            {
                gas_sum = diff;
                start = i;
            }
            else
            {
                gas_sum += diff;
            }
        }
        
        return total >= 0 ? start : -1;
    }
};
