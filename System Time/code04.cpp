#include <iostream>
#include <sys/time.h>

using namespace std;

/**
 * To get more control values in time filed we have tm structure.
 * In this struct more field valures present like day month sec hour weekday year day...
 * There are two function call present for these one is for global time (gmtime) and another is for local time(localtime).
 **/
int main()
{
    time_t *pt;
    struct tm *ptm;

    time(pt);
    cout << "Value of pt is " << *pt << endl;

    cout<<"Global time value:"<<endl;
    ptm = gmtime(pt);

    printf("tm_sec:[%d] tm_min:[%d] tm_hour:[%d] tm_mday:[%d] tm_mon:[%d] tm_year:[%d] tm_wday:[%d] tm_yday:[%d] tm_isdst:[%d]\n", ptm->tm_sec, ptm->tm_min, ptm->tm_hour, ptm->tm_mday, ptm->tm_mon, ptm->tm_year, ptm->tm_wday, ptm->tm_yday,ptm->tm_isdst);

    cout<<"Local time value:"<<endl;
    ptm = localtime(pt);
    
    printf("tm_sec:[%d] tm_min:[%d] tm_hour:[%d] tm_mday:[%d] tm_mon:[%d] tm_year:[%d] tm_wday:[%d] tm_yday:[%d] tm_isdst:[%d]\n", ptm->tm_sec, ptm->tm_min, ptm->tm_hour, ptm->tm_mday, ptm->tm_mon, ptm->tm_year, ptm->tm_wday, ptm->tm_yday,ptm->tm_isdst);

    // There is reverse function also present which convert broken tm time structure into time_t format
    //mktime(cont struct *tm))    
}

// struct tm
// {
//   int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
//   int tm_min;			/* Minutes.	[0-59] */
//   int tm_hour;			/* Hours.	[0-23] */
//   int tm_mday;			/* Day.		[1-31] */
//   int tm_mon;			/* Month.	[0-11] */
//   int tm_year;			/* Year	- 1900.  */
//   int tm_wday;			/* Day of week.	[0-6] */
//   int tm_yday;			/* Days in year.[0-365]	*/
//   int tm_isdst;			/* DST.		[-1/0/1]*/

// # ifdef	__USE_MISC
//   long int tm_gmtoff;		/* Seconds east of UTC.  */
//   const char *tm_zone;		/* Timezone abbreviation.  */
// # else
//   long int __tm_gmtoff;		/* Seconds east of UTC.  */
//   const char *__tm_zone;	/* Timezone abbreviation.  */
// # endif
// };