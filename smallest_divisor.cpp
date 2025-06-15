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

//Optimized Approach: Using Binary Search to find which ans offers more possibility to be the correct ans
 int computeSum(vector<int>& arr, int divisor){
        int total = 0;
        for (int num : arr) {
            total += (num + divisor - 1) / divisor;  // Efficient ceil
        }
        return total;
    }
  
    int smallestDivisor(vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int currSum = computeSum(arr, mid);
    
            if (currSum <= k) {
                ans = mid;           // Candidate found, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;       // Too small, try larger
            }
        }
    
        return ans;
    }
