#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  List *history = init_history(); // Initiates history list
  char **tokens, str[32], c;

  //Generate UI Shape(curtains)
  int i, x, y, n = 7,idx = 0;
  for (x=1; x<=n; x++){
    for (y=1; y<=(2*n); y++){
      if (x>(n-y+1))
	printf(" ");
      else
        printf("*");
      if ((x+n)>y)
	printf(" ");
      else
	printf("*");
    }
    printf("\n");
  }
  printf("\t Tokenizer!");
  printf("\n----------------------------\n");
  printf("Commands: 0 to exit\n");
  printf("          1 to view history\n");
  printf("          !n to print history[n]\n");
  printf("Enter a phrase\n");

  while (1) {                          //Keep active loop
    printf("\n|=> ");
    i = 0;
    while ( (c = getchar()) != '\n') { // keep storing until enter/return key
      str[i] = c;                     
      i++;
    }
    str[i] = '\0';                     // terminate string

    printf("\nIn: %s\n",str);
    
    switch(*str){
    case '0':
      printf("\n\t  Good-Bye!\n");
      for(x = 1; x < n; x++){
	for(y = 1; y <= (2*n); y++){
	  if(x < y)
	    printf(" ");
	  else
	    printf("*");
	  if(x <= ((2*n) - y))
	    printf(" ");
	  else
	    printf("*");
	}
	printf("\n");
      }
      free_history(history);
      exit(0);
    case '1':
      print_history(history);
      break;
    case 33:
      idx  = atoi(str+1);          // convert n to int
      printf("%s", get_history(history,idx)); //print history[n]
      break;
    default :
      tokens = tokenize(str);  // tokenize
      print_tokens(tokens);   // print tokenized input
      free_tokens(tokens);
      add_history(history,copy_str(str,i)); // adds input to history list
    }
  }
  free_history(history);  
  return 0;
}
