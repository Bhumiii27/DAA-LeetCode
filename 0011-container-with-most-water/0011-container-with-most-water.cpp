class Solution {
public:
    int maxArea(vector<int>& height) {
      int  n = height.size();
        int maxWt= 0; //max water
      int lp = 0, rp = n - 1;
      while(lp<rp) {
        int w = rp - lp;
        int ht = min(height[lp], height[rp]); //min height
        int currWt = w*ht; //width*height
        maxWt = max(maxWt, currWt); //max water
        height[lp] < height[rp] ? lp++ : rp--; //if left ht is less try next left ht
      }
      return maxWt;
    }
};