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
            if(!node){
                return NULL;
            }
            unordered_map<Node*,Node*>clone;
            clone[node]=new Node(node->val);
            queue<Node*>q;
            q.push(node);   

            while(!q.empty()){
                Node* temp=q.front();
                q.pop();

                for(Node* nei:temp->neighbors){
                    if(clone.find(nei)==clone.end()){
                        clone[nei]=new Node(nei->val);
                        q.push(nei);
                    }
                    clone[temp]->neighbors.push_back(clone[nei]);
                }
            }

            return clone[node];

    }
};







