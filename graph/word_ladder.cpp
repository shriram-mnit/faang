class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string,list<string>> m;
        for(int i=0;i<wordList.size();i++)
        {
            for(int j=0;j<i;j++)
            { int cn=0;
                for(int k=0;k<wordList[i].size();k++)
                {
                     if(wordList[j][k]!=wordList[i][k])
                          cn++;
                }
             if(cn==1)
             {
                m[wordList[i]].push_back(wordList[j]);
                m[wordList[j]].push_back(wordList[i]);
             }
            }
        }
        queue<string> q;
        q.push(beginWord);
        map<string ,int> v;
        q.push("");
        v[beginWord]=1;
        int x=1,ans=-1;
        while(!q.empty())
        {
            string s=q.front();
            q.pop();
            if(s=="")
            {
                x++;
                if(!q.empty())
                    q.push("");
                continue;
            }
            if(s==endWord)
                ans=x;
            
            for(auto d:m[s])
            {
                if(v[d]==0)
                {q.push(d);
                    v[d]=1;
                 
                }
            }
            
        }
        if(ans!=-1)
            return ans;
        else
           return 0;
    }
};
