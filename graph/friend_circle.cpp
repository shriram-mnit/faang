class Solution {
public:
    
    void dfsH(map<int,list<int>> m,map<int,bool> &vi,int i)
    {
        vi[i]=true;
        for(auto x:m[i])
        {
            if(!vi[x])
            {
                dfsH(m,vi,x);
            }
        }
    }
    int dfs(map<int,list<int>> m,int n)
    {
        map<int,bool> vi;
        for(int i=0;i<n;i++)
            vi[i]=false;
        int comp=0;
        for(int i=0;i<n;i++)
        {
            if(!vi[i])
            {dfsH(m,vi,i);
            comp++;}
        }
        return comp;
    }
    int findCircleNum(vector<vector<int>>& isC) {
        map<int,list<int>> m;
        int n=isC.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isC[i][j])
                    m[i].push_back(j);
            }
        }
        return dfs(m,n);
        
    }
};
