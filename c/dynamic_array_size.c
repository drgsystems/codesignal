#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
This example demonstrates how to declare and use a dynamic size 
array using a char pointer which uses a realloc to assign new
memory block to array.  Modified stackoverflow example.
*/
void fatal_error(void);

int main( int argc, char** argv)
{
    unsigned int buf_size = 0;
    unsigned int buf_used = 0;

    char* buf = NULL;
    char* tmp = NULL;    

    char c;
    int i = 0;

    //while ((c = getchar()) != EOF) {
	for(int j=0; j<1000; j++) {
        if (buf_used == buf_size) {
             //need more space in the array

             buf_size += 20;
             tmp = (char *) realloc(buf, sizeof(char) * buf_size); // get a new larger array
             if (!tmp) fatal_error();
             buf = tmp;
			 //memset(&buf[buf_size-20], 'A', sizeof(char) * 20);
        }
		//fill buffer with ascii ! to ~
        buf[buf_used] = j%94 + 33; // pointer can be indexed like an array
        ++buf_used;
    }

	printf("\n\n*** Dump of stdin ***\nbuf size=%d\n",buf_used);
    for (i = 0; i < buf_used; ++i) 
		printf("%c ",buf[i]);

    free(buf);

    return 0;
}

void fatal_error(void)
{
    fputs("fatal error - out of memory\n", stderr);
    exit(1);
}