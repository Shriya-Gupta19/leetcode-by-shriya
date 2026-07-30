class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        for(int x:students){
            q.push(x);
        }
        int count=0;
        int j=0;
        while(count<q.size()){
            if(q.front()==sandwiches[j]){
                q.pop();
                j++;
                count=0;
            }
            else{
                int temp=q.front();
                q.pop();
                q.push(temp);
                count++;
            }
        }
        return count;
    }
};