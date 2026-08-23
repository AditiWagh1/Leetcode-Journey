class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1;
        int sum=0;
        while(n>0)
        {
            int lastdigit=n%10;
            prod*=lastdigit;
            sum+=lastdigit;
            n=n/10;
        }
        int ans=prod-sum;
        return ans;
    }
};