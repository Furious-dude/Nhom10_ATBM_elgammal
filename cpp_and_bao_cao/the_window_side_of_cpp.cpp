#include <windows.h>
#include <string>

// Global variables
HWND hTextBox1, hTextBox2, hTextBox3, hTextBox4, hTextBox5;
HWND hButton1, hButton2, hButton3, hButton4, hButton5;
HWND hLabel1, hLabel2, hLabel3, hLabel4, hLabel5;
HWND hwnd;
HINSTANCE hInstance;

// Function to handle button clicks
void OnButtonClick(int buttonID) {
    char buffer[256];
    std::string text;
    
    switch (buttonID) {
        case 1: // Ma hoa
            // Add encryption logic here
            break;
        case 2: // Giai ma
            // Add decryption logic here
            break;
        case 4: // Ky-sign
            // Add digital signature logic here
            break;
        case 5: // Kiem tra
            // Add verification logic here
            break;
        default:
            break;
    }
}

// Window Procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            hTextBox1 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 50, 50, 100, 50, hwnd, NULL, hInstance, NULL);
            hTextBox2 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 50, 100, 50, hwnd, NULL, hInstance, NULL);
            hTextBox3 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 50, 100, 50, hwnd, NULL, hInstance, NULL);
            hTextBox4 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 50, 150, 100, 50, hwnd, NULL, hInstance, NULL);
            hTextBox5 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 150, 100, 50, hwnd, NULL, hInstance, NULL);

            hLabel1 = CreateWindow("STATIC", "Plain Text", WS_VISIBLE | WS_CHILD, 50, 30, 100, 20, hwnd, NULL, hInstance, NULL);
            hLabel2 = CreateWindow("STATIC", "Cipher Text", WS_VISIBLE | WS_CHILD, 200, 30, 100, 20, hwnd, NULL, hInstance, NULL);
            hLabel3 = CreateWindow("STATIC", "Plain Text", WS_VISIBLE | WS_CHILD, 350, 30, 100, 20, hwnd, NULL, hInstance, NULL);
            hLabel4 = CreateWindow("STATIC", "Plain Text", WS_VISIBLE | WS_CHILD, 50, 130, 100, 20, hwnd, NULL, hInstance, NULL);
            hLabel5 = CreateWindow("STATIC", "Plain Text", WS_VISIBLE | WS_CHILD, 200, 130, 100, 20, hwnd, NULL, hInstance, NULL);

            hButton1 = CreateWindow("BUTTON", "Ma hoa", WS_VISIBLE | WS_CHILD, 50, 250, 50, 60, hwnd, (HMENU)1, hInstance, NULL);
            hButton2 = CreateWindow("BUTTON", "Giai ma", WS_VISIBLE | WS_CHILD, 150, 250, 50, 60, hwnd, (HMENU)2, hInstance, NULL);
            hButton3 = CreateWindow("BUTTON", "null", WS_VISIBLE | WS_CHILD, 250, 250, 50, 60, hwnd, (HMENU)3, hInstance, NULL);
            hButton4 = CreateWindow("BUTTON", "Ky-sign", WS_VISIBLE | WS_CHILD, 350, 250, 50, 60, hwnd, (HMENU)4, hInstance, NULL);
            hButton5 = CreateWindow("BUTTON", "Kiem tra", WS_VISIBLE | WS_CHILD, 450, 250, 50, 60, hwnd, (HMENU)5, hInstance, NULL);

            break;

        case WM_COMMAND:
            if (HIWORD(wParam) == BN_CLICKED) {
                int buttonID = LOWORD(wParam);
                OnButtonClick(buttonID);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {
    hInstance = hInst;
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInst;
    wc.lpszClassName = "MyWindowClass";

    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, "MyWindowClass", "Simple Window", WS_OVERLAPPEDWINDOW, 100, 100, 600, 400, NULL, NULL, hInst, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}