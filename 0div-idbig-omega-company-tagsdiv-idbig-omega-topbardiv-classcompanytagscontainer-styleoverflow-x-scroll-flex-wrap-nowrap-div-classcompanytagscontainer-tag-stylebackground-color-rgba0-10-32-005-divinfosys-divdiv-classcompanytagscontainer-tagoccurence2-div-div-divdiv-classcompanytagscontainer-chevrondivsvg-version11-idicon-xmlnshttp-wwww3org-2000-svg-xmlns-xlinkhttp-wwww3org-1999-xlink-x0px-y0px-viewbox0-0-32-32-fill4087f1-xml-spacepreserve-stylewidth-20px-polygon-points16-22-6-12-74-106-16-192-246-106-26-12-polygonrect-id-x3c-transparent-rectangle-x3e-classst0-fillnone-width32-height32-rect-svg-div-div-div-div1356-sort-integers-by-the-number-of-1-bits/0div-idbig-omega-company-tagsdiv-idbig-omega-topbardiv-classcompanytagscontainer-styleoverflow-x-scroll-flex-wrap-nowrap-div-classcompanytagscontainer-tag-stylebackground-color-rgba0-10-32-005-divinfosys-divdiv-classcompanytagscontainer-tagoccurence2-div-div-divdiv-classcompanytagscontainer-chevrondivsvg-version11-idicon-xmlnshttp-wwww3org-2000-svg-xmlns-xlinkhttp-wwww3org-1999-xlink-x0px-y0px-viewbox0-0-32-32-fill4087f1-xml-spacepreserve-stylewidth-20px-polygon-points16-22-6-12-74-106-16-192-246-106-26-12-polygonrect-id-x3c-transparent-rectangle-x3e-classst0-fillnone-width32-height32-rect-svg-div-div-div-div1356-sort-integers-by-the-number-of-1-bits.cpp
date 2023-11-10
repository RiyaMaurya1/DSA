class Solution {
public:
    typedef pair<int, int> pii;
    int cal(int num){
        int x = 0;
        while(num > 0){
            if(num & 1){
                x++;
            }
            num = num>>1;
        }
        return x;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pii, vector<pii>, greater<pii>>minh;
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minh;
        for(int i = 0 ; i < n ; i++){
            int bit = cal(arr[i]);
            minh.push({bit, arr[i]});
        }
        vector<int>ans;
        while(!minh.empty()){
            int ele = minh.top().second;
            ans.push_back(ele);
            minh.pop();
        }
        return ans;
    }
};