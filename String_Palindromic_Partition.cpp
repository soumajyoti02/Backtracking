
=======================================================================================================================================================
QUESTION : Given a string s, partition s such that every string of the partition is a palindrome. Return all possible palindrome partitioning of s. 
=======================================================================================================================================================
Input  : s = "bcc"
Output : [["b", "c", "c"], ["b", "cc"]]

Input  : s = "geeks"
Output : [["g", "e", "e", "k", "s"], 
          ["g", "ee", "k", "s"]]
          
-----------------------------------------------
Approach :

1. Declare a Vector of String temp to store the answers.
2. Call addString and pass main String, ans vector,temp vector and index i.e. 0
  
Inside addString(string &s, vector<vector<string>> &ans, vector<string> &temp, int ind) ------>>>
1) Starting from index 0; Check that SubString from 0 to i is palindrome or not.
    i) If palindrome then :
      a) If i less than length of main string then
           Push that part of string in Vector temp. and call the function recursively by incrementing i -> i+1;
      b) If not then We checked rest of string from starting of a letter. So push that temp into ans.
      
      Make temp = current to make it new;


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
<<--- :THE 2 MAIN FUNCTION :--->>

-----------------------------------------------------------------------------------------------
void partition(string s, vector<vector<string>> &v)
{
    vector<string> temp;
    addString(s, v, temp, 0);
    printSolution(v);
    return;
}


void addString(string &s, vector<vector<string>> &ans, vector<string> &temp, int ind)
{
    string str; // To store palindrome subStrings.
    vector<string> current = temp; // To store starting state of temp.
    for (int i = ind; i < s.length(); i++)
    {
        str = str + s[i]; // Taking the SubString from 0 to i
        if (checkPalindrome(str))
        {
            temp.push_back(str); // If it's Palindrome then it's One part of our one answer.
            if (i + 1 < s.length()) // If index is less than length of string
                addString(s, ans, temp, ind + 1);
            else
            {
                ans.push_back(temp);
            }
            temp = current; // Making temp as starting.
        }
    }
}

------------------------------------------------------------------------------------------
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  
  
  
  ## FULL CODE BELOW ###


// C++ program to print all palindromic partitions
// of a given string.
#include <bits/stdc++.h>
using namespace std;

// Returns true if str is palindrome, else false
bool checkPalindrome(string str)
{
    int len = str.length();
    len--;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != str[len])
            return false;
        len--;
    }
    return true;
}

void printSolution(vector<vector<string>> partitions)
{
    for (int i = 0; i < partitions.size(); ++i)
    {
        for (int j = 0; j < partitions[i].size(); ++j)
            cout << partitions[i][j] << " ";
        cout << endl;
    }
    return;
}

// Goes through all indexes and recursively add remaining
// partitions if current string is palindrome.
void addString(string &s, vector<vector<string>> &ans, vector<string> &temp, int ind)
{
    string str;
    vector<string> current = temp;
    for (int i = ind; i < s.length(); i++)
    {
        str = str + s[i];
        if (checkPalindrome(str))
        {
            temp.push_back(str);
            if (i + 1 < s.length())
                addString(s, ans, temp, ind + 1);
            else
            {
                ans.push_back(temp);
            }
            temp = current;
        }
    }
}
// Generates all palindromic partitions of 's' and
// stores the result in 'v'.
void partition(string s, vector<vector<string>> &v)
{
    vector<string> temp;
    addString(s, v, temp, 0);
    printSolution(v);
    return;
}

// Driver code
int main()
{
    string s = "aabbbaa";
    vector<vector<string>> partitions;
    partition(s, partitions);
    return 0;
}
