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
        if (node == NULL)
            return NULL;
        unordered_map<Node*, Node*> mp;
        stack<Node*> st;
        Node* clone = new Node(node->val);
        mp[node] = clone;
        st.push(node);
        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();
            for (auto neighbour : curr->neighbors) {
                if (mp.find(neighbour) == mp.end()) {
                    mp[neighbour] = new Node(neighbour->val);
                    st.push(neighbour);
                }
                mp[curr]->neighbors.push_back(mp[neighbour]);
            }
        }
        return clone;
    }
};