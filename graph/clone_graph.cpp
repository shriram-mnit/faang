/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<Node *,Node *> m;
        queue<Node *>q;
        q.push(node);
        m[node]=new Node(node->val);
        Node *head=m[node];
        while(!q.empty())
        {
            Node * tmp=q.front();
            q.pop();
            for(int i=0;i<(tmp->neighbors).size();i++)
            {  Node * x=(tmp->neighbors)[i];
                if(m[x]==NULL)
            { q.push(x);
            m[x]=new Node(x->val);
             
            }
             (m[tmp]->neighbors).push_back(m[x]);
            }
        }
        return m[node];
        
    }
};
