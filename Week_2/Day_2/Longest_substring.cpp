   #include<iostream>
   #include<string>
   #include<unordered_set>
   using namespace std;
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int left=0;
        int maxlen=0;
        for(int right=0;right<s.length();right++){
            while(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxlen= max(maxlen,(right-left)+1);
        }
       return maxlen;
    }
    int main(){
     string s="abcabcbb";
     int ans =lengthOfLongestSubstring(s);
     cout<<"length Of Longest Substring is : "<<ans;
        return 0;
    }