class Solution {
public:
    string longestPalindrome(string s) {
     int start,end;
        int currlen = 0;
        int maxlen = 0;
        int maxidx = 0;
        int i = 0;
        while(i < s.size()){
            start = i;
            end = i;
         //case for even palindrome expand end
         while(end+1 < s.size() and s[end] == s[end+1]){
             end++;             
         }
            i = end + 1;
        //general case expand start and end while its a palindrome
            while(start-1 >= 0 and end+1 <= s.size()-1 and s[start-1] == s[end+1]){
                start--;
                end++;
            }
            
            int currlen = end - start + 1;
            if(currlen > maxlen){
                maxidx = start;
                maxlen = currlen;
            } 
        }  
     return s.substr(maxidx,maxlen);   
    }
};