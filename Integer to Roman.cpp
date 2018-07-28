string Solution::intToRoman(int A) {
    vector<char> vc;
    vc.push_back('I');
    vc.push_back('V');
    vc.push_back('X');
    vc.push_back('L');
    vc.push_back('C');
    vc.push_back('D');
    vc.push_back('M');
    int i = 0;
    string str = "";
    while(A > 0)
    {
        int rem = A%10;
        if(rem <= 3)
        {
            for(int iter = 0; iter < rem; iter++)
            {
                str = vc[i] + str;
            }
        }
        else if(rem == 4)
        {
            str = vc[i+1] + str;
            str = vc[i] + str;
        }
        else if(rem > 4 && rem < 9)
        {
            for(int iter = 5; iter < rem; iter++)
            {
                str = vc[i] + str;
            }
            str = vc[i+1] + str;
        }
        else if(rem == 9)
        {
            str = vc[i+2] + str;
            str = vc[i] + str;
        }
        i += 2;
        A /= 10;
    }
    return str;
}
