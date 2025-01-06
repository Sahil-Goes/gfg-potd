//{ Driver Code Starts
// Initial template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        if (arr.size() < 2) return {}; // If there are fewer than 2 elements, return empty

        sort(arr.begin(), arr.end()); // Sort the array
        int s = 0, e = arr.size() - 1;
        int closestDiff = INT_MAX; // Store the closest difference
        vector<int> result;

        while (s < e) {
            int pairSum = arr[s] + arr[e];
            int diff = abs(target - pairSum);

            // Update the result if a closer pair is found
            if (diff < closestDiff || (diff == closestDiff && abs(arr[e] - arr[s]) > abs(result[1] - result[0]))) {
                closestDiff = diff;
                result = {arr[s], arr[e]};
            }

            // Adjust pointers
            if (pairSum < target) {
                s++;
            } else if (pairSum > target) {
                e--;
            } else {
                return result; // Exact match
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends