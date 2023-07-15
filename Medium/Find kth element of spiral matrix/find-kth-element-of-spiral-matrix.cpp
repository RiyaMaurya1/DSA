//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int ind = 0;
 		int total = m*n;
 		int ans = 0;
 		
 		int startrow = 0;
 		int startcol = 0;
 		int endrow = n-1;
 		int endcol = m-1;
 		
 		vector <pair<int, pair<int,int>>> v;
 		
 		while(ind < total){
 		    for(int i = startcol; i <= endcol && ind < total; i++ ){
 		        ans = a[startrow][i];
 		        v.push_back({ans,{startrow, i}});
 		        ind++;
 		    }
 		    startrow++;
 		    
 		    for(int i = startrow ; i <= endrow && ind < total ; i++){
 		        ans = a[i][endcol];
 		        v.push_back({ans, {i, endcol}});
 		        ind++;
 		    }
 		    endcol--;
 		    
 		    for(int i = endcol ; i >= startcol && ind < total ; i-- ){
 		        ans = a[endrow][i];
 		        v.push_back({ans, {endrow, i}});
 		        ind++;
 		    }
 		    endrow--;
 		    
 		    for(int i = endrow; i >= startrow && ind < total; i--){
 		        ans = a[i][startcol];
 		        v.push_back({ans, {i, startrow}});
 		        ind++;
 		    }
 		    startcol++;
 		    
 		}
//  		for(auto i : v){
//  		    cout << i << " ";
//  		}
//  		cout << endl;

//         int x = 0;
//  		for(int i = 0 ; i < v.size(); i++){
//             cout << "r " << v[i].second.first << " c " << v[i].second.second << endl;
//             cout << "ind " << x << " ele " << v[i].first << endl;
//             x++;
//         }
//     cout << "r " << v[k-1].second.first << " c " << v[k-1].second.second << endl;
 		return v[k-1].first;
    }
};

// 4 4 10
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16




//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends