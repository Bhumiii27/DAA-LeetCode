class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n==1)
            return {1};

        vector <int> result;

        //separate to even and odd first
        //beautiful array for Odd positions
        vector <int> odd= beautifulArray((n+1)/2);
        //convert to odd numbers
        for(int i=0;i<odd.size();i++){
            int x=odd[i];
            result.push_back(2*x-1);
        }
//i.e 1,3,2 --> 1,5,3
        //beautiful array for even positions
        vector <int> even= beautifulArray(n/2);
        //Convert to even numbers
        for(int i=0;i<even.size();i++){
            int x=even[i];
            result.push_back(2*x);
        }
// i.e 1,2---> 2,4
// final 1,5,3,2,4 instead of 1,3,2,1,2
        return result;
    }
};
