class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<pair<long long,long long>> sd;
        for(auto i:meetings)
            sd.push_back({i[0],i[1]-i[0]});
        sort(sd.begin(),sd.end(),[&](pair<long long,long long> a,pair<long long,long long> b)
        {
            return a.first<b.first;
        });
        priority_queue<long long,vector<long long>,greater<>>time;
        queue<pair<long long,long long>>meet;
        for(auto i:sd)
        {
            meet.push(i);
            time.push(i.first);
        }    
        set<int>availableRooms;
        for(int i=0;i<n;i++)
            availableRooms.insert(i);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>fullRooms;
      
        map<int,long long>ans;
        
        for(long long i=0;!meet.empty();)
        {
            while(!fullRooms.empty()&&fullRooms.top().first<=i)
            {
                availableRooms.insert(fullRooms.top().second);
                fullRooms.pop();
            }
            while(!meet.empty()&&!availableRooms.empty()&&meet.front().first<=i)
            {
                long long duration = meet.front().second;
                int room  = *availableRooms.begin();
                availableRooms.erase(room);
                time.push(i+duration);
                fullRooms.push({i+duration,room});
                ans[room]++;
                meet.pop();
            }
            if(time.size()){
                i = time.top();
                time.pop();
            }
            else break;
        }
        long long mx = ans[0];
        for(auto i:ans)mx = max(i.second,mx);
        
        for(auto i:ans)
            if(i.second==mx)
                return i.first;
    return 0;
    }
};