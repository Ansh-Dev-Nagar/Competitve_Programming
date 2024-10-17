/* Q-670-You are given an integer num. You can swap two digits at most once to get the maximum valued number.
Return the maximum valued number you can get.

Example 1:
Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
*/

//SOLUTION-
//Time complexity: O(NlogN) since we used sort function.
//Space complexity: O(N) since we used another array.

class Solution {
public:
// converting the number to vector
    vector<int>to_array(vector<int>&v,int n)
    {
        while(n>0)
        {
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(),v.end());
        return v;
    }

// converting the vector to number again
    int to_number(vector<int>&v)
    {
        int sum =0,j=0;
       for(int i=v.size()-1;i>=0;i--)
       {
          sum+=v[i]*pow(10,j);
          j++;
       }
       return sum;
    }

 // Main solution function
    int maximumSwap(int num) {

        vector<int>v;
        to_array(v,num);
        int i=0,j=v.size()-1,need;
        vector<int>v2=v;

      // Sorting the array in descending order
        sort(v2.begin(),v2.end(),greater<int>()); 
      
      /* comparing the sorted array with normal array to find the greatest element
         which is not same */
        while(i<v.size())
        {
            if(v[i]!=v2[i])
            {
                need=v2[i]; // storing the value where its not same 
                break;
            }
            i++;
        }

        if(i==v.size()) // condition when the array was already sorted
        return num;     // return original number

        while(j>=0)
        {
            if(v[j]==need) //  stopping at index where the values is equal to need
            break;
            j--;
        }

        swap(v[i],v[j]); 

        int ans= to_number(v); //converting array to number 

        return ans;


    }
};
