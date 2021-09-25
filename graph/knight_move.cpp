class Solution 
{
    public:
    struct data{
        int x,y,d;
    };
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &k,vector<int> &t,int n)
	{
	    int dx[]={2,2,-2,-2,1,1,-1,-1};
	    int dy[]={1,-1,1,-1,2,-2,2,-2};
	    queue<data> q;
	    q.push({k[0],k[1],0});
	    vector<vector<int>> visited;
	    for(int i=0;i<=n;i++){
	        vector<int> temp(n+1,0);
	        visited.push_back(temp);
	    }
	    visited[k[0]][k[1]]=1;
	    while(!q.empty()){
	        data f=q.front();
	        q.pop();
	        if(f.x==t[0]&&f.y==t[1]) return f.d;
	        for(int i=0;i<8;i++){
	            int x=f.x+dx[i],y=f.y+dy[i];
	            if(x>0&&x<=n&&y>0&&y<=n&&!visited[x][y]){
	                visited[x][y]=1;
	                q.push({x,y,f.d+1});
	            }
	        }
	    }
	    return 1;
	}
};
