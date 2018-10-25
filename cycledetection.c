#include <stdlib.h>
#include "graph.h"

void cycle_detection(graph *g) {
  
  linked_list *L;
  linked_list *S;
  
  int size = g->number_vertices;
  
  int i = 0;
  
  while(i < size) {
    
    vertex *v = &g->vertices[i];
    linked_list *in = v->in_neighbours;
    if(in->data == NULL && in->next == in){
      add_element(S,v);
    }
  i++;
  }
  
  while(linked_list_size(S) != 0) {
    add_element(L,S->data);
    remove_first(S);
    
    i = 0;
    while(i < size) {
      
      vertex *v = &g->vertices[i];
      linked_list *in = v->in_neighbours;
      
      int j = linked_list_size(in);
  	
      	while (j != 0) {
      		if (in->data == L->data) {
      			
      			remove_element(in,L->data);
      			if(linked_list_size(in) == 0) {
      			  add_element(S,v);
      			}
      		}
      		j--;
      	}
      	i++;
      } 		
    }
    while(i < size) {
    
    vertex *v = &g->vertices[i];
    linked_list *in = v->in_neighbours;
    if(in->data != NULL){
      return -1;
    }
  i++;
  }
  
  
  return L;

}
