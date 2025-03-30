/*
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 
Example 1:
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:
Input: s = "leetcode"
Output: "leotcede"

 
Constraints:
1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

//SOLUTION

class Solution {
public:

    bool isVowel(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='I' || a=='O' || a=='U')
        return true;
        return false;
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;

        while(i<j)
        {
            if(isVowel(s[i]) && isVowel(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(isVowel(s[i]))
            j--;
            else if(isVowel(s[j]))
            i++;
            else
            {
                i++;
                j--;
            }
        }

        return s;
    }
};
