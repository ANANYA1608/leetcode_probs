class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> curr(1, poured);
		
        for(int i=0; i<=query_row; i++){ 
            vector<double> next(i+2, 0); 
            for(int j=0; j<=i; j++){ 
                if(curr[j]>=1){ 
                    next[j] += (curr[j]-1)/2.0; 
                    next[j+1] += (curr[j]-1)/2.0; 
                    curr[j] = 1; 
                }
            }
            if(i!=query_row) curr = next; 
        }
        return curr[query_glass];
    }
};