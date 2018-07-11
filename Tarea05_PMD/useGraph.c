#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int cmpArrays(void *, void *);
void printArray(void *);

typedef struct{
    char tweet_id[300];
}tweet;

tweet retweets[138063];
tweet tweets[138063];

int main(){

    char string1[300];
    char string2[300];
    char temp;
    FILE *f;
    f = fopen ("RETWEETS.csv", "r");
    int counter=0;
    temp=fgetc(f);
    while(temp != EOF){
        temp=fgetc(f);
        if(temp ==','){
            counter++;
        }
    }
    //This counts how many lines the file text has
//    printf("%d\n\n\n",counter);
    fclose(f);
    FILE *g;
    g = fopen ("RETWEETS.csv", "r");
    for(int i=0; i<counter;i++){
        fscanf(g, "%[^,]%*c%[^\n]", string1, string2);
        strcpy(retweets[i].tweet_id, string1);
        strcpy(tweets[i].tweet_id, string2);
        //Check to see that
//        printf("%s ", string1);
//        printf("%s \n", string2);
    }
    //Verificar que este en la estructura los datos de los tweets
//    for(int i=0; i<counter;i++){
//        printf("%s ", retweets[i].tweet_id);
//        printf("%s\n", tweets[i].tweet_id);
//    }
//
    fclose(g);

    Graph s1;
    /*for(int k=0;k<counter;k++){
    	printf("%s,%s",retweets[k].tweet_id,tweets[k].tweet_id);
    }*/
    s1 = graph_create(cmpArrays, printArray);
    //printf("%d",counter);
   for(int k=0;k<counter;k++){
    	graph_addVertex(s1, &retweets[k]);
    	graph_addVertex(s1,  &tweets[k]);
    	graph_addEdge(s1,&tweets[k],&retweets[k]);
    }

    printf("\nNúmero de vértices: %lu\n",graph_vertexCount(s1));
    printf("Número de Aristas; %lu", graph_edgeCount);

//    for(int i=0; i<counter;i++){
//        graph_addVertex(s1, retweets[i].tweet_id);
//
//    }


}
int cmpArrays(void *d1, void *d2) {
    char v1[300];
    char v2[300];
    strcpy(v1, (char *) d1);
    strcpy(v2, (char *) d2);
    if(strcmp(v1,v2)==0)
    	return true;
    return false;
    //return !strcmp(v1,v2);//retorna 0 si son iguales
}

void printArray(void *d){
    printf(" %s \n",(char*)d);
}
