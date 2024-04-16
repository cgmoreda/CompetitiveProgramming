class Solution {
public:
    string reverseWords(string s) {
        stringstream line(s);
        vector<string>words;
        string x;
        while(line>>x)
            words.push_back(x);
        s="";
        int z=0;
        reverse(words.begin(),words.end());
        for(auto &i:words)
        {
            if(z++)
                s+=" ";
            s+=i;
        }
        return s;
    }
};