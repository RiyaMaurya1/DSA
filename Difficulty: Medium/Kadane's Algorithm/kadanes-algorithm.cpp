//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        int n = arr.size();
        long long maxsum = LLONG_MIN;
        long long currsum = 0;
        for(int i = 0 ; i < n ; i++){
            // cout << "i " << i << " arr[i] " << arr[i] << endl;
            // cout << "currsum " << currsum << " maxsum " << maxsum << endl;
            if(currsum + arr[i] <= 0){
                // cout << "enter if" << endl;
                currsum = 0;
                if(arr[i] > maxsum){
                    maxsum = arr[i];
                }
            }
            else if (currsum + arr[i] > 0){
                // cout << "enter else if" << endl;
                currsum += arr[i];
                if(currsum > maxsum){
                    maxsum = currsum;
                }
            }
            // cout << "currsum " << currsum << " maxsum " << maxsum << endl;
        }
        return maxsum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends