/* Q-884-A sentence is a string of single-space separated words where each word consists only of lowercase letters.
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
*/

//SOLUTION-
// TC- O(N)
// SC- O(N)

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s3= s1+" "+s2; // joining the two sentences
        vector<string>ans;
        string word;
        unordered_map<string,int>mp;

        int i=0,j=0;
          
          // separating words from the joint sentence and storing them in map with count
        while(j<s3.size())
        {
            while(j<s3.size() && s3[j]!=' ')
            j++;
            word=s3.substr(i,j-i);
            mp[word]++;
            i=j+1;
            j++;
        }

        // words which have count = 1 will be pushed in ans
        for(auto it:mp)
        {
            if(it.second==1)
            ans.push_back(it.first);
        }
        return ans;
    }
};
