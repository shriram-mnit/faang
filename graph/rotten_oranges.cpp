class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>>v(grid.size());
        int n=grid.size(),m=grid[0].size();
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {   
                if(grid[i][j])
                    count++;
                if(grid[i][j]==2)
                {q.push({i,j});
                 v[i].push_back(1);
                }
                else
                    v[i].push_back(0);
            }
        }
        q.push({-1,-1});
        int d=0,cn=0;
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first,y=p.second;
            if(x==-1&& y==-1)
            {
                if(!q.empty())
                {q.push({-1,-1});
                 d++;}
             
                continue;
            }
            cn++;
            if(x-1>=0)
            {   if(grid[x-1][y])
                grid[x-1][y]++;
                if(!v[x-1][y] && grid[x-1][y]==2)
                {
                    v[x-1][y]=1;
                    q.push({x-1,y});
                }
            }
            if(x+1<n)
            {   if(grid[x+1][y])
                grid[x+1][y]++;
                if(!v[x+1][y] && grid[x+1][y]==2)
                {
                    v[x+1][y]=1;
                    q.push({x+1,y});
                }
                
            }
            if(y-1>=0)
            {   if(grid[x][y-1])
                grid[x][y-1]++;
                if(!v[x][y-1] && grid[x][y-1]==2)
                {
                    v[x][y-1]=1;
                    q.push({x,y-1});
                }
            }
            if(y+1<m)
            {   if(grid[x][y+1])
                grid[x][y+1]++;
                if(!v[x][y+1] && grid[x][y+1]==2)
                {
                    v[x][y+1]=1;
                    q.push({x,y+1});
                }
            }
        }
        if(cn==count)
        return d;
        else 
            return -1;
    }
};
