class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int skipd=0,skipr=0,score=0;
        int og=senate.size();
        char last='R';
        for(int j=0;j<senate.size();j++){
            char i = senate[j];
            if(skipd==og)
                return "Radiant";
            if(skipr==og)
                return "Dire";
            if(i=='D')
            {
                if(skipd>0)
                {
                    skipd--;
                }
                else {
                    skipr++;
                    senate.push_back(i);
                }
            }
            if(i=='R')
            {
                if(skipr>0)
                {
                    skipr--;
                }
                else {
                    skipd++;
                    senate.push_back(i);
                }
            }
        }
        return "X";
    }
};