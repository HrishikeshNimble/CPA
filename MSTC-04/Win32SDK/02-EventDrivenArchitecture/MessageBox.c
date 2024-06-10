 #include <Windows.h>

 #pragma comment(lib,"user32.lib")
 #pragma comment(lib,"gdi32.lib")
 #pragma comment(lib,"kernel32.lib")

 LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

 int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdline, int nShowCmd)
 {
    static TCHAR szClassName[] = TEXT("This Standard Window");
    static TCHAR szAppName[] = TEXT("HVN: Event Driven Architecture");

    HWND hwnd = NULL;

    WNDCLASSEX wnd;
    MSG msg;
    
    ZeroMemory(&wnd, sizeof(WNDCLASSEX));
    ZeroMemory(&msg, sizeof(MSG));

    wnd.cbSize = sizeof(WNDCLASSEX);
    wnd.cbClsExtra = 0;
    wnd.cbWndExtra = 0;
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hIconSm = LoadCursor(NULL, IDI_APPLICATION);
    wnd.hInstance = hInstance;
    wnd.lpszClassName = szClassName;
    wnd.lpszMenuName = NULL;
    wnd.lpfnWndProc = WndProc;
    wnd.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClassEx(&wnd))
    {
        MessageBox(NULL, 
                   TEXT("Error in registering a class"),
                   TEXT("RegisterClassEX"),
                   MB_TOPMOST | MB_ICONERROR);
        
        ExitProcess(EXIT_FAILURE);
    }

    hwnd = CreateWindowEx(
        WS_EX_APPWINDOW,
        szClassName,
        szAppName,
        WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if(hwnd == NULL)
    {
        MessageBox(NULL,
                   TEXT("Error in creating window"),
                   TEXT("CreateWindowEx"),
                   MB_TOPMOST | MB_ICONERROR
        );

        ExitProcess(EXIT_FAILURE);
    }

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    while(GetMessage(&msg, NULL, 0 ,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return(msg.wParam);
 }

 LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
 {
    switch(uMsg)
    {
        case WM_RBUTTONDOWN:
            MessageBox(NULL,
                       TEXT("Mouse: Right Button is Clicked"),
                       TEXT("WM_RBUTTONDOWN"),
                       MB_OK);
            break;

        case WM_LBUTTONDOWN:
            MessageBox(NULL,
                       TEXT("Mouse: Left Button is Clicked"),
                       TEXT("WM_LBUTTONDOWN"),
                       MB_OK);
            break;
        case WM_CHAR:
            switch(wParam)
            {
                case 'F':
                case 'f':
                    MessageBox(NULL,
                               TEXT("Keyboard: 'F' key is pressed"),
                               TEXT("WM_CHAR"),
                               MB_OK);
                    break;
                default:
                    MessageBox(NULL,
                               TEXT("Keyboard: Random key is pressed"),
                               TEXT("WM_CHAR"),
                               MB_OK);
                    break;
            }
            break;

        case WM_DESTROY:
             PostQuitMessage(EXIT_SUCCESS);
             break;
        
        default:
            break;
    }

    return (DefWindowProc(hwnd,uMsg,wParam, lParam));

 }
 