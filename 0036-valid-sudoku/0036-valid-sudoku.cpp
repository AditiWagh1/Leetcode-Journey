class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        
        // Loop through every cell in the 9x9 board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char current_val = board[i][j];
                
                // We only care about cells that actually contain numbers
                if (current_val != '.') {
                    
                    // Convert the character number to a string fragment
                    string num = string(1, current_val);
                    
                    // Construct the three unique keys for Row, Column, and Sub-box
                    string row_key = num + " in row " + to_string(i);
                    string col_key = num + " in col " + to_string(j);
                    string box_key = num + " in box " + to_string(i / 3) + "-" + to_string(j / 3);
                    
                    // Attempt to insert into the set. 
                    // If .insert().second returns false, it means it's a duplicate!
                    if (!seen.insert(row_key).second || 
                        !seen.insert(col_key).second || 
                        !seen.insert(box_key).second) {
                        return false; 
                    }
                }
            }
        }
        
        return true;
    }
};