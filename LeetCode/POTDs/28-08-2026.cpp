class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        vector<int> freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }
        int cnt=0;
        string cur;
        for(auto &x:freq){
            if (x&1){
                cnt++;
            }
        }
        //palindrome not possible
        if (cnt>=2){
            return cur;
        }
        /*
        if n is odd, that means the element with freq == 1
        should be at the end 
        */
        char last = '?';
        for(char ch='a';ch<='z';ch++){
            if (freq[ch-'a']&1){
                last=ch;
                break;
            }
        }
        for(int i=0;i<26;i++){
            freq[i]/=2;
        }
        for(int i=0;i<n/2;i++){
            //element exists
            if (freq[target[i]-'a']){
                cur.push_back(target[i]);
                freq[target[i]-'a']--;
            }
            //this element doesnt exist
            else{
                bool flag=false;
                for(char ch=target[i]+1;ch<='z';ch++){
                    if (freq[ch-'a']){
                        cur.push_back(ch);
                        freq[ch-'a']--;
                        flag=true;
                        break;
                    }
                }
                if (flag){
                    for(char ch='a';ch<='z';ch++){
                        for(int iter=0;iter<freq[ch-'a'];iter++){
                            cur.push_back(ch);
                        }
                    }
                    string ans = cur;
                    if (last != '?'){
                        ans.push_back(last);
                    }
                    reverse(cur.begin(),cur.end());
                    ans += cur;
                    return ans;
                }
                //here we will moe backward until we find
                int indx=i-1;
                while(indx>=0){
                    freq[target[indx]-'a']++;
                    cur.pop_back();
                    bool found=false;
                    for(char ch=target[indx]+1;ch<='z';ch++){
                        if (freq[ch-'a']){
                            freq[ch-'a']--;
                            cur.push_back(ch);
                            found=true;
                            break;
                        }
                    }
                    if (found){
                        for(char ch='a';ch<='z';ch++){
                            for(int iter=0;iter<freq[ch-'a'];iter++){
                                cur.push_back(ch);
                            }
                        }
                        string ans = cur;
                        if (last != '?'){
                            ans.push_back(last);
                        }
                        reverse(cur.begin(),cur.end());
                        ans += cur;
                        return ans;
                    }
                    indx--;
                }
                return "";
            }
        }
        /*
        again, if we are here that means uptil now cur is our target
        so for last != '?, a single check and save us
        or we again go backwards until we find something 
        */
        /*
        here we missed an edge case, for even
        when the first half is already greater than the target if 
        combined, so we can just combine these two last and even edge cases
        */
        string temp = cur;
        string rev = cur;
        if (last != '?'){
            temp.push_back(last);
        }
        reverse(rev.begin(),rev.end());
        temp += rev;
        if (temp > target){
            return temp;
        }
        int indx=(n/2)-1;
        while(indx>=0){
            freq[target[indx]-'a']++;
            cur.pop_back();
            bool found=false;
            for(char ch=target[indx]+1;ch<='z';ch++){
                if (freq[ch-'a']){
                    freq[ch-'a']--;
                    cur.push_back(ch);
                    found=true;
                    break;
                }
            }
            if (found){
                for(char ch='a';ch<='z';ch++){
                    for(int iter=0;iter<freq[ch-'a'];iter++){
                        cur.push_back(ch);
                    }
                }
                string ans = cur;
                if (last != '?'){
                    ans.push_back(last);
                }
                reverse(cur.begin(),cur.end());
                ans += cur;
                return ans;
            }
            indx--;
        }
        return "";
    }
};
