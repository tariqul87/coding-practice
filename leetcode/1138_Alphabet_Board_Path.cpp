#include "array.cpp"


class Solution {
public:
    string alphabetBoardPath(string target) {
        char current = 'a';
        string path = "";
        
        for(char ch: target) {
            if (current == 'z' && ch != 'z') {
                path.push_back('U');
                current = 'u';
            }
            
            for(;;) {
                int indexReminder = (current - 'a') % 5;
                int targetIndexReminder = (ch - 'a') % 5;
                
                if (indexReminder > targetIndexReminder) {
                    path.push_back('L');
                    current--;
                } else if (indexReminder < targetIndexReminder) {
                    path.push_back('R');
                    current++;
                } else {
                    break;
                }
            }
            
            for(;;) {
                int indexRow = (current - 'a') / 5;
                int targetIndexRow = (ch - 'a') / 5;
                
                if (indexRow > targetIndexRow) {
                    path.push_back('U');
                    current -= 5;
                } else if (indexRow < targetIndexRow) {
                    path.push_back('D');
                    current += 5;
                } else {
                    break;
                }
            }
            
            path.push_back('!');
            current = ch;
        }
        
        return path;
    }
};