#include <stdlib.h>
#include "graph.h"
#include <stdio.h>
#include <string.h>

	graph *pGraph;
	
graph *read_graph(char *filename) {
	FILE *fp = fopen ( "filename", "r");
	char string[100];
	char *s = fgets(string,100,fp);
	int num = atoi(s);

	//Init Graph
	graph *pGraph = malloc(sizeof(graph));
	pGraph->number_vertices = num;
	pGraph->vertices = malloc(sizeof(vertex*) * num);

	//init vertices
	int k = 0;
	while (k < num) {
		vertex *pVertex ;
		pVertex = malloc(sizeof(vertex));
		pVertex->id = k;
		pVertex->out_neighbours = init_linked_list();
		pVertex->in_neighbours = init_linked_list();
		pGraph->vertices[k] = *pVertex;
		k++;
	}		
	
	
	int i = 1;
	while(i <= num) {
		char *tmp = fgets(string,100,fp);
		int j = 0;
		while (j < num){
		  int p = tmp[j] - '0';
			if (p != 0){
				vertex *v = &pGraph->vertices[i-1];
        vertex *v_neighbor = &pGraph->vertices[j];
        add_element(v->out_neighbours, v_neighbor);
        add_element(v_neighbor->in_neighbours, v);
				}
			j++;
		}
		i++;
	}
}

void print_graph(graph *g) {

}

