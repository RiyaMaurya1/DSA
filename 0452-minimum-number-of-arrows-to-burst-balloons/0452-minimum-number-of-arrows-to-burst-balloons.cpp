class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int arrows = 0;
        sort(points.begin(),points.end());
        vector <int> balloons(n, 1);
        int start = 0;
        int end = 0;
        int start2 = 0;
        int end2 = 0;
         for(int i = 0 ; i < n ; i++){
             if(balloons[i] == 1){
                 start = points[i][0];
                 end = points[i][1];
                 int j = i+1;
                 balloons[i] = 0;
                 while(j < n && points[j][0] <= end){
                     start2 = points[j][0];
                     end2 = points[j][1];
                     balloons[j] = 0;
                     if(start2 >= start){
                         start = start2;
                     }
                     if(end2 <= end){
                         end = end2;
                     }
                     j++;
                 }
                 arrows++;
             }
         }
        
        return arrows;
    }
};