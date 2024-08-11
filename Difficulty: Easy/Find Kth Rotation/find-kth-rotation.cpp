//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  
    int findindex(vector<int> &arr, int n){
        int start = 0;
        int end = n-1;
        int mini = INT_MAX;
        int ind = -1;
        while(start <= end){
            int mid = (start+end)/2;
            // cout << "st: " << start << " end: " << end << " mid: " << mid << endl;
            if(arr[start] <= arr[mid]){ //left is sorted
                if(arr[start] < mini){
                    mini = arr[start];
                    ind = start;
                }
                start = mid+1;
                // cout << "left sorted "<< endl;
            }
            else{ // right is sorted;
                // cout << "rightt sorted "<< endl;
                if(arr[mid] < mini){
                    mini = arr[mid];
                    ind = mid;
                }
                end = mid-1;
            }
        }
        return ind;
    }
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        if(arr[0] < arr[n-1]){
            return 0;
        }
       
        return findindex(arr, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends