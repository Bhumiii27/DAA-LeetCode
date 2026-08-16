class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() < 2)
            return "";

        set<char> letters;
        for(char c : s)
            letters.insert(c);

        for(int i = 0; i < s.size(); i++) {
            if(letters.count(tolower(s[i])) == 0 || letters.count(toupper(s[i])) == 0) {

                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));

                if(left.size() >= right.size())
                    return left;
                else
                    return right;
            }
        }

        return s;
    }
};