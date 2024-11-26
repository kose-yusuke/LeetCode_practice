class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_str_len = 0;
        int s_len = s.length();
        unordered_map<char, int> charIndexMap;
        int start=0;
        if (s.empty())
            return (0);
        else if (s_len == 1)
            return (1);
        for (int end=0; end<s_len; end++)
        {
            char currentChar = s[end];
            // currentCharがMap内かつ範囲内にある. 
            if (charIndexMap.find(currentChar) != charIndexMap.end()
                && charIndexMap[currentChar] >= start){
                    //重複したら, start位置を前に出す
                    start = charIndexMap[currentChar] + 1;
            }
            // currentCharの位置を設定(重複した場合は新しい位置に再設定)
            charIndexMap[currentChar] = end;
            // 重複あった場合はstartが1個前に出てるから変わらないはず
            max_str_len = max(max_str_len, end - start + 1);
        }
        return (max_str_len);
    }
};