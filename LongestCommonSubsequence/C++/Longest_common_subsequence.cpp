//Begin
//Take the array of strings as input.
//function matchedPrefixtill(): find the matched prefix between string s1 and s2 :
  // n1 = store length of string s1.
   //n2 = store length of string s2.
   //for i = 0, j = 0 to i <= n1 – 1 && j <= n2 - 1
     // if s1[i] != s2[j]
       //  break
    //  result.push_back(s1[i])
  // return result
//End
//Begin
//function matchedPrefix(): returns the longest matched prefix from the array of strings:
  // for int i = 1 to n - 1
    //     pre = matchedPrefixtill(pre, a[i])
   //return pre.
//End

#include<bits/stdc++.h>
using namespace std;

string matchedPrefixtill(string s1, string s2) {
   string res;
   int n1 = s1.length(); //store length of string s1.
   int n2 = s2.length(); //store length of string s2.
   for (int i = 0, j = 0; i <= n1 - 1 && j <= n2 - 1; i++, j++) {
      if (s1[i] != s2[j])
         break;
      res.push_back(s1[i]);
   }
   return (res);
}
string matchedPrefix (string a[], int n) {
   string pre = a[0];
   for (int i = 1; i <= n - 1; i++)
   pre = matchedPrefixtill(pre, a[i]);
   return (pre);
}
int main() {
   string a[] = {"Tutorialspoint", "Tutor", "Tutorials"}; //taking inputs
   int n = sizeof(a) / sizeof(a[0]);
   string res = matchedPrefix(a, n);
   if (res.length())
      cout<<"Longest common subsequence is matched - "<<res.c_str();
   else
      cout<<"No matched prefix";
   return (0);
}