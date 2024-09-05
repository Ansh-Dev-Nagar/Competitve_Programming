/* Q-874 - A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot can receive a sequence of these three possible types of commands:
-2: Turn left 90 degrees.
-1: Turn right 90 degrees.
1 <= k <= 9: Move forward k units, one unit at a time.
Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle,
then it will instead stay in its current location and move on to the next command.
Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if the distance is 5, return 25).
Note:
North means +Y direction.
East means +X direction.
South means -Y direction.
West means -X direction.
There can be obstacle in [0,0]. */

// Solution
// TC - O(N*M) due to nested loop
// SC - O(N) since used set of pair

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0;
        char dir='N';
        int ans=0;
      // Using set so we can easily find if a position has a obstacle or not
        set<pair<int,int>>st;
       for(int i=0;i<obstacles.size();i++)
       {
         st.insert({obstacles[i][0],obstacles[i][1]});
       }
      /* iterating through all commands and checking if the value is less then 0, because if it is then we have to either turn left or right
         and changing direction accordingly using char N,S,E,W */
        for(int i=0;i<commands.size();i++)
        {
           if(commands[i]<0)
           {
             if(dir=='N')
             {
                if(commands[i]==-2)
                dir='W';
                else
                dir='E';
             }
             else if(dir=='E')
             {
                if(commands[i]==-2)
                dir='N';
                else
                dir='S';
             }
             else if(dir=='W')
             {
                if(commands[i]==-2)
                dir='S';
                else
                dir='N';
             }
             else
             {
                if(commands[i]==-2)
                dir='E';
                else
                dir='W';
             }
           }
        // if value is greater then zero then we will move in the particular direction while also making sure we dont find any obstacle using set
           else   
           {
            int j=0;
            if(dir=='N')
            {
                while(j<commands[i])
                {
                    if(st.find({x,y+1})!=st.end())
                    break;
                    y++;
                    j++;
                }
            }

            else if(dir=='E')
            {
                while(j<commands[i])
                {
                    if(st.find({x+1,y})!=st.end())
                    break;
                    x++;
                    j++;
                }
            }

            else if(dir=='S')
            {
                while(j<commands[i])
                {
                    if(st.find({x,y-1})!=st.end())
                    break;
                    y--;
                    j++;
                }
            }

            else
            {
                while(j<commands[i])
                {
                    if(st.find({x-1,y})!=st.end())
                    break;
                    x--;
                    j++;
                }
            }

           }
           //cout<<x<<" "<<y<<" "<<dir<<endl;
           ans= max(ans,y*y+x*x);
        }
        
        return ans;
    }
};
