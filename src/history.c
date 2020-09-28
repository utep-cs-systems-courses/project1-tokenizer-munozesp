#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *list = (List *)malloc(sizeof(List));
  list->root=NULL;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  int count= 1; 
  char *temp= str;
  int i= 0;
  while(temp[i] != '\0')
    {
      i++;
    }

  Item *add_item= (Item*)malloc(sizeof(Item));
  add_item->str= copy_str(str, i);
  add_item-> next = NULL;
  if(list-> root == NULL)
    {
      list-> root= add_item;
      add_item->id= count;
    }
  else
    {
      Item *temp= list-> root;
      while(temp->next != NULL)
	{
	  count++;
	  temp= temp-> next;
	}
      temp->next= add_item;
      add_item->id=count;
    }
}


  
/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
if(list->root == NULL)
  {
    return "List is empty";
  }
 else
   {
     Item* temp= list-> root;

     while(temp != NULL)
       {
       if(temp->id == id)
	   {
	     return temp->str;
	   }
	 temp = temp->next;
       }
     return "Item ID not found\n";
   }
}


/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *temp=list->root;

  while(temp != NULL)
    {
      printf("Item [%d]: %s \n", temp->id, temp->str);
      temp=temp->next;
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
Item* temp;
Item* temp2;
temp2= list->root;

while(temp2 != NULL)
  {
    temp= temp2;
    temp2=temp2->next;
    free(temp);
  }
 free(list);
}
