/* Q-539- Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
*/

//SOLUTION-
// TC - O(N)
// SC - O(N)

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>v;
         int hour=0,mins=0,total=0,ans=INT_MAX;
         // adding the time in minutes to vector v
        for(auto it:timePoints)
        {
            //converting string to int
            hour = stoi(it.substr(0,2));  
            mins = stoi(it.substr(3,2));

            //converting hour into mins and adding into mins
            total= hour*60 + mins;

            v.push_back(total);
        }
        int n = v.size();

        // sorting vector v
       sort(v.begin(),v.end());


        for(int i=0;i<n-1;i++)
        {  
             ans = min(ans,v[i+1]-v[i]);  // finding the minimum diff b/w minutes
        }
           // for considering last and first minute(circular nature)
            ans = min(ans,1440-v[n-1]+v[0]);  

        return ans;
    }
};
