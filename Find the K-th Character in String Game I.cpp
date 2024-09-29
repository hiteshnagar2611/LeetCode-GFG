class Solution {
public:
    char kthCharacter(int k) {
        string word = "a"; // Initial word
    
    // Continue generating new words until the length is at least k
    while (word.length() < k) {
        string newWord = "";
        for (char c : word) {
            // Convert each character to its next in the alphabet
            if (c == 'z') {
                newWord += 'a'; // Wrap around after 'z'
            } else {
                newWord += char(c + 1);
            }
        }
        word += newWord; // Append the newWord to the original word
    }

    // Return the k-th character (0-indexed in C++)
    return word[k - 1];
    }
};
