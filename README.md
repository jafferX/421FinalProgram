# 421FinalProgram

This project required us to design and implement a scanner, parser, and translator for Japanese romaji into english.

For the scanner, we had to develop DFA's for nearly all Japanese syllables. Pre-defined words are hard coded into a dictionary array and provide a basis for most basic Japanese sentences. If a word is found to be in this array it is assigned the relevant type found next to the word in the array. If it is not found in the array but is a valid word it is assigned type WORD1. If the word has an uppercase letter as the last character in the word it is WORD2, or a verb root. If the word is not made of Japanese syllables it is marked as ERROR.

For the parser, ...
