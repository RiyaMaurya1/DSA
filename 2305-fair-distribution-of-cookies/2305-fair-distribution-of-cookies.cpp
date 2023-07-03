class Solution {
public:
    // the vector of children representing the number of chocolates each child has, 
    // and the minimum maximum chocolates (MMC) allocated to any child so far. 
    
    void ExploreDistributions(vector<int> &cookies, int index, vector<int> &children, int &MMC){
        // Base Case (if index goes out of bounds)
        if(index >= cookies.size()){
            // get the current largest element (max chocolates alloted to a child)
            int curr_max = INT_MIN;
            for(int &choc : children){
                curr_max = max(curr_max, choc);
            }

            MMC = min(MMC, curr_max);

            return ;
        }

        // Processing
        for(int i=0; i < children.size(); i++){
            // recursive call where the current chocolate box is given to the i'th child
            children[i] += cookies[index];
            ExploreDistributions(cookies, index + 1, children, MMC );
            // backtracking to explore those cases where
            // the current chocolate box is not given to the i'th child 
            children[i] -= cookies[index];           
        }

        return ;
    };

 int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k,0);
        int MMC = INT_MAX;
        ExploreDistributions(cookies, 0, children, MMC);
        return MMC;
    }
};