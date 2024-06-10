#ifndef _DATE_H
#define _DATE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

struct date{
    int day;
    int month;
    int year;
};

struct date* create_date();

void init_date(struct date* p_date, int dd, int mm, int yy);

int get_day(struct date* p_date);
int get_month(struct date* p_date);
int get_year(struct date* p_date);

void set_day(struct date* p_date, int new_day);
void set_month(struct date* p_date, int new_month);
void set_year(struct date* p_date, int new_year);

void show(struct date* p_date);
void destroy_date(struct date* p_date);

/* not to be called by client directly
for internal use of server
*/

static int validate_date(int dd, int mm, int yy);

#endif /* _DATE_H */
