class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int maxscore = 0;
        int visiting_score = 0;
        int max_ind = 0;
        for(int i = 0 ; i < n ; i++){
            if(customers[i] == 'Y'){
                visiting_score++;
            }
            else{
                visiting_score--;
            }
            if(visiting_score > maxscore){
                maxscore = visiting_score;
                max_ind = i;
            }
        }
        if(maxscore == 0){
            return 0;
        }
        return max_ind+1;
    }
};