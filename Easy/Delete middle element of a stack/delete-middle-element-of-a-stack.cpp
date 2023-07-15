//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int midind = (sizeOfStack+1)/2;
        // cout << "midind " << midind << endl;
        int k = 1;
        if(sizeOfStack % 2 == 0){
            k = 0;
        }
        vector <int> temp;
        while(k < midind+1){
            // cout << "k " << k << endl;
            if(k != midind){
                int a = s.top();
                // cout << "a " << a << endl;
                s.pop();
                temp.push_back(a);
            }
            else{
                // cout << "pop " << s.top() << endl;
                s.pop();
            }
            k++;
        }
        
        for(int i = temp.size()-1 ; i >= 0 ; i--){
            s.push(temp[i]);
        }
        
    }
};


// 5
// 1 2 3 4 5

// Expected Output: 
// 5 4 2 1


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends