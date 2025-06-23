// Most Frequently occuring element in an 2D Matrix. If 2 nos have same frequency return the maximum value.
#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int findMostFrequentElement(int n, vector<vector<int>> &mat) {
    map<int, int> freq;

    // Count frequencies
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            freq[mat[i][j]]++;
        }
    }

    int maxFreq = 0;
    int result = INT_MAX;

    // Find the element with max frequency (and smallest if tie)
    for(auto p : freq) {
        int element = p.first;
        int count = p.second;

        if(count > maxFreq) {
            maxFreq = count;
            result = element;
        } else if(count == maxFreq && element < result) {
            result = element;
        }
    }

    return result;
}

// Example usage
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 1},
        {2, 9, 1}
    };
    int n = 3;

    cout << findMostFrequentElement(n, mat) << endl;  // Output: 1
    return 0;
}
