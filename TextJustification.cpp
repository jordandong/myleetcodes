/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.

Hide Tags String
*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int sz = words.size();
        vector<string> res;
        vector<int> spaces;
        int start = 0, end = 0;

        if(sz == 0 || L <= 0){
            res.push_back("");
            return res;
        }
        
        while(end < sz){
            spaces.clear();
            int wl = words[start].size();
            end = start + 1;
            while(end < sz){
                if(wl + 1 + words[end].size() > L)
                    break;
                wl += words[end].size() + 1;
                spaces.push_back(1);//one space added after the old word
                end++;
            }
            
            int left_spaces = L - wl;
            if(spaces.size() == 0 || end == sz){//only one word in line OR is the last line
                spaces.push_back(left_spaces);
            }else{
                int i = 0;
                while(left_spaces > 0){
                    spaces[i++] += 1;//distribute all the left spaces
                    i = (i == spaces.size() ? 0 : i);//reset i when the line is over
                    left_spaces--;
                }
                spaces.push_back(0); //add the space stat for the last word in the line 
            }
            
            string l = "";
            for(int i = start; i < end; i++){
                l += words[i];
                for(int j = 1; j <= spaces[i-start]; j++){
                    l += " ";
                }
            }
            res.push_back(l);
            start = end;//start a new line
        }
        return res;
    }
};
