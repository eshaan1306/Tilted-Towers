class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int> freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }
        string cur;
        for(int i=0;i<n;i++){
            //that element exists
            if (freq[target[i]-'a']){
                freq[target[i]-'a']--;
                cur.push_back(target[i]);
            }
            //elements not here
            else{
                //find the first greatest if there
                bool flag=false;
                for(char j=target[i];j<='z';j++){
                    if (freq[j-'a']){
                        cur.push_back(j);
                        freq[j-'a']--;
                        flag=true;
                        break;
                    }
                }
                if (flag){
                    //now for the remaining, add in sorted order
                    for(int j=0;j<26;j++){
                        for(int iter=0;iter<freq[j];iter++){
                            cur.push_back('a'+j);
                        }
                    }
                    //ans is done
                    return cur;
                }
                //we dont have anything so we would have to go backward
                int indx=i-1;
                while(indx>=0){
                    cur.pop_back();
                    freq[target[indx]-'a']++;
                    bool found=false;
                    for(char j=target[indx]+1;j<='z';j++){
                        if (freq[j-'a']){
                            cur.push_back(j);
                            freq[j-'a']--;
                            found=true;
                            break;
                        }
                    }
                    if (found){
                        for(int j=0;j<26;j++){
                            for(int iter=0;iter<freq[j];iter++){
                                cur.push_back('a'+j);
                            }
                        }
                        //ans is done
                        return cur;
                    }
                    indx--;
                }
                return "";
            }
        }
        //if we are here, that means s == target 
        //so we follow the same procedure of going backwards
        int indx=n-1;
        while(indx>=0){
            cur.pop_back();
            freq[target[indx]-'a']++;
            bool found=false;
            for(char j=target[indx]+1;j<='z';j++){
                if (freq[j-'a']){
                    cur.push_back(j);
                    freq[j-'a']--;
                    found=true;
                    break;
                }
            }
            if (found){
                for(int j=0;j<26;j++){
                    for(int iter=0;iter<freq[j];iter++){
                        cur.push_back('a'+j);
                    }
                }
                //ans is done
                return cur;
            }
            indx--;
        }
        return "";
    }
};
