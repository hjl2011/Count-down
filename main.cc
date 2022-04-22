/*
    Author : hjl2011
    Version : 1.3.1-alpha
    Date : 2022-04-22

    -- 尝试兼容 Linux
      : windows.h -> unistd.h
*/
#include <stdio.h>
#include <string>
#include <unistd.h>
using std::string;
char msg[10005];
struct Time {
    int h,m,s;
    Time(int hour,int min,int sec) {
        h = hour;
        m = min;
        s = sec;
    }
    void clock() {
        while(h || m || s) {
            sleep(1);
            if(--s < 0) {
                s = 59;
                if(--m < 0) m = 59,--h;
            }
            printf("%02d:%02d:%02d\r",h,m,s);
        }
    }
};
int main() {
    int h,m,s;
    while(true) {
        printf("hour(s) : ");
        scanf("%d",&h);
        printf("\nminute(s) : ");
        scanf("%d",&m);
        printf("\nsecond(s) : ");
        scanf("%d",&s);
        sprintf(msg,"hour(s) = %d\nminute(s) = %d\nsecond(s) = %d\n",h,m,s);
        if(m > 59 || s > 59) continue;
        printf("Please confirm ...");
        int code = MessageBox(NULL,msg,"Count-down",MB_YESNO);
        if(code == 6) break;
    }
    CONSOLE_CURSOR_INFO cursor_info = {1,0}; 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
    Time x(0,5,0);
    x.clock();
    return 0;
}
