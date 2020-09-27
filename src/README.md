Project 1: Tokenizer
====================
# Instructions:

> To compile: type command: make -f MakeFile.mk
>>>>>>>>>>>>> this inside of the src folder

> To run: type command: ./tokenize

> Enjoy using the tokenizer!

***********************************************

The purpose of the tokenizer program is to receive a string input from the
user and split that string based on space characters.

- The string is received, number of words are counted based on the space
  character before and after the words. Once the words are counted and array
  of pointers is made to store these individual words into. Once the words
  have been stored, they are sent to the history to keep a log of the strings
  that the user has passed. Finally the split string is displayed back to the
  user. Once the user exits the program, all allocated memory is freed.

- This can be thought of as the split() function in python/java.
