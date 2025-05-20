class Solution {
  public:
    int findMaxDistance(map<Node*, Node*>& mp, Node* result){
        queue<Node*> q;
        map<Node*, bool> visited;
        int totalTime=0;
        visited[result] = true;
        q.push(result);
        while(!q.empty()){
            int size = q.size();
            int flag=0;
            while(size--){
                Node* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    visited[node->left]=true;
                    q.push(node->left);
                    flag=1;
                }
                if(node->right && !visited[node->right]){
                    visited[node->right]=true;
                    q.push(node->right);
                    flag=1;
                }
                if(mp[node] && !visited[mp[node]]){
                    visited[mp[node]]=true;
                    q.push(mp[node]);
                    flag=1;
                }
            }
            if(flag==1) totalTime++;
        }
        return totalTime;
    }
    Node* bfsToFindParent(Node* root, int target, map<Node*, Node*>& mp){
        queue<Node*> q;
        Node* res;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node->data==target){
                res = node;
            }
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
        
    }
    int minTime(Node* root, int target) {
        // code here
        map<Node*, Node*> parentMap;
        Node* resultNode = bfsToFindParent(root, target, parentMap);
        int minimumTime = findMaxDistance(parentMap, resultNode);
        return minimumTime;
    }
};
