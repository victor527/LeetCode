// Forward declaration of isBadVersion API.
// Trial 1 with O(logN) with iteration from the middle to find the first bad version
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(isBadVersion(mid) == false) 
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

// Trial 2 with recursive function to get the final value
class Solution {
public:
    int firstBadVersion(int n) {
        return recur(1, n);
    }
    
    int recur(int left, int right){
        int mid = left + (right - left) / 2;
        if(isBadVersion(mid) == false){
            if(mid == left)
                return right;
            return recur(mid + 1, right);
        }
        else{
            if(mid == left)
                return mid;
            return recur(left, mid);
        }
    }
};