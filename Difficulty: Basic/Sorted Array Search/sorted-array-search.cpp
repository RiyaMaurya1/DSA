//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    bool binSearch(int arr[], int N, int k, int start, int end){
        if(start > end){
            return false;
        }
        int mid = (start+end)/2;
        if(arr[mid] == k){
            return true;
        }
        if(arr[mid] > k){
           return binSearch(arr, N, k, start , mid-1);
        }
        else{
           return binSearch(arr, N, k, mid+1, end);
        }
        return false;
    }
    
    int searchInSorted(int arr[], int N, int K) 
    { 
       // Your code here
       if(binSearch(arr, N, K, 0, N-1) == true){
           return 1;
       }
       return -1;
       
    }
};

//{ Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 

// } Driver Code Ends