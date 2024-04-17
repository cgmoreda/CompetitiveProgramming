class Solution {
public:
    int compress(vector<char>& chars) {
        int sz=0,idx=0,cnt=1;
        char pr ='*';
        bool first = true;
        for(auto &i:chars)
        {
            if(first)
            {
                first = false;
                pr = i;
                cnt=1;
                continue;
            }
            if(i==pr)
            {
                cnt++;
            }
            else{
               
                chars[idx++] = pr;
                if(cnt!=1){
                    string num = to_string(cnt);
                    for(auto &j:num)
                        chars[idx++] =j; 
                }
                    
                pr=i;
                cnt=1;
            }
        }
        
        chars[idx++] = pr;
        if(cnt!=1){
            string num = to_string(cnt);
            for(auto &j:num)
                chars[idx++] =j; 
        }

        while(chars.size()>idx)
            chars.pop_back();
        return idx;
    }
};