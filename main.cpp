/*
Count-down Main File 1.2.7
This source code file is under MIT License.
Copyright (c) 2022 Class Tools Develop Team
Contributors: hjl2011
*/
#include <stdio.h>
#include <string>
#include <windows.h>
using std::string;
char msg[10005];
class Time {
    private:
        int h;
        int m;
        int s;
    public:
    Time(int hour,int min,int sec) {
        h = hour;
        m = min;
        s = sec;
    }
    void clock() {
        while(h || m || s) {
            Sleep(998);
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