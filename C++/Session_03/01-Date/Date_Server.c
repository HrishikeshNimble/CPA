#include "Date.h"

struct date* create_date(){
    struct date* p_date = (struct date*)calloc(1, sizeof(struct date));
    assert(p_date != NULL);
    return (p_date);
}

void init_date(struct date* p_date, int dd, int mm, int yy){
    //assert(validate_date());
    p_date->day = dd;
    p_date->month = mm;
    p_date->year = yy;
}

int get_day(struct date* p_date){
    return (p_date->day);
}

int get_month(struct date* p_date){
    return (p_date->month);
}

int get_year(struct date* p_date){
    return (p_date->year);
}

void set_day(struct date* p_date, int new_day){
    //assert(validate_date());
    p_date->day = new_day;
}

void set_month(struct date* p_date, int new_month){
    //assert(validate_date());
    p_date->month = new_month;
}

void set_year(struct date* p_date, int new_year){
    //assert(validate_date());
    p_date->year = new_year;
}

void show(struct date* p_date){
    printf("[%d]-[%d]-[%d]\n", p_date->day, p_date->month, p_date->year);
}

void destroy_date(struct date* p_date)
{
    free(p_date);
    p_date = NULL;
}

static int validate_date(int dd, int mm, int yy){
    //TODO
    return (TRUE);
}
