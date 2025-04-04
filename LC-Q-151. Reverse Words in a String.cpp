/*
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 
Constraints:
1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/

//SOLUTION-

lass Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i=n-1,j=i;
        string ans;

        if(n==1)
        return s;

        while (i>=0)
        {
            while(i>=0 && s[i]==' ' && s[j]==' ')
            {
                j--;
                i--;
            }
            while(i>0 && s[i-1]!=' ')
            {
                i--;
            }
            
            if(i>=0)
           ans+=s.substr(i,j-i+1)+' ';
           j=i-2;
           i=j;
        }

        return ans.substr(0,ans.size()-1);
    }
};
