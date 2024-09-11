/*
Q-2220-A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.
For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it.
We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.
*/

//SOLUTION- 

 // BRUTE FORCE
        //TC - O(N)
        //SC - O(N)

class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<int>one,two;
        int ans=0;
        //converting to binary
        while(start)
        {
            one.push_back(start%2);
            start/=2;
        }

        while(goal)
        {
            two.push_back(goal%2);
            goal/=2;
        }
        int diff =two.size()>one.size()?two.size()-one.size():one.size()-two.size();

        //making both array equal by adding 0s to smaller array

        if(two.size()>=one.size())
        {
            while(diff)
            {
                one.push_back(0);
                diff--;
            }
        }
        if(two.size()<one.size())
        {
            while(diff)
            {
                two.push_back(0);
                diff--;
            }
        }

        //comparing the difference
        
        for(int i=0;i<two.size();i++)
        {
            if(one[i]!=two[i])
            ans++;
        }
        return ans; 
    }
};

 //OPTIMIZED
        // TC - O(1)
        // SC - O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
      int xoR = start ^ goal;  // gives the difference between bits of start and goal as 1
        int ans=0;

        while(xoR > 0) // runs until all bits become 0
        {
            ans+= xoR & 1; // compares the LSB (right most) as if we & 1 it will give 1 if its set
            xoR >>= 1; // right shift by 1 bit
        }
        return ans;
    }
};
