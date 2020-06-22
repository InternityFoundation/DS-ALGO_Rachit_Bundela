//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3362/


class Solution {
public:
    
    bool check_ipv4(string s){
        s = s + '.';
        bool ans = true;
        long long n = s.size();
        string temp = "";
        long long val;
        long long dot_count = 0;
        for(int i = 0 ; i<n; i++){
            if(temp.size() > 3) return false;
            if(dot_count > 4) return false;
            if(s[i] == ':') return false;
            // cout<<i<<" "<<s[i]<<endl;
            if(!(s[i] - '0' >= 0 && s[i] - '0' <= 9 || (s[i] - '.' == 0 ) )) return false;
            if(s[i] == '.'){
                if(temp.size() == 0) return false;
                // cout<<temp.size()<<endl;
                
                dot_count++;
              val = stoi(temp);
                // cout<<temp<<endl;
                bool x;
                // bool x = (temp[0] == '0' && val != 0 && temp.size() != 1);
                if(temp[0] == '0'){
                    if(temp == "0")
                        x = true;
                    else
                        x = false;
                }
                else
                    x = true;
                temp = "";
                if(val >= 0 && val <= 255 && x) continue;
                else{
                    
                    ans = false; break;
                }
            }
            
            else
                temp += s[i];
        }
        if(dot_count != 4)
            ans = false;
        return ans;
        
    }
    
    
      bool check_ipv6(string s){
          s = s+':';
          long long n = s.size();
          string temp = "";
          long long val;
          bool ans = true;
          long long collon_count = 0;
          for(int i = 0 ; i<n;i++){
              if(collon_count > 8) return false;
              if(s[i] == '.') return false;
              long long ascii = s[i];
              long long asciinumber = ascii - '0';
              // cout<<s[i]<<" "<<ascii<<" "<<asciinumber<<endl;
              if(s[i] == ':'){
                  collon_count++;
                  // cout<<temp<<endl;
                  if(!(temp.size() > 0 && temp.size() <= 4))
                      return false;
                  temp = "";
                  continue;
              }
              temp += s[i];
                     
if(!((ascii >= 65 && ascii<=70) || (ascii >= 97 && ascii<=102) || (asciinumber >= 0 && asciinumber <= 9))){
       return false; 
    }
              
                    
          }
          if(collon_count != 8)
              return false;
          return true;
          
        
    }  

    string validIPAddress(string s) {
        if(check_ipv6(s))
            return "IPv6";
        // cout<<"h";
        if(check_ipv4(s))
            return "IPv4";
            
        else
            return "Neither";
            
        
    }
};
