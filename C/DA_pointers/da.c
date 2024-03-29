#include <stdio.h>
#include <stdlib.h>
#include "da.h"

Da_t* createDA(int capacity)
{
	Da_t* da;
    int num=0;

    da = malloc(capacity * sizeof(Da_t));
    if (da == NULL)                     
        {
            printf("Error! memory not allocated.");
            exit(0);
        }

    da->capacity = capacity;
	da->index = 0;
    da->arr = malloc(capacity * sizeof(intPtr));
	
    if(da->arr == NULL)                     
    {
        printf("Error! memory not allocated.");
    	free(da);
        exit(0);
    }

    return da;

}

int insertDA(Da_t* da, intPtr nPtr)
{
    
	if(da->arr!=NULL||nPtr!=NULL)
	{
		intPtr* temp = da->arr;

        if (da->index == da->capacity)
        {
            temp = realloc(da->arr,sizeof(intPtr)*((da->capacity)*2));
            if(da->arr != NULL)                     
            {
                da->arr = temp;
                da->capacity *=2;
            }
            else
            {
                return **(da->arr);
            }
            
        }
        da->arr[(da->index)]=nPtr;
        (da->index)++;


    return **(da->arr);
	}
	
    
}

void printDA(Da_t* da)
{   
    int i=0;
	if(da!=NULL)
	{
    		for(i=0; i < da->index; i++)
		{
		    printf("index[%i], value: %d\n", i, *(da->arr[i])); /**/
		}  
	}
}

void destroyDA(Da_t* da)
{
    int i=0;

	if(da!=NULL)
	{
        for (i=0 ; i<da->index ; i++)
        {
            free(da->arr[i]);
        } 
		
        free(da);

	}
    
    
}

