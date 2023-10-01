class Solution {
public:
    string reverseWords(string s) {
    int n=s.length(),i=0,j=0,k;
    while(j<n)
    {
        while(j<n && s[j]!=' ') j++;
        k=j-1;
        while(i<k) swap(s[i++],s[k--]);
        i=j+1;
        j++;
    }
    return s;
}
};