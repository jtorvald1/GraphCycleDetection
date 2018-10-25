/*
 * linked_list.c
 *
 *  Created on: Dec 24, 2013
 *      Author: jacob
 */
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

linked_list *init_linked_list() {
	linked_list *ll;
    ll = (linked_list *) malloc(sizeof(linked_list));

    ll->next = ll;
    ll->previous = ll;
    return ll;
}

void add_element( linked_list *list, void *element) {
 	linked_list *list_element;

    list_element = malloc(sizeof(linked_list));
    list_element->data = element;

    list_element->next = list->next;
    list->next->previous = list_element ;
    list->next = list_element ;
    list_element->previous = list;
}

int linked_list_size(linked_list *list) {

	linked_list *iterator = list->next;
	  int size = 0;

	while (list != iterator) 
		{
			size++;
			iterator = iterator->next;
		}
	return size;
}

void *remove_first(linked_list *list) {
	list->next->previous = list->previous;
	list->previous->next = list->next;
	
	free(list);
}

int remove_element(linked_list *list, void *element) {
	linked_list *tmp = list;
	int i = linked_list_size(tmp);
	
	while (i != 0) {
		if (tmp->data == element) {
			tmp->next->previous = tmp->previous;
			tmp->previous->next = tmp->next;
			
			free(tmp);
			
			return 0;
		}
		tmp = tmp->next;
		i--;
	}
	
	return -1;
}

