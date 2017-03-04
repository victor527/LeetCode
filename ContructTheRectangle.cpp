class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L, W;
        vector<int> result;
        L = sqrt(area);
        for(L = sqrt(area); L <= area; L++){
            W = area / L;
            if(area == L * W && L >= W){
                result = {L, W};
                return result;
            }
        }
        return result;
    }
};