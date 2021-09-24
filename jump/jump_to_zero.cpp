class Solution {
public:
    bool canReach(vector<int>& a, int inti) {
         vector<int> zero;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==0)
         zero.push_back(i);
         
    }
   unordered_map<int,list<int>> m;
   for(int i=0;i<a.size();i++)
    {
        
        if(i+a[i]>=0 && i+a[i]<a.size())
          m[i].push_back(i+a[i]);
        if(i-a[i]>=0 && i-a[i]<a.size())
          m[i].push_back(i-a[i]);
    }
    vector<bool> visi(a.size(),false);
    queue<int> q;
    q.push(inti);
    visi[inti]=true;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto x:m[t])
        {
            if(!visi[x])
            {
                q.push(x);
                visi[x]=true;
            }
        }
    }
    for(int i=0;i<zero.size();i++)
     {
         if(visi[zero[i]]==true)
         return true;
     }
return false;
        
    }
};
