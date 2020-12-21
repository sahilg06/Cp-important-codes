/***************************************
//to check whether a string is whole number(without leading 0s)
bool isNumber(string s) 
{
    if(s=="0") return true;
    if(s[0]=='0') return false;
    For(i,0,sz(s)-1) 
    {
        if (isdigit(s[i]) == false)  return false;
    } 
    return true; 
}
******************************/