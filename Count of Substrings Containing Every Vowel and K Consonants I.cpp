class Solution {
public:

    bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

    int countOfSubstrings(string word, int k) {
        int n = word.length();
    int count = 0;

    // Sliding window approach with two pointers
    for (int left = 0; left < n; ++left) {
        unordered_set<char> vowelSet;
        int consonantCount = 0;

        for (int right = left; right < n; ++right) {
            char currentChar = word[right];

            // If the current character is a vowel, add it to the vowel set
            if (isVowel(currentChar)) {
                vowelSet.insert(currentChar);
            } else {
                // If it's a consonant, increment the consonant count
                consonantCount++;
            }

            // If we have exactly k consonants and all vowels, this is a valid substring
            if (consonantCount == k && vowelSet.size() == 5) {
                count++;
            }

            // If consonant count exceeds k, no need to continue for this starting point
            if (consonantCount > k) {
                break;
            }
        }
    }

    return count;
    }
};
