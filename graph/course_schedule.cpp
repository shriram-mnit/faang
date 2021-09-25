class Solution {
public:
    bool canFinish(int nC, vector<vector<int>>& pre) {
        vector<int> dg(nC,0);
        unordered_map<int,list<int>>m;
        for(int i=0;i<pre.size();i++)
        {
            dg[pre[i][1]]++;
            m[pre[i][0]].push_back(pre[i][1]);
        }
        queue<int> q;
        for(int i=0;i<nC;i++)
        {
            if(dg[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(auto x:m[t])
            {
                dg[x]--;
                if(dg[x]==0)
                     q.push(x);
            }
        }
        for(int i=0;i<nC;i++)
        {
            if(dg[i]!=0)
                return false;
       }
        
        return true;
    }
};
