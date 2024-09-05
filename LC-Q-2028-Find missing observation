/* Q 2028- You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls.
Fortunately, you have also calculated the average value of the n + m rolls.
You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.
Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers,
return any of them. If no such array exists, return an empty array.
The average value of a set of k numbers is the sum of the numbers divided by k.
Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m */

//SOLUTION-  

//TIME COMPLEXITY- O(N)
//SPACE COMPLEXITY- O(N)

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int>ans;
        int sum=0;   // sum is sum of elements int rolls 
        int remain=0; // remain is sum of remaining rolls which are not given

         // getting sum
        for(int i=0;i<rolls.size();i++)
        {
            sum+=rolls[i];      
        }

        // using formula of mean [ n=(sum+remain)/(no of elements in rolls + n)]
        remain= (mean * (rolls.size()+n))-sum; 

        /* condition when its not possible to make arrray if remain is greater
           or less then the range */       
        if(remain > 6*n || remain < n)
        return ans;

       // finding avg of remain so we know most of the values will be equal to avg
        int avg = remain/n;

        while(remain >0)
        {
            ans.push_back(avg);  //putting avg value in ans
            remain-=avg;          // subttracting avg from remain

            if(ans.size()== n-1)
            {
                ans.push_back(remain); // putting all remaining value in last index
                remain=0;
            }
        }

        int k=ans[ans.size()-1]-6; // checking if last element is greater then 6
        
        while(k>0)
        {
            
            ans[ans.size()-1]=6; // making last element 6

            for(int i=0;i<ans.size();i++)
            {
                if(k<=0)
                break;

                if(ans[i]<6)   // distributing k among values to keep them in range 
                {
                    if(k>6-ans[i])
                    {
                        k-=(6-ans[i]);
                        ans[i]+=6-ans[i];                       
                    }
                    else
                    {
                       ans[i]++;
                       k--;
                    }
                    
                }
            }
        }
        return ans;
    }
};
