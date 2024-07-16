//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int zeropointer = 0;
	    int numpointer = 0;
	    while(zeropointer < n && numpointer < n){
	        while(zeropointer < n && arr[zeropointer] != 0){
	            zeropointer++;
	        }
	        while(numpointer < n && arr[numpointer] == 0 ){
	            numpointer++;
	        }
	        if(zeropointer < n && numpointer < n && zeropointer < numpointer){
	            swap(arr[zeropointer], arr[numpointer]);
	        } 
	        else{
	            numpointer++;
	        }
	    }
	    
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends