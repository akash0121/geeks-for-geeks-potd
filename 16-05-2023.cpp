// Cutting Binary String

// Given a string s containing 0's and 1's. You have to return the smallest positive integer C, such that the binary string can be cut into C pieces and each piece should be of the power of 5  with no leading zeros.
// Note: The string s is a binary string. And if no such cuts are possible, then return -1.

class Solution{
    public:
    
    long solve(int i,string &s){
        if(s[i]=='0')
        return INT_MAX;
        if(i==s.size()){
            return 0;
        }
        int num = 0;
        long mini = INT_MAX;
        
        for(int j=i;j<s.size();j++)
        {
            num = num*2 + (s[j]-'0');
            for(int p=0;p<15;p++)
            {
                if(num == pow(5,p))
                {
                    long cut = 1 + solve(j+1,s);
                    mini = min(mini,cut);
                }
            }
        }
        return mini;
    }
    
    int cuts(string s){
        //code
        int ans = solve(0,s);
        return ans == INT_MAX ? -1 : ans;
    }
};