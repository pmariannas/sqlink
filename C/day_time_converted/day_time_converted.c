#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "day_time_converted.h"

int checkTime(int, int , int );
int checkDate(int , int , int );


cDate_t* createDate(int day, int month, int year)
{
	cDate_t* date;

    date = (cDate_t*)malloc(sizeof(cDate_t));

    if (date == NULL)                     
    {
        return NULL;
    }

    date->cDay = day;
    date->cMon = month;
    date->cYear = year;
    date->currTime = (cTime_t*)malloc(sizeof(cTime_t));
    if(date->currTime == NULL)                     
    {
    	free(date);
        return NULL;
    }
    date->currTime->cHour = 00;
    date->currTime->cMin = 00;
    date->currTime->cSec = 00;



    return date;
}

void printDate(cDate_t* date)
{
    int i;
    char* mon[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    if(date!=NULL)
    {
    printf("1: ‫‪European‬ dd/mm/yyyy  \n");
    printf("2: ‫‪American‬‬ mm/dd/yyyy \n");
    printf("3: ‫‪European‬‬ dd/Dec/yyyy\n");
    printf("4: ‫‪‬dd/mm/yyyy hh:mm:ss \n");
    printf("5: am/pm -> hh:mm:ss \n");

    scanf("%d", &i);
    switch(i)
    {
        case 1:
            printf("date in struct: %d/%d/%d\n", date->cDay, date->cMon, date->cYear);
            break;
        case 2:
            printf("date in struct: %d/%d/%d\n", date->cMon, date->cDay, date->cYear);
            break;
        case 3:
            printf("date in struct: %d/%s/%d\n", date->cDay, mon[date->cMon-1], date->cYear);
            break;
        case 4:
            printf("date in struct: %d/%s/%d  %d:%d:%d\n",  date->cDay, mon[date->cMon-1], 
                                                            date->cYear, date->currTime->cHour, 
                                                            date->currTime->cMin, date->currTime->cSec);
            break;
        case 5:
            if(date->currTime->cHour > 1 && date->currTime->cHour<12) /*am*/
            {
                printf("time in struct: %d:%d:%d a.m\n",    date->currTime->cHour, 
                                                    date->currTime->cMin, 
                                                    date->currTime->cSec);
            }
            else 
            {
              printf("time in struct: %d:%d:%d p.m\n",    date->currTime->cHour-12, 
                                                    date->currTime->cMin, 
                                                    date->currTime->cSec);  /*pm*/
            }
            
            break;
        
        }
    }
}

int checkLeapYear(int year)
{
    if(year%4 == 0)
    {
        if( year%100 == 0)
        {
            /*year is divisible by 400, hence the year is a leap year*/ 
            if ( year%400 == 0)
                {
                return 0; /*printf("%d is a leap year.", year);*/
                }
            else
                {
                return -1; /*printf("%d is not a leap year.", year);*/
                }
        }
        else
            return 0; /*printf("%d is a leap year.", year );*/
    }
    else
        return -1; /*printf("%d is not a leap year.", year);*/
   
}


cTime_t* setTime(cTime_t* curTime)
{
    int h, min, sec;

    if(curTime!=NULL)
    {
        printf("Set New Time\n");
        while (1)
        {
            printf("enter hour:\n");
            scanf("%d", &h);
            printf("enter min:\n");
            scanf("%d", &min);
            printf("enter seconds:\n");
            scanf("%d", &sec);
            
            if(checkTime(h,min, sec)==-1)
            {
                break;
            }
            
            printf("TIME INCCORECT \n");
        }
        
        curTime->cHour = h;
        curTime->cMin = min;
        curTime->cSec = sec;
        return curTime;
    }
}


int checkTime(int h, int min, int sec)
{
    if( h >24 || h <1 || sec > 60 || sec < 0 || min >60 || min <0)
    {
       return 0;
    }
    else
    {
        return -1;
    }
}

int checkDate(int d, int m, int y)
{

     if( (y>1900)&&((checkLeapYear(y) == 0 && m == 2 && d > 0 && d <= 28)       ||
         (y>1900)&&(checkLeapYear(y) == -1 && m == 2 && d > 0 && d <= 29)       ||
                        m == 4 && d >0 && d <= 30 || m == 6 && d >0 && d <= 30      ||
                        m == 9 && d >0 && d <= 30 || m == 11 && d >0 && d <= 30     ||
                        m == 1 && d >0 && d <= 31 || m == 3 && d >0 && d <= 31      ||
                        m == 7 && d >0 && d <= 31 || m == 8 && d >0 && d <= 31     ||
                        m == 10 && d >0 && d <= 31|| m == 12 && d >0 && d <= 31||
                        m == 5 && d >0 && d <= 31   ))
                        
                        {
                            return 0;
                        }
    else
    {
        return -1;
    }
    
}

cDate_t* addTimeToTime(cDate_t* curDate, cTime_t* newTime)
{
    int day=0, s=0, m=0, h=0;
    
    if(time!=NULL)
    {
        int h=0, min=0, sec=0;

        s = curDate->currTime->cSec + newTime->cSec;
        if(s>60)
        {
            m = s/60;
            s = s%60;
        }

        m = m + curDate->currTime->cMin + newTime->cMin;
        if(m > 60)
        {
            h = m/60;
            m = m%60;
        }

        h= h + curDate->currTime->cHour + newTime->cHour;
        if(h>24)
        {
            day=1;
            h = h%24;
        }

        /*check if d>0 change date*/
        if(day>0)
        {
            
            if(checkDate(curDate->cDay+1, curDate->cMon, curDate->cYear)==0)/*if the date stay correct after adding*/
            {
                curDate->cDay++;
            }
            else
            {
                if(checkDate(curDate->cDay+1, curDate->cMon+1, curDate->cYear)==0)/*if date no legal meens month +1 not legal month*/
                {
                    curDate->cMon++;
                }
                else
                {
                    curDate->cDay =1;
                    curDate->cMon=1;
                    curDate->cYear++;
                }
                
                
            }
            
            curDate->currTime->cHour = h;
            curDate->currTime->cMin = m;
            curDate->currTime->cSec = s;
            return curDate;
        }
        else
        {
            curDate->currTime->cHour = h;
            curDate->currTime->cMin = m;
            curDate->currTime->cSec = s;

            return curDate;
        }
        
    }

}

/*cDate_t* addDateToDate(cDate_t* curDate, cDate_t* newDate)
{
    return 0;
}*/


cDate_t* setNewDate(cDate_t* date)
{
    int d, m, y;

    if(date!=NULL)
    {
        printf("Set New Date\n");
        while (1)
        {
            printf("enter day:\n");
            scanf("%d", &d);
            printf("enter month:\n");
            scanf("%d", &m);
            printf("enter year:\n");
            scanf("%d", &y);
            
            if(checkDate(d,m,y)==0)
            {
                break;
            }
            
            printf("TIME INCCORECT \n");
        }
        
        date->cDay = d;
        date->cMon = m;
        date->cYear = y;
        return date;
        }
}

int dayOfYear(cDate_t* date)
{
    int day, mon, year, days_in_feb = 28, doy;    
 
    day = date->cDay;
    mon = date->cMon;
    year = date->cYear;
    
    doy = day;
    
    if( (year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0) )
    {
        days_in_feb = 29;
    }
 
    switch(mon)
    {
        case 2:
            doy += 31;
            break;
        case 3:
            doy += 31+days_in_feb;
            break;
        case 4:
            doy += 31+days_in_feb+31;
            break;
        case 5:
            doy += 31+days_in_feb+31+30;
            break;
        case 6:
            doy += 31+days_in_feb+31+30+31;
            break;
        case 7:
            doy += 31+days_in_feb+31+30+31+30;
            break;            
        case 8:
            doy += 31+days_in_feb+31+30+31+30+31;
            break;
        case 9:
            doy += 31+days_in_feb+31+30+31+30+31+31;
            break;
        case 10:
            doy += 31+days_in_feb+31+30+31+30+31+31+30;            
            break;            
        case 11:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31;            
            break;                        
        case 12:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31+30;            
            break;                                    
    }
    return doy;
}

char* monthName(int month)
{
    char* monthArr[12]= {   "January","February","March","April","May",
                            "June","July","August","September",
                             "October","November","December"};
    return monthArr[month-1];
}