//Smallest Divisor: To find smallest divisor such that divides entire array with ans <= k. k is always greater than array size.
//Brute Force Approach
 int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int ans=999, possibleAns;
        int max = *max_element(arr.begin(), arr.end());
        
        for(int i=1; i<= max; i++){
            possibleAns = 0;
            for(int j=0; j<arr.size(); j++){
               possibleAns += (arr[j] + i - 1) / i;
            }
            
            if( possibleAns <= k){
                ans = min(ans,i);
            }
        }
        return ans;
    }
