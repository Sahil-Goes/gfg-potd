//{ Driver Code Starts
#include <iostream>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int count=0, size = arr.size(), j = size - 1;
        
        sort(arr.begin(), arr.end());  //Sorting of vector array
        
        for(int i=0; i<size; i++){
            
                while(i<j){
                    int sum = arr[i] + arr[j];
                    
                    if (sum >= target){
                        j--;
                    }
                    
                    else{
                        //Uses this formula to count the no of pairs as nos less than that index of j will be
                        //lesser than count of target (used to optimize code as we sort the array)
                        count = count + (j-i);
                        break;
                    }
                }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}