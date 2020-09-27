class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        set<string> s;
        bool flag = 0;
        
        for(auto word : wordList)
        {
            if(endWord.compare(word) == 0)
                flag = 1;
            
            s.insert(word);
        }
        
        if(!flag)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty())
        {
            depth++;
            
            int lsize = q.size();
            
            while(lsize--)
            {
                string curr = q.front();
                q.pop();
                
                for(int i=0;i<curr.length();i++)
                {
                    string temp = curr;
                    
                    for(char c='a';c<='z';c++)
                    {
                        temp[i] = c;
                        
                        if(curr.compare(temp) == 0)
                            continue;
                        if(temp.compare(endWord) == 0)
                            return depth+1;
                        
                        if(s.find(temp) != s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
        
    
};