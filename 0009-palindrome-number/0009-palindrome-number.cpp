class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        if(x==0)
        return true;
       long int y=x,rev=0;
        while(y>0){
        int nums=y%10;
        y/=10;
        rev=rev*10+nums ;
    }
    return rev==x;
    }
};