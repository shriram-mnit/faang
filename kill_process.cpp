vector<int> kill_process( vector <int> c,vector<int>p,int kill)
{
	unordered_map<int,list<int>> ma;
	vector<int> ans;
	for(int i=0;i<p.size();i++)
	{
		ma[p[i]].push_back(c[i]);
	}
	queue<int> q;
	q.push(kill);
	while(q.empty())
	{
		int k=q.top();
		q.pop();
		ans.push_back(k);
		for(auto i:ma[k])
			q.push(i);
		
	}
return ans;
}
	