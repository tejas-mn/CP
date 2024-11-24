// /https://practice.geeksforgeeks.org/contest/gfg-weekly-182-rated-contest/problems

class Solution {
  public:
    int minTime(int k, vector<int> &positions) {
        
        // sort the balloons in increasing order of their positions
        sort(positions.begin(), positions.end());
        
        int n = positions.size();
        int res = INT_MAX;
        
        // k-sized sliding window 
        for(int i = 0; i < n - k + 1; i++) {
            
            // left-most balloon of current window
            int leftEnd = positions[i];
            
            // right-most balloon of current window
            int rightEnd = positions[i + k - 1];
            
            // All k balloons are on -ve side
            if(leftEnd < 0 && rightEnd < 0) {
                res = min(res, abs(leftEnd));
            }
            
            // All k balloons are on +ve side
            else if(leftEnd > 0 && rightEnd > 0) {
                res = min(res, rightEnd);
            }
            
            // Balloons are on +ve as well as -ve side 
            else {
                int closerEnd = min(abs(leftEnd), rightEnd);
                int fartherEnd = max(abs(leftEnd), rightEnd);
                res = min(res, closerEnd * 2 + fartherEnd);
            }
        }
        return res;
    }
};
