//    https://leetcode.com/problems/closest-prime-numbers-in-range/description/
class Solution {
public:
    bitset<500000> sieve=0;
    void Sieve(int n) {
        //Use sieve method to solve 
        const int n_2=n>>1;   
        sieve[0]=1;
        const int n_2sqrt=int((sqrt(n)-1)/2);
        [[unroll]]
        for(int i=1; i<=n_2sqrt; i++)
        {
            if (!sieve[i])
            {
                const int p=2*i+1;
                for(int j=p*p/2 ; j<=n_2; j+=p)
                    sieve[j]=1;
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        left=(left&1)?left:left+1;
        right=(right&1)?right:right-1;

        if (right-left<2) return {-1, -1};
        if (left<=2) return {2, 3};
        Sieve(right);

        int minDist=1e6, prevPrime=-1e9-7;
        vector<int> ans={-1, -1};
        for (int p=left; p<=right; p+=2){
            if (!sieve[p>>1]) {
                const int dist=p-prevPrime;
                if (dist==2) return {prevPrime, p};
                if (dist<minDist){
                    ans={prevPrime, p};
                    minDist=dist;
                }
                prevPrime=p;
            }
        } 
        return ans;
    }
};
