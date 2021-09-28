class Solution {
public:
    vector<int> findOrder( int nc, vector<vector<int>>dl)
{
	vector<int> def(nc,0);
	unordered_map<int,list<int>> m;
	for(int i=0;i<dl.size();i++)
	{
		int a=dl[i][0],b=dl[i][1];
		m[b].push_back(a);
		def[a]++;
	}
	queue<int>q;
	for(int i=0;i<nc;i++)
	{
		if(def[i]==0)
		{q.push(i);
		}
	}
	int er=0;
	vector<int> ord;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		ord.push_back(t);
		for(auto ch:m[t])
		{
			def[ch]--;
			if(def[ch]==0)
				q.push(ch);
			er++;
		}
	}
	if(er==dl.size())
		return ord;
    else 
		return {};
		    
}
};
