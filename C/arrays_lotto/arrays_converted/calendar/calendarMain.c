#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"

int main()
{
    int capacity=0, flagCheck, i=9;
    int* nPtr=NULL;
    AD_t* ad = NULL;
    MT_t* pMeeting = NULL;
	
    while(i != 0)
    {
    printf("\n\nEnter number of function:\n ");
    printf("1-Create AD \n 2-Create meeting \n ");
    printf("3-Insert appointment into AD \n 4-Remove appointment from AD \n");
    printf("5-Find appointment in AD \n 6-Print AD AD \n 7-Destroy \n");
    scanf("%d",&i);

        switch(i)
        {
            case 1: 
                printf("Enter capacity of Appointment Diary:");
                scanf(" %d", &capacity);  

                ad = createAD(capacity);
                if (ad==NULL)
                {
                    printf("error!!!"); 
                    return 0;
                }
                break;

            case 2:

                if (ad!=NULL)
                {
                    pMeeting = createMT(ad);
                    if(pMeeting == NULL)
                    {
                        printf("Create meeting failed\n");
                    }
                }
                else 
                {
                    printf("NO Calendar created\n");
                }
                
                break;

            case 3:
                if(ad != NULL && pMeeting != NULL)
                {
                    flagCheck = insertMeeting(ad, pMeeting);
                    if(flagCheck == 0)
                    {
                        printf("Insert meeting success\n");
                    }
                    else
                    {
                        printf("Insert meeting failed\n");
                    } 
                }
                
                break;

            case 4:
                if(ad != NULL)
                {
                    flagCheck = deleteMeeting(ad);
                    if(flagCheck == 0)
                    {
                        printf("Delete meeting success\n");
                    }
                    else
                    {
                        printf("Delete meeting failed\n");
                    } 
                }
                else
                {
                    printf("Calendar not exist\n");

                }
                
                break;
            case 5:
                if (ad != NULL)
                {
                    pMeeting = findMeeting(ad);
                    if (pMeeting !=NULL)
                    {
                        printf("%f", pMeeting->startT);
                        printf("%f", pMeeting->endT);
                        printf("%d", pMeeting->room);

                    }
                
                }
                else
                {
                    printf("Calendar not exist\n");

                }
                
                
              
                break;
            case 6:
                if(ad != NULL)
                {
                    printAD(ad); /*print calendar*/
                }
                else
                {
                    printf("Calendar not exist\n");

                }
                
                break;
            case 7:
                if(ad != NULL)
                {
                    destroyAD(ad); /*destroy pointers*/
                }
                else
                {
                    printf("Calendar not exist\n");
                }
            
                break;
            
        }
    }

    
    
    return 0;
}