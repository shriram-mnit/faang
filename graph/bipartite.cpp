class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<string> col(n,"white");
        queue<int> q;
        for(int d=0;d<n;d++)
        { if(col[d]=="white")
        {q.push(d);
        col[d]="red";
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            for(auto x:graph[i])
            {
                if(col[x]=="white")
                {
                    q.push(x);
                    if(col[i]=="red" )
                    col[x]="while";
                    else
                        col[x]="red";
                }
                else
                {
                    if(col[i]==col[x])
                        return false;
                }
            }
            
        }}}
        return true;
        
    }
};
