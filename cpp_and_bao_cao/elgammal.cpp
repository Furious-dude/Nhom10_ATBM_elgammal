#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

// luy thua
int modExp(int a, int b, int m)
{
    int result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}
// ktra so nguyen to
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// tao so nguyen to ngau nhien trong [min, max]
int generatePrime(int min, int max)
{
    int num;
    do
    {
        num = min + rand() % (max - min + 1);
    } while (!isPrime(num));
    return num;
}

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    srand(time(0));

    wstring key = L"aáàạảãăắằặẳẵâấầậẩẫbcdđeéẹẻẽêếềệểễfghiíìịỉĩjklmnoóòọỏõôốồộổỗơớờợởỡpqrstuúùụủũưứừựửữvwxyýỳỵỷỹ0123456789- ";
    // wstring key = L"abcdefghijklmnopqrstuvwxyz0123456789- ";
    //  Tạo ánh xạ giữa ký tự và số nguyên
    std::unordered_map<wchar_t, int> char_to_int;
    std::unordered_map<int, wchar_t> int_to_char;
    for (int i = 0; i < key.size(); ++i)
    {
        char_to_int[key[i]] = i;
        int_to_char[i] = key[i];
    }
    // tao so nugyen to p voi so nguyen to g (g la can nguyen thuy cua p)
    int p = generatePrime(100, 300);
    int g = generatePrime(2, p - 1);

    // tao khoa bi mat
    int x = rand() % (p - 2) + 1; // 1 <= x <= p-2

    // tao khoa cong khai y
    int y = modExp(g, x, p);

    std::cout << "khoa cong khai: (p = " << p << ", g = " << g << ", y = " << y << ")\n";
    std::cout << "Khoa bi mat: x = " << x << "\n";

    std::wstring message;
    wcout << "input message: ";
    getline(wcin, message);

    // Mã hóa
    std::vector<int> cipher1;
    std::vector<int> cipher2;
    std::wcout << L"ma hoa: \n";
    for (wchar_t c : message)
    {
        int m = char_to_int[c];
        int k = rand() % (p - 1) + 1; // 1 <= k <= p-1
        int a = modExp(g, k, p);
        int b = (m * modExp(y, k, p)) % p;
        cipher1.push_back(a);
        cipher2.push_back(b);
        std::wcout << L"(" << a << L", " << b << L") ";
    }
    std::wcout << L"\n";

    // Giải mã
    std::wcout << L"thong diep da giai ma: ";
    wstring cache = L"";
    for (int i = 0; i < cipher1.size(); ++i)
    {
        int a = cipher1[i];
        int b = cipher2[i];
        int s = modExp(a, x, p);
        int m = (b * modExp(s, p - 2, p)) % p; // b * s^(-1) mod p
        cache += key[m];
        // std::wcout << int_to_char[m];
    }
    wcout << cache << L"\n";

    return 0;
}