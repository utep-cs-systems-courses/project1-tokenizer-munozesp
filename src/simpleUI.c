#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 1000

int main()
{
  char str[MAX];
  int condition=1;
  List *history= init_history();


  while (condition == 1)
    {
      printf("> ");
      fgets(str, MAX, stdin);
      if(*str== '@')
	{
	  int index= atoi(str+1);
	  char *prv_str=get_history(history, index);
	  if(prv_str != NULL)
	    {
	      printf("Item #%d: ", index);
	      printf(get_history(history, index));
	    }
	}
      if(*str != '@')
	{
	  char** tokens=tokenize(str);
	  print_tokens(tokens);
	  add_history(history, str);
	  free_tokens(tokens);
	}
      if (*str == '0')
	condition = 0;
      
    }
  print_history(history);
  free_history(history);
  return 0;
}
