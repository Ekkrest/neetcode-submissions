class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        for(int i=0;i<s.length();i++){
            if(mp1.find(s[i]) != mp1.end()){
                mp1[s[i]] += 1;
            }else{
                mp1[s[i]] = 1;
            }
        }

        for(int j=0;j<t.length();j++){
            if(mp2.find(t[j]) != mp2.end()){
                mp2[t[j]] += 1;
            }else{
                mp2[t[j]] = 1;
            }
        }

        if(mp1 == mp2)
            return true;
        return false;
    }
};
