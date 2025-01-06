// Sum Pair closest to target

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int diff = INT_MAX;
        int closestSum = INT_MAX;
        vector<int>result;
        int i=0,j=n-1;
        while(i<j){
            int sum = arr[i] + arr[j];
            int currentDiff = abs(target - sum);
            if(currentDiff < diff){
                diff = currentDiff;
                closestSum = sum;
                result = {arr[i],arr[j]};
            }
            if(sum<target){
                i++;
            }
            else if(sum>target){
                j--;
            }
            else{
                return {arr[i],arr[j]};
            }
        }
        return result;;
    }
};