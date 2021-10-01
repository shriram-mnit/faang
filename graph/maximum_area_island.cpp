class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int n=g.size();
        int m1=g[0].size();
        map<pair<int,int> ,list<pair<int,int>>>m;
        vector<vector<int>>vec(n,vector<int>(m1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m1;j++)
            {
                if(g[i][j]==1)
                {
                    if(i-1>=0 && g[i-1][j])
                        m[{i,j}].push_back({i-1,j});
                    if(i+1<n && g[i+1][j])
                        m[{i,j}].push_back({i+1,j});
                    if(j-1>=0 && g[i][j-1])
                        m[{i,j}].push_back({i,j-1});
                    if(j+1<m1 && g[i][j+1])
                        m[{i,j}].push_back({i,j+1});
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m1;j++)
            {
                if(g[i][j] && !vec[i][j])
                {
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vec[i][j]=1;
                    int cn=0;
                    while(!q.empty())
                    {
                        pair<int,int> p=q.front();
                        q.pop();
                        cn++;
                        for(auto x:m[p])
                        {
                            int a=x.first,b=x.second;
                            if(!vec[a][b])
                            {
                                q.push(x);
                                vec[a][b]=1;
                            }
                        }
                            
                    }
                    maxi=max(cn,maxi);
                }
            }
        }
        return maxi;
        
    }
};
