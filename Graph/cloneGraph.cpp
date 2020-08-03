//https://leetcode.com/problems/clone-graph/

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
        
        if(!node) return NULL;
        
        map <Node*, bool> vis;   //keep track of explored nodes
        map <Node*, Node*> NtoN; // node to node mapping
        queue <Node*> Q;
        Node *ans;
        Q.push(node);
        
        //for reference node/first node
        Node *first = new Node(node -> val);
        NtoN[node] = first;
        vis[node] = true;
        
        while(!Q.empty()) {
            
            Node *curr = Q.front();
            Q.pop();
           
            Node *clone = NtoN[curr];
            
            for(auto adj : curr -> neighbors) {
                //add to queue only when the node is not explored
                if(!vis[adj]) {
                    Q.push(adj);
                    vis[adj] = true;
                }
                
                //if the clone node is not yet created
                //then create the node & add mapping
                if(!NtoN[adj]) {
                    Node* temp = new Node(adj -> val);
                    NtoN[adj] = temp;
                }
                
                clone -> neighbors.push_back(NtoN[adj]);
            }
            
        }
        
        return first;
    }
};
