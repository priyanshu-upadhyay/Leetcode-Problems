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
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* start = NULL;
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();
            if(front == NULL) continue;
            vector<Node*> front_neighbours = front->neighbors;
            
            int n = front_neighbours.size();
            
            if(mp.find(front) == mp.end())
            {
                Node* newnode = new Node(front->val);
                mp[front] = newnode;
            }
            
            vector<Node*> newnode_neighbours(n);
            for(int i = 0; i < n; i++)
            {
                if(mp.find(front_neighbours[i]) == mp.end())
                {
                    Node* neighbour_node = new Node(front_neighbours[i]->val);
                    mp[front_neighbours[i]] = neighbour_node;
                    q.push(front_neighbours[i]);
                }
                newnode_neighbours[i] = mp[front_neighbours[i]];
            }
            if(start == NULL) start = mp[front];
            mp[front]->neighbors = newnode_neighbours;
        }
        return start;
    }
};