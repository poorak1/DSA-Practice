class Solution {
public:
    bool valid(int curr_speed, vector<int> &piles, int hours){
        int hours_taken = 0;
        for(int i=0; i<piles.size(); i++){
            if(hours_taken > hours) return false;

            if(piles[i] <= curr_speed) hours_taken++;
            else hours_taken+=ceil((double)piles[i] / curr_speed);;
        }
        return hours_taken <= hours; 
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(valid(mid, piles, h)){
                ans = mid;
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};