bool areAnagram(string s1,string s2)
{
    if(s1.length()!=s2.length()) return false;
    else
    {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1.compare(s2)==0) return true;
        else return false;
    }
}
