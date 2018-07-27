string Solution::addBinary(string a, string b)
{
     int mx = max(a.length(), b.length());
        if(mx > a.length())
        {
            a = string(mx-a.length(), '0') + a;
        }
        if(mx > b.length())
        {
            b = string(mx - b.length(), '0') + b;
        }
        string final(mx+1, '0');
        string::const_reverse_iterator iter = a.rbegin(), s = a.rend();
        string::const_reverse_iterator jter = b.rbegin();
        string::reverse_iterator fter = final.rbegin();
        char carry = 0;
        for(; iter != s; iter++, jter++, fter++)
        {
            char temp = (*iter - '0') + (*jter - '0') + carry;
            if(temp == 0)
            {
                carry = 0;
            }
            else if(temp == 1)
            {
                carry = 0;
            }
            else if(temp == 2)
            {
                carry = 1;
                temp = 0;
            }
            else if(temp == 3)
            {
                carry = 1;
                temp = 1;
            }
            *fter = temp + '0';
        }
        if(carry == 1)
        {
            final[0] = carry + '0';
        }
        else
        {
            return final.substr(1, final.length()-1);
        }
        return final;
}
