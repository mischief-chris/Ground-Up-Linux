#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RSIZE 256
#define CSIZE 256

int main(void){

    char line[RSIZE][CSIZE];
    int row_num, column_num = -1;

    FILE *fptr = NULL;
    fptr = fopen("PKGBUILD", "r");
    while(fgets(line[row_num], CSIZE, fptr))
	{
        line[row_num][strlen(line[row_num]) - 1] = '\0';
        row_num++;
    }
    column_num++;
    column_num = row_num;
    for(row_num = 0; row_num < column_num; ++row_num)
    {
	//printf(" %d\n", row_num);
	//printf(" %d\n", column_num);
        printf("|%d|%d| %s\n",row_num, column_num, line[row_num]);
    }
    return 0;
}

