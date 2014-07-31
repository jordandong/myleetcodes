//============================================================================
// Text Justification
// Given an array of words and a length L, format the text such that each line
// has exactly L characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words
// as you can in each line. Pad extra spaces ' ' when necessary so that each
// line has exactly L characters.
//
// Extra spaces between words should be distributed as evenly as possible. If
// the number of spaces on a line do not divide evenly between words, the empty
// slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is
// inserted between words.
//
// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
//
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.
//
// Corner Cases:
// A line other than the last line might contain only one word. What should
// you do in this case?
// In this case, that line should be left-justified.
//============================================================================


class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        if(words.size() == 0 || L <= 0) {
            result.push_back("");
            return result;
        }
        
        int N = words.size();
        int start = 0;
        int end = 0;
        while (end < N)  {
            // justify one line
            vector<int> spaces;
            int length = words[start].size();//one word, this length must be less than L
            end = start+1;
            while (end < N) {
                int M = words[end].size();
                if (length + 1 + M > L)
                	break;
                length += 1 + M; //one more word is the total length is less than L
                spaces.push_back(1); // add a space before words, starting from the second
                end++;
            }//now end is the start position of the next line
            
            int rest = L-length;
            if (spaces.size() == 0 || end == N) { //only one word in this line or this is the last line
                spaces.push_back(rest); //push all the spaces back
            } else {// the line int middle with full words
                int j = 0;
                while (rest > 0) {
                    spaces[j++] += 1;
                    if (j == spaces.size())//distribute all the spaces after each words
                    	j = 0;
                    rest--;
                }
                spaces.push_back(0);//add 0 spaces after the last word
            }
            // append one line
            string line = "";
            for (int i = start; i < end; i++) {
                line.append(words[i]); // append word
                for (int j = 0; j < spaces[i-start]; j++)
                    line.push_back(' '); // append spaces after this word
            }
            result.push_back(line);//append this line
            start = end;//go to next line
        }
        return result;
    }
};
