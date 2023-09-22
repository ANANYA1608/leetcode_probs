class Solution {
public:
    string convert(string s, int r) {
        int num=s.size();
        if(r==1)
            return s;

        int f=(r-1)*2;
        int sl=0;
        int flag=1;
        string ans;
        int k=0;

        while(f>=0)
        {
            int temp=k;
            while(temp<num)
            {
                if(flag && f)
                {
                    ans.push_back(s[temp]);
                    temp+=f;
                }
                else
                {
                    if(sl)
                        ans.push_back(s[temp]);
                    temp+=sl;
                }

                flag=1-flag;
            }
            flag=1;
            f-=2;
            sl+=2;
            k++;
        }
        return ans;
    }
};