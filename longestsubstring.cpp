//sliding window algorithm

class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        int n=st.length();
        if(n==1)
            return 1;
        set<char> s;
        int start=0,maxl=0;
        for(int i=0;i<n;){
            if(s.find(st[i])!=s.end()){
                s.clear();
                maxl=max(maxl,i-start);
                start++;
                i=start;
            }
            else{
                s.insert(st[i]);
                i++;
            }
        }
        return max(maxl,n-start) ;
    }
};
