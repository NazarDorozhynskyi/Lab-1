#include <iostream>
#include <Windows.h>
using namespace std;
double const pi = 3.14;

/* Створюємо клас */
class Cone {
private:
    double Radius; // радіус основи
    double Height; // висота

public:
    // Описуємо конструктор
    Cone() {
        Radius = Height = 0;
    }

    // Описуємо конструктор (використовуємо перегрузку функції конструктора)
    Cone(double valueRadius, double valueHeight) {
        Radius = valueRadius;
        Height = valueHeight;
    }

    // Описуємо деструктор
    ~Cone() {}

    // Функція отримання значення об'єкта поля Радіус
    double GetRadius() {
        return Radius;
    }

    // Функція отримання значення об'єкта поля Висота
    double GetHeight() {
        return Height;
    }

    // Функція зміни значення об'єкта поля Радіус
    void SetRadius(double valueRadius) {
        while (valueRadius <= 0) {
            cout << "Некоректно значення радіуса! Введіть ще раз: ";
            cin >> valueRadius;
        }
        Radius = valueRadius;
    }

    // Функція зміни значення об'єкта поля Висота
    void SetHeight(double valueHeight) {
        while (valueHeight <= 0) {
            cout << "Некоректно значення висоти! Введіть ще раз: ";
            cin >> valueHeight;
        }
        Height = valueHeight;
    }

    // Прототипи функцій (описані нижче)
    void Print(void);
    double Volume(Cone& obj);
    double Area(Cone& obj);
};

// Опис функції виводу значень радіуса та висоти на екран
void Cone::Print(void) {
    cout << "Радіус: " << Radius << "\tВисота: " << Height << endl;
}

// Опис функції знаходження Об'єму конуса
double Cone::Volume(Cone& obj) {
    return (pi * Radius * Radius * Height) / 3;
}

// Опис функції знаходження повної Площі поверхні конуса
double Cone::Area(Cone& obj) {
    double l = sqrt(Height * Height + Radius * Radius); // твірна конуса
    return pi * Radius * (Radius + l); // повна площа поверхні конуса
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); // Підключаємо кирилицю

    Cone obj1(4, 5); // Створюємо перший об'єкт класу

    /* Викликаємо функції геттерів та виводимо занчення радіуса та висоти на екран */
    cout << "Радіус: " << obj1.GetRadius() << "\tВисота: " << obj1.GetHeight() << endl;

    /* Викликаємо функції сеттерів для радіуса та висоти з некоректними параметрами */
    obj1.SetRadius(-1);
    obj1.SetHeight(0);

    obj1.Print(); // Викликаємо функцію виводу на екран радіуса та висоти

    /* Викликаємо функції знаходження об'єму та повної площі конуса, виводимо на екран */
    cout << "Об'єм конуса: " << obj1.Volume(obj1) << endl;
    cout << "Площа повної поверхні конуса: " << obj1.Area(obj1) << "\n\n";

    Cone obj2; // Створюємо другий об'єкт класу (використовуємо інший конструктор)

    cout << "Введіть значення радіуса: ";
    double Radius;
    cin >> Radius;
    obj2.SetRadius(Radius); // Викликаємо сеттер і передаємо аргумент значення радіуса

    cout << "Введіть значення висоти: ";
    double Height;
    cin >> Height;
    obj2.SetHeight(Height); // Викликаємо сеттер і передаємо аргумент значення висоти

    obj2.Print(); // Викликаємо функцію виводу на екран радіуса та висоти

    /* Викликаємо функції знаходження об'єму та повної площі конуса, виводимо на екран */
    cout << "Об'єм конуса: " << obj2.Volume(obj2) << endl;
    cout << "Площа повної поверхні конуса: " << obj2.Area(obj2) << endl;

    return 0;
}
