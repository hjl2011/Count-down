/*
    Author : hjl2011
    Version : 0.1.0-alpha
*/
#include <cstdio>
#include <windows.h>
int main() {
    int h,m,s;
    printf("hour(s) : ");
    scanf("%d",&h);
    printf("\n\nminute(s) : ");
    scanf("%d",&m);
    printf("\n\nsecond(s) : ");
    scanf("%d",&s);
    MessageBox(NULL,"temp","title",MB_OK);
    return 0;
}