QUESTION : Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.
  
Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
  
Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
  
https://media.geeksforgeeks.org/wp-content/cdn-uploads/NewPermutation.gif


-----------------------------------------------------------
  
class Solution
{
	public:
	
        void permute(string s, vector<string>& ans, int i)
        {
            if(i == s.length() - 1) 
            {
                ans.push_back(s);
                return;
            }
            
            for(int j = i; j < s.length(); j++)
            {
                if(i != j and s[i] == s[j]) continue; // Swaping of same element remains same so skipped.
                else
                {
                    swap(s[i],s[j]); // Swap them to Make a permutation
                    permute(s,ans,i+1); // i+1 is for to check the permutation of next element.
                }
            }
        }
	
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string> ans;
		    sort(s.begin(),s.end()); // To Print input in sorted order.
		    permute(s,ans,0);
		    return ans;
		}
};
