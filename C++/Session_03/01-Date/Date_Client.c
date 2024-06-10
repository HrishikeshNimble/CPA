#include "Date.h"

int main(void)
{
    struct date* p_today = create_date();

    init_date(p_today, 1, 8, 2020);
    show(p_today);

    set_day(p_today, 15);
    set_month(p_today, 8);
    set_year(p_today, 2022);

    show(p_today);

    destroy_date(p_today);
    p_today = NULL;

    exit(0);
}
