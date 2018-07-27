{
#include <bits/stdc++.h>
using namespace std;
int isValid(char *);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		char s[10000];
		cin>>s;
		cout<<isValid(s)<<endl;
	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
bool isValid(string str)
{
    if(str.length() > 3 || stoi(str) > 255 || stoi(str) < 0)
    {
        return false;
    }
    if(str.length() > 1 && str[0] == '0')
    {
        return false;
    }
    return true;
}
int isValid(char *ip)
{
      //your code here
      string str = "";
      for(int iter = 0; ip[iter] != '\0'; iter++)
      {
          str = str + ip[iter];
      }

      if(str[str.length()-1] == '.')
      {
          return 0;
      }
      stack<string> st;
      string s = "";
      for(string::size_type iter = 0; iter < str.length(); iter++)
      {
          if(str[iter] == '.')
          {
              if(s.length() == 0)
              {
                  return 0;
              }
              else
              {
                  st.push(s);
                  s = "";
              }
          }
          else
          {
              if(isdigit(str[iter]))
              {
                  s = s+str[iter];
                  if(iter == str.length()-1)
                  {
                      st.push(s);
                  }
              }
              else
              {
                  return 0;
              }
          }
      }
      if(st.size() < 4 || st.size() > 4)
      {
          return 0;
      }
      while(!st.empty())
      {
         if(!isValid(st.top()))
         {
             return 0;
         }
         st.pop();
      }
      return 1;
}
