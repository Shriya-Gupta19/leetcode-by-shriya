class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>f;
        for(int i:nums){
            int r=((i%value)+value)%value;
            f[r]++;
        }
        int x=0;
        while(true){
            int r=x%value;
            if(f[r]>0){
                f[r]--;
            }
            else return x;
            x++;
        }
    }
};