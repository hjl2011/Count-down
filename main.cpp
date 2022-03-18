#include <cstdio>
#include <windows.h>
int main() {
    int h,m,s;
    printf("hour(s) = ");
    scanf("%d",&h);
    printf("minute(s) = ");
    scanf("%d",&m);
    printf("second(s) = ");
    scanf("%d",&s);
    SYSTEMTIME sys,temp;
    GetLocalTime(&sys);
    sys.wHour += h;
    sys.wMinute += m;
    sys.wSecond += s;
    if(sys.wSecond >= 60) {
        sys.wSecond -= 60;
        sys.wMinute++;
    }
    if(sys.wMinute >= 60) {
        sys.wMinute -= 60;
        sys.wHour++;
    }
    if(sys.wHour >= 24) return 0;
    system("cls");
    printf("hour(s) = %d\n\nminute(s) = %d\n\nsecond(s) = %d",h,m,s);
    Sleep(1000);
    printf("\n");
    while(true) {
        GetLocalTime(&temp);
        if(sys.wHour == temp.wHour) {
            if(sys.wMinute == temp.wMinute) {
                if(sys.wSecond == temp.wSecond) {
                    Beep(523,400);
                    Beep(578,400);
                    Beep(659,400);
                    system("pause");
                }
            }
        }
    }
    return 0;
}
