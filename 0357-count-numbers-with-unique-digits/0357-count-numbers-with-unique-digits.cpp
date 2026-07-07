class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int total=10;
        int count=9;
        for(int i=1;i<n;i++){
            count=count*(10-i);
            total+=count;
        }
        return total;
    }
};