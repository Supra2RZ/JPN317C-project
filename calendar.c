#include <stdio.h>
#include <string.h>

#define LEAP_YEAR ((year%4 == 0 && year%100 != 0)|| year%400 == 0 )
#define TRUE 1
#define ch '-'
#define max_no 91

int days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[] = {" ","\n\n\n一月", "\n\n\n二月","\n\n\n三月","\n\n\n四月","\n\n\n五月","\n\n\n六月","\n\n\n七月", "\n\n\n八月","\n\n\n九月",
                "\n\n\n十月","\n\n\n十一月", "\n\n\n十二月"};
char *japanDays[] = {" ", "一", "二", "三", "四", "五", "六", "七", "八", "九", "十", "十一", "十二", "十三", "十四","十五","十六", "十七","十八","十九", "二十",
                    "二十一","二十二","二十三", "二十四", "二十五", "二十六", "二十七", "二十八", "二十九", "三十", "三十一"};

int get_dayCode(int year) { 
    int daycode;
    int x, y, z;
    x = (year - 1) / 4;
	y = (year - 1) / 100;
	z = (year - 1) / 400;
	daycode = (year + x - y + z) %7;
    return daycode;
}

void setLeapYear(int year) {
    if(year == LEAP_YEAR) {
        days_in_month[2] = 29;
    } else {
        days_in_month[2] = 28;
    }
}

void print(int year, int daycode) {
    int month, day;
    for(month = 1; month <=12; month++) {
        printf("%s, %d", months[month], year);
        printf("\n\n日曜日 月曜日 火曜日 水曜日 木曜日 金曜日 土曜日");

        for(day = 1; day < 1 + daycode*5; day++) {
            printf(" ");
        }
        for(day = 1; day <= days_in_month[month]; day++) {
            printf("%2d", day);

            if(((day + daycode) % 7) > 0) {
                printf("   ");
            } else {
                printf("\n ");
            }
        }
        daycode = (daycode + days_in_month[month]) % 7;
    }
}

int main(void) {
    int year, daycode, leap;

    printf("四桁（けた）の年をタイプしてください： ");
    scanf("%d", &year);
    daycode = get_dayCode(year);
    setLeapYear(year);
    print(year, daycode);
    printf("\b");
    return 0;
}
