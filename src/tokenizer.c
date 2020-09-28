#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define TRUE 1
#define FALSE 0



/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (c == ' ' || c == '\t')
    {
  return TRUE;
    }
  else
    {
   return FALSE;
    }
}


/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c) {
  if(c != ' ' && c != '\t') {
    return TRUE;
  }
  else {
   return FALSE;
  }
}



/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  char *tmp= str;
  while(*tmp != '0')
    {
      if((non_space_char(tmp[0])) == 1)
	{
	  return tmp;
        }
	tmp++;
    }
      return tmp;
}






/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while (non_space_char((*word)))
    {
      word++;
      if(space_char(*word))
	{
	  return word;
	}
    }
  return "0";
}


/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int count=0;
  int OUT= 0;
  int IN= 1;
  int state= OUT;

  while(*str)
    {
      if(*str == ' ' || *str == '\t' || *str == '\n')
	{
	  state= OUT;
	}
      else if (state == OUT)
	{
	  state = IN;
	  count++;
	}
      str++;
    }
  return count;
}



/* Returns a freshly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *copyStr;

  copyStr = (char*) malloc(sizeof(char) * (len+1));

  int i;
  for(i=0; i < len; i++)
    copyStr[i] =inStr[i];

  copyStr[i]='\0';

  return copyStr;
}


/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/ 
char **tokenize(char* str)
{
  int size= count_words(str);

  //allocate memory
  char** tokens= (char**) malloc(sizeof(char*) * (size +1));

  char* start=word_start(str);
  char* terminator= word_terminator(start);

  int i;
  for (i=0; i < size; i++)
    {
      if(i > 0)
	{
	  start = word_start(terminator);
	  terminator = word_terminator(start);
	}
      int size2= terminator - start;
      tokens[i]= malloc(size2 * sizeof(char));

      for (int j=0; j < size2; j++)
	{
	  tokens[i][j]= start[j];
	}
    }
  return tokens;
}


/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int i= 0;
  while(tokens[i] != NULL)
    {
      printf("token[%d] = %s\n", i, tokens [i]);
      i++;
    }
}


/* Frees all tokens and the vector containing them. */
  void free_tokens(char **tokens) {
  for(int i=0; tokens[i]; i++) { 
    free(tokens[i]);
  }
  free(tokens);
  }
