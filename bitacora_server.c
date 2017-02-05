/*
 * Code concerning the client.
 * Depending on the operation selected, the server
 * manipulates the text file and shows the correct
 * output on the terminal.
 */

#include "bitacora.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* A new name is to be added to the file */
char **
add_1_svc(char **argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */
	/* Initialize variable of time */
	time_t timeres = time(NULL);
	
	/* Open file */
	FILE *f = fopen("file.txt", "a+"); 
	/* Exit if there is an error with the file */
	if (f == NULL) {
    printf("Error opening file!\n");
    exit(1);
	}
	/* Time variable is acosiated with the local time */
	char * time = asctime(localtime(&timeres));
	
	/* Name and time are added to the file*/
	fprintf(f, "%s %s", *argp, time);
	printf("Server Added:%s %s", *argp, time);
	fclose(f);
	
	asprintf(&result, "%s %s", *argp, time);
	
	return &result;
}

/* Search for a name in the file */
char **
search_1_svc(char **argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */
	printf("Server is searching for: %s \n", *argp);
	
	/* Try to open file */
	FILE* fh = fopen("file.txt", "r");
	/* Exit if file doesnt exist */
	if (fh == NULL){
    printf("file does not exists");
    return 0;
	}
 	char buff[1000];
  	char *s;
	//read line by line
	
	const size_t line_size = 300;
	char* line = malloc(line_size);
	/* Counter for the occurrences of a name */
	int count = 0;
	while (fgets(line, line_size, fh) != NULL){
  	//printf("%s",line);
  	
	/* Increase counter each time the name is found */
  	s = strstr(line, *argp);
 		if (s != NULL) {
     count++;
    }
    else {
			//printf("String not found\n");
 		}
	}
	
	/* Print how many times the name was found */
  	printf("Registry found: %d times \n", count);
	asprintf(&result, "Server Found, %s %d times", *argp, count);
	
	return &result;
}
