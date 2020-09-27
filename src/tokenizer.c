#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

// 1 if char is space otherwise return 0
int space_char(char c)
{
  if ( (c == '\t' || c == ' ') && c != '\0') return 1;
  return 0;
}

// 1 if char is non space otherwise return 0
int non_space_char(char c)
{
  if ( (c !=  '\t' && c != ' ') && c != '\0') return 1;
  return 0;
}

// Pointer to "head" of word of s
char *word_start(char *s)
{
  int i = 0;

  while (space_char(s[i])) i++;
  return &s[i];
}

// Pointer to "tail" of word
char *word_terminator(char *word)
{
  int i = 0;

  word = word_start(word);// remove whitespace at begining of word

  while (non_space_char(word[i])) i++; // loop to find "tail"
  return &word[i];
}

// # of words in s
int count_words(char *s)
{
  int i = 0, words = 0;
  
  while(s != word_terminator(s)){
    s = word_terminator(s);
    words++;
  }

  return words;
}

//creates a copy of inStr 
char *copy_str(char *inStr, short len)
{
  char *copy = malloc((len + 1) * sizeof(char));
  int i = 0;

  while(i <= len){
    copy[i] = inStr[i];
    i++;
  }

  return copy;
}

//splits str by space char, storing each 'word' into an array of pointers(vector)
char **tokenize(char *str)
{
  int i, wordCount = count_words(str);
  char **vector = malloc((wordCount+1) * sizeof(char *));
  char *start_of_word = word_start(str), *end_of_word = word_terminator(str); // start,end pointers

  for (i = 0; i < wordCount; i++) { 
    vector[i] = copy_str(start_of_word,end_of_word-start_of_word);//copies current word into vector
    start_of_word = word_start(end_of_word); // find next start
    end_of_word = word_terminator(start_of_word); // find next end
  }

  vector[i] = NULL; // 'tail' is null to maintain proper word count
  return vector;
}

// Prints each word in vector(tokens)
void print_tokens(char **tokens)
{
  int i = 0;
  
  while (tokens[i] != NULL) {
    printf("%s\n", tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens)
{
  int i = 0;

  while (tokens[i] != NULL) {
    free(tokens[i]);
    i++;
  }
  
  free(tokens); // free the vector's allocated memory
}
