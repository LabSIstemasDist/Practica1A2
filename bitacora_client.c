/*
 * Code concerning the client.
 * Client introduces an option and a name
 * and the apropriate function is executed.
 */
#include "bitacora.h"
#include <stdio.h>
#include <stdlib.h>

void bitacora_prog_1(char *host, char* opt, char *name) /* Parameters required: host, option and name */
{
    CLIENT *clnt; 
	char * *result_1;
	char * add_1_arg;
	char * *result_2;
	char * search_1_arg;

#ifndef	DEBUG
	/* Exit if client cant be found */
	clnt = clnt_create (host, BITACORA_PROG, BITACORA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	/* Option to add new name */
	if(strcmp(opt, "add")==0){//opt is equals to "add"
		add_1_arg = name;
		result_1 = add_1(&add_1_arg, clnt);
		if (result_1 == (char **) NULL) {
			//clnt_perror (clnt, "call failed");
		} else {
			printf("Server response: %s", *result_1);
		}
	}
	
	/* Option to search name */
	if(strcmp(opt, "search")==0){//opt is equals to "search"
		search_1_arg = name;
		result_2 = search_1(&search_1_arg, clnt);
		if (result_2 == (char **) NULL) {
			//clnt_perror (clnt, "call failed");
		} else {
			printf("Server response: %s \n", *result_2);
		}
	}
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

int
main(int argc, char *argv[]) {
        char *host; /* client handle to server */
        char *name; /* name to be added or searched */
        char* opt;  /* option chosen (1 for add, 2 for search)  */
        int id;

	/* Ends if client doesnt introduce any parameters */
        if (argc != 4) {
            printf ("usage: %s host opt name\n", argv[0]);
            exit(1);
        }
        host = argv[1]; // Host.
        opt  = argv[2]; //Option.
        name = argv[3]; //Name

	/* Error message if client tries invalid option */
        if (strcmp(opt, "add")!=0 && strcmp(opt, "search")!=0) {
            fprintf(stderr, "invalid value: %s\n", argv[2]);
            exit(1);
        }

	/* If nothing has failed thus far, process continues */
        bitacora_prog_1(host, opt, name);
}
