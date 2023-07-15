//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        vector <int> v;
        map <int, int> mp;
        for(int i = 0 ; i< n ; i++){
            mp[arr[i]]++;
        }
        for(auto it: mp){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        if(v.size() == 1){
            return true;
        }
        for(int i = 1 ; i < v.size(); i++){
            if(v[i] == v[i-1] ){
                return false;
            }
        }
        return true;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends