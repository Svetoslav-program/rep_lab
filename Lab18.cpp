// Lab18.cpp : Определяет точку входа для приложения.
//
#include <stdio.h>
#include "framework.h"
#include "Lab18.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB18, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB18));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB18));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB18);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void Triangle(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, cx, cy - size, NULL);
    LineTo(hdc, cx + size, cy + size);
    LineTo(hdc, cx - size, cy + size);
    LineTo(hdc, cx, cy - size);

    DeleteObject(hPen);
}

int counter = 0;
void TriangleSpecial(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, cx, cy - size, NULL);
    LineTo(hdc, cx + size, cy + size);
    LineTo(hdc, cx - size, cy + size);
    LineTo(hdc, cx, cy - size);

    char strC[5];
    sprintf_s(strC, "%d", counter);
    TCHAR strWin[5];
    OemToCharW(strC, strWin);
    TextOut(hdc, cx, cy, (LPCWSTR)strWin, _tcslen(strWin));

    DeleteObject(hPen);
}

void Triangle2(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    int x1 = cx - size / 2;
    int y1 = cy - size;
    int x2 = cx + size / 2;
    int y2 = cy - size;
    int x3 = cx - size;
    int y3 = cy + size;
    int x4 = cx + size;
    int y4 = cy + size;

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);
    DeleteObject(hPen);
}
void Romb(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    int x1 = cx ;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy;
    int x3 = cx ;
    int y3 = cy + size;
    int x4 = cx - size;
    int y4 = cy ;

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);
    DeleteObject(hPen);
}
void Star(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    int x1 = cx;
    int y1 = cy - size;
    int x2 = cx + size/4;
    int y2 = cy-size / 4;
    int x3 = cx + size;
    int y3 = cy;
    int x4 = cx + size/4;
    int y4 = cy+  size/4;
    int x5 = cx;
    int y5 = cy + size;
    int x6 = cx - size / 4;
    int y6 = cy + size / 4;
    int x7 = cx - size;
    int y7 = cy;
    int x8 = cx - size / 4;
    int y8 = cy - size / 4;

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);
    LineTo(hdc, x1, y1);
    DeleteObject(hPen);
}
void uh(HDC hdc, int cx, int cy, int LongSize) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    int x1 = cx- LongSize / 2;
    int y1 = cy - LongSize / 2;
    int x2 = cx + LongSize;
    int y2 = cy - LongSize / 2;
    int x3 = cx + LongSize / 2;
    int y3 = cy + LongSize / 2;
    int x4 = cx -LongSize;
    int y4 = cy + LongSize / 2;

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);
    DeleteObject(hPen);
}





//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//


void task1_1(HDC hdc, int cx, int cy, int size) {
    Triangle(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task1_1(hdc, cx - size, cy - size, size / 2);
    task1_1(hdc, cx + size, cy-size, size / 2);
}
void task1_2(HDC hdc, int cx, int cy, int size) {
    Triangle(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task1_2(hdc, cx - size, cy - size, size / 2);
    task1_2(hdc, cx, cy + size, size / 2);
}
void task1_3(HDC hdc, int cx, int cy, int size) {
    Triangle(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task1_3(hdc, cx - size, cy - size, size / 2);
    task1_3(hdc, cx, cy + size, size / 2);
    task1_3(hdc, cx + size, cy - size, size / 2);
}
void task2_1(HDC hdc, int cx, int cy, int size) {
    Triangle2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task2_1(hdc, cx - size, cy - size, size / 2);
}

void task2_2(HDC hdc, int cx, int cy, int size) {
    Triangle2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task2_2(hdc, cx - size, cy - size, size / 2);
    task2_2(hdc, cx + size, cy - size, size / 2);
}
void task2_3(HDC hdc, int cx, int cy, int size) {
    Triangle2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task2_3(hdc, cx - size, cy - size, size / 3);
    task2_3(hdc, cx + size, cy - size, size / 3);
    task2_3(hdc, cx + size, cy + size, size / 2);
    task2_3(hdc, cx - size, cy + size, size / 2);
}
void task3_1(HDC hdc, int cx, int cy, int size) {
    Romb(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task3_1(hdc, cx + size, cy , size / 2);
    task3_1(hdc, cx - size, cy , size / 2);
}
void task3_2(HDC hdc, int cx, int cy, int size) {
    Romb(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task3_2(hdc, cx + size, cy, size / 2);
    task3_2(hdc, cx - size, cy, size / 2);
    task3_2(hdc, cx, cy+size, size / 2);
}
void task3_3(HDC hdc, int cx, int cy, int size) {
    Romb(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task3_3(hdc, cx + size, cy, size / 2);
    task3_3(hdc, cx - size, cy, size / 2);
    task3_3(hdc, cx, cy - size, size / 2);
}
void task3_4(HDC hdc, int cx, int cy, int size) {
    Romb(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task3_4(hdc, cx + size, cy, size / 2);
    task3_4(hdc, cx - size, cy, size / 2);
    task3_4(hdc, cx, cy - size, size / 2);
    task3_4(hdc, cx, cy + size, size / 2);
}
void task4_1(HDC hdc, int cx, int cy, int size) {
    Star(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task4_1(hdc, cx + size, cy, size / 2);
    task4_1(hdc, cx - size, cy, size / 2);
}
void task4_2(HDC hdc, int cx, int cy, int size) {
    Star(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task4_2(hdc, cx, cy+size, size / 2);
    task4_2(hdc, cx , cy-size, size / 2);
}
void task4_3(HDC hdc, int cx, int cy, int size) {
    Star(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    task4_3(hdc, cx, cy + size, size / 2);
    task4_3(hdc, cx, cy - size, size / 2);
    task4_3(hdc, cx-size, cy, size / 2);
}
void task5_3(HDC hdc, int cx, int cy, int size) {
    uh(hdc, cx, cy, size);
    if (size < 80) {
        return;
    }
    task5_3(hdc, cx + size, cy + size, size / 2);
    
    task5_3(hdc, cx + size, cy - size, size / 2);
    task5_3(hdc, cx - size, cy - size, size / 2);
    task5_3(hdc, cx - size, cy + size, size / 2);
}

void taskFromLab21(HDC hdc, int cx, int cy, int size) {
    counter++;
    TriangleSpecial(hdc, cx, cy, size);

    if (size < 5) {
        return;
    }

    taskFromLab21(hdc, cx, cy-size, size / 2);
    taskFromLab21(hdc, cx+size, cy+size, size / 2);
}






enum Modes {
    image1_1,
    image1_2,
    image1_3,
    image2_1,
    image2_2,
    image2_3,
    image3_1,
    image3_2,
    image3_3,
    image3_4,
    image4_1,
    image4_2,
    image4_3,
    taskDop,
    lab21,

    mode_none
};
enum Modes mode = image1_1;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
            SelectObject(hdc, hPen);
            switch (mode) {
            case image1_1:
                task1_1(hdc, 200, 200, 100);
                break;
            case image1_2:
                task1_2(hdc, 200, 200, 100);
                break;
            case image1_3:
                task1_3(hdc, 200, 200, 100);
                break;
            case image2_1:
                task2_1(hdc, 200, 200, 100);
                break;
            case image2_2:
                task2_2(hdc, 200, 200, 100);
                break;
            case image2_3:
                task2_3(hdc, 200, 200, 100);
                break;
            case image3_1:
                task3_1(hdc, 200, 200, 100);
                break;
            case image3_2:
                task3_2(hdc, 200, 200, 100);
                break;
            case image3_3:
                task3_3(hdc, 200, 200, 100);
                break;
            case image3_4:
                task3_4(hdc, 200, 200, 100);
                break;
            case image4_1:
                task4_1(hdc, 200, 200, 100);
                break;
            case image4_2:
                task4_2(hdc, 200, 200, 100);
                break;
            case image4_3:
                task4_3(hdc, 200, 200, 100);
                break;
            case taskDop:
                task5_3(hdc, 200, 200, 100);
                break;
            case lab21:
                taskFromLab21(hdc, 200, 200, 100);
                break;
            }
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        mode = (enum Modes)(mode + 1); // переключение на следующий режим
        if (mode == mode_none) mode = image1_1; // если режимы закончились - начинаем заново
        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
