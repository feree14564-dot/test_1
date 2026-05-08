#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Error, file did not oppend: input.txt" << endl;
        return 1; // завершаем программу с ошибкой
    }
    else cout << "hello world";

    // Позже сюда добавим чтение рёбер

    fin.close(); // можно и без этого (деструктор закроет), но явно — лучше
    return 0;
}
