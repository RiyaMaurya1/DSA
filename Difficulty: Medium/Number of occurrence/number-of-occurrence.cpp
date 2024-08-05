//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	// logic: upper bound - lower bound to get the no. of occurences
	// upper bound: arr[i] > target
	// lower bound: arr[i] >= target
	
	int getLB(int arr[], int n, int target){
	    int ans = n;
	    int start = 0;
	    int end = n-1;
	    while(start <= end){
	       int mid = (start+end)/2;
	       
	       if(arr[mid] >= target){
	           ans = mid;
	           end = mid-1;
	       }else{
	           start = mid+1;
	       } 
	    }
	    return ans;
	}
	
	int getUB(int arr[], int n, int target){
	    int ans = n;
	    int start = 0;
	    int end = n-1;
	    while(start <= end){
	       int mid = (start+end)/2;
	       
	       if(arr[mid] > target){
	           ans = mid;
	           end = mid-1;
	       }else{
	           start = mid+1;
	       } 
	    }
	    return ans;
	}
	
	
	int count(int arr[], int n, int x) {
	    // code here
	    int first = getLB(arr, n, x);
	    if(first == n || arr[first] != x){
	        return 0;
	    }
	    int last = getUB(arr, n, x);
	    
	    return last-first;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends