class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map<char,int>mp;
        for(char a='a';a<='z';a++)mp[a]=100;
        for(auto i:words)
        {
            for(char a='a';a<='z';a++)
                mp[a] = min(mp[a],(int)count(i.begin(),i.end(),a));
        }
        vector<string>ret;
        for(auto [key,val]:mp){
           string x="";
           x+= key;
            while(val-->0)ret.push_back(x);   
        }
        return ret;
    }
};