#include <bits/stdc++.h>
#include <windows.h>
#define START 1
#define EXIT 2

void Add(HWND);

HWND edit, show;

int Time;
bool flag, running;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_DESTROY:
        exit(0);
        break;
    case WM_COMMAND:
        switch (wp) {
        case START:
            flag = 0;
            char tim[10];
            GetWindowText(edit, tim, 10);

            for (int i = 0; tim[i]; i++)
                if (!(tim[i] >= '0' && tim[i] <= '9'))
                {
                    SetWindowText(show, "Please input the correct time.");
                    flag = 1;
                }

            if (!flag)
            {
                SetWindowText(show, tim);
                if (!running)
                    running = 1, Time = atoi(tim);

                char show_text[10] = {0};

                for (int i = 0; i <= 4 && running && Time >= -1; i++)
                {
                    itoa(Time, show_text, 10);
                    SetWindowText(show, show_text);
                    Sleep(1000);
                    Time--;

                    if (Time == -1)
                        running = 0;
                }
            }
            break;
        case EXIT:
            exit(0);
            break;
        }
        break;
    case WM_CREATE:
        Add(hwnd);
        break;
    default:
        return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrvIns, LPSTR args, int cmdShow) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hIns;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = "wnd";
    RegisterClass(&wc);
    CreateWindow("wnd", "Count Down", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, NULL, NULL);
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

void Add(HWND hwnd) {
    CreateWindow("button", "Start", WS_CHILD | WS_VISIBLE, 150, 250, 80, 50, hwnd, (HMENU)START, NULL, NULL);
    show = CreateWindow("static", "", WS_CHILD | WS_VISIBLE, 150, 100, 200, 100, hwnd, NULL, NULL, NULL);
    CreateWindow("button", "Quit", WS_CHILD | WS_VISIBLE, 270, 250, 80, 50, hwnd, (HMENU)EXIT, NULL, NULL);
    CreateWindow("static", "Input time (Second): ", WS_CHILD | WS_VISIBLE, 35, 200, 90, 90, hwnd, NULL, NULL, NULL);
    edit = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE, 150, 200, 100, 20, hwnd, NULL, NULL, NULL);
}

int main() {
    int h, m, s;
    printf("hour(s) = ");
    scanf("%d", &h);
    printf("minute(s) = ");
    scanf("%d", &m);
    printf("second(s) = ");
    scanf("%d", &s);
    SYSTEMTIME sys, temp;
    GetLocalTime(&sys);
    sys.wHour += h;
    sys.wMinute += m;
    sys.wSecond += s;
    if (sys.wSecond >= 60) {
        sys.wSecond -= 60;
        sys.wMinute++;
    }
    if (sys.wMinute >= 60) {
        sys.wMinute -= 60;
        sys.wHour++;
    }
    if (sys.wHour >= 24) {
        return 0;
    }
    system("cls");
    printf("hour(s) = %d\n\nminute(s) = %d\n\nsecond(s) = %d", h, m, s);
    Sleep(1000);
    printf("\n");
    while (true) {
        GetLocalTime(&temp);
        if (sys.wHour == temp.wHour) {
            if (sys.wMinute == temp.wMinute) {
                if (sys.wSecond == temp.wSecond) {
                    Beep(523, 400);
                    Beep(578, 400);
                    Beep(659, 400);
                    system("pause");
                }
            }
        }
    }
    return 0;
}
