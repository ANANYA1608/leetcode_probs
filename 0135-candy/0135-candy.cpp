class Solution {
public:
    int candy(vector<int>& ratings) {
       int n= ratings.size();
       int l2r[n];
       int r2l[n];
       for(int i=0;i<n;i++){
         l2r[i]=r2l[i]=1;
       }
       for(int i=1;i<n;i++){
           if(ratings[i]>ratings[i-1])
           l2r[i]=l2r[i-1]+1;
       }
       for(int j=n-2;j>=0;j--){
           if(ratings[j]>ratings[j+1])
           r2l[j]=r2l[j+1]+1;
       }
       int sum[n];
       for(int i=0;i<n;i++){
           sum[i]=max(l2r[i],r2l[i]);
       }
       int ans=accumulate(sum,sum+n,0);
       return ans;

    }
};