#include <iostream>
#include <windows.h>
using namespace std;
void menu() {
    int choice,second_choice;
    cout << "Меню" << endl;
    cout << "1 – Добавление объекта" << endl;
    cout << "2 – Удаление объекта" << endl;
    cout << "3 – Вывод объектов на экран" << endl;
    cout << "4 – Сохранение состояния гаража в файл" << endl;
    cout << "5 – Загрузка состояния гаража из файла" << endl;
    cout << "6 – Выход из программы" << endl;

    do {
        cout << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Что вы хотите добавить в гараж?" << endl;
                cout << "1 – Автомобиль" << endl;
                cout << "2 – Мотоцикл" << endl;
                cout << "3 – Автобус" << endl;
                cout << "4 – Вернуться обратно" << endl;
                cin >> second_choice;
                do {
                    switch (second_choice) {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Введите число от 1 до 4!" << endl;
                            break;
                    }
                } while (second_choice != 4);
                break;
            case 2:
                cout << "Что вы хотите убрать из гаража?" << endl;
                cout << "1 – Автомобиль" << endl;
                cout << "2 – Мотоцикл" << endl;
                cout << "3 – Автобус" << endl;
                cout << "4 – Вернуться обратно" << endl;
                cin >> second_choice;
                do {
                    switch (second_choice) {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Введите число от 1 до 4!" << endl;
                            break;
                    }
                } while (second_choice != 4);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5: {
                break;
            }
            case 6: {
                cout << "Выход..." << endl;
                break;
            }
            default:
                cout << "Введите число от 1 до 6!" << endl;
                break;
        }
    } while (choice != 6);
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    wcout.imbue(locale(""));
    menu();
    return 0;
}