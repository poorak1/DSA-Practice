class Solution {
  public:
    int myAtoi(string& s) {
        // code here
        int sign = 1; 
        long final = 0;
        int i=0;

        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return 0;

        if(s[i] == '-' && i<s.size()){
            i++;
            sign = -1;
        }else if(s[i]=='+'){
            i++;
            }

        while(i<s.size() && isdigit(s[i])){
            final = final*10 + (s[i] - '0');

            if (sign * final > INT_MAX) return INT_MAX;
            if (sign * final < INT_MIN) return INT_MIN;

            i++;
        }
        return (int)(sign*final);
    }
};