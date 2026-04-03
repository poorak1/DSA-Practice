class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr1 = 0;
        int ptr2 = numbers.size()-1;
        vector<int> final;
        while(ptr2 > ptr1){
            if((numbers[ptr1] + numbers[ptr2]) == target){
                final.push_back(ptr1+1);
                final.push_back(ptr2+1);
                return final;
            }else if((numbers[ptr1] + numbers[ptr2]) > target){
                ptr2--;
            }else{
                ptr1++;
            }
        }
        return final;
    }
};