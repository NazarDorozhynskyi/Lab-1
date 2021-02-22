#include <iostream>
#include <Windows.h>
using namespace std;
double const pi = 3.14;

/* ��������� ���� */
class Cone {
private:
    double Radius; // ����� ������
    double Height; // ������

public:
    // ������� �����������
    Cone() {
        Radius = Height = 0;
    }

    // ������� ����������� (������������� ���������� ������� ������������)
    Cone(double valueRadius, double valueHeight) {
        Radius = valueRadius;
        Height = valueHeight;
    }

    // ������� ����������
    ~Cone() {}

    // ������� ��������� �������� ��'���� ���� �����
    double GetRadius() {
        return Radius;
    }

    // ������� ��������� �������� ��'���� ���� ������
    double GetHeight() {
        return Height;
    }

    // ������� ���� �������� ��'���� ���� �����
    void SetRadius(double valueRadius) {
        while (valueRadius <= 0) {
            cout << "���������� �������� ������! ������ �� ���: ";
            cin >> valueRadius;
        }
        Radius = valueRadius;
    }

    // ������� ���� �������� ��'���� ���� ������
    void SetHeight(double valueHeight) {
        while (valueHeight <= 0) {
            cout << "���������� �������� ������! ������ �� ���: ";
            cin >> valueHeight;
        }
        Height = valueHeight;
    }

    // ��������� ������� (������ �����)
    void Print(void);
    double Volume(Cone& obj);
    double Area(Cone& obj);
};

// ���� ������� ������ ������� ������ �� ������ �� �����
void Cone::Print(void) {
    cout << "�����: " << Radius << "\t������: " << Height << endl;
}

// ���� ������� ����������� ��'��� ������
double Cone::Volume(Cone& obj) {
    return (pi * Radius * Radius * Height) / 3;
}

// ���� ������� ����������� ����� ����� ������� ������
double Cone::Area(Cone& obj) {
    double l = sqrt(Height * Height + Radius * Radius); // ����� ������
    return pi * Radius * (Radius + l); // ����� ����� ������� ������
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); // ϳ�������� ��������

    Cone obj1(4, 5); // ��������� ������ ��'��� �����

    /* ��������� ������� ������� �� �������� �������� ������ �� ������ �� ����� */
    cout << "�����: " << obj1.GetRadius() << "\t������: " << obj1.GetHeight() << endl;

    /* ��������� ������� ������� ��� ������ �� ������ � ������������ ����������� */
    obj1.SetRadius(-1);
    obj1.SetHeight(0);

    obj1.Print(); // ��������� ������� ������ �� ����� ������ �� ������

    /* ��������� ������� ����������� ��'��� �� ����� ����� ������, �������� �� ����� */
    cout << "��'�� ������: " << obj1.Volume(obj1) << endl;
    cout << "����� ����� ������� ������: " << obj1.Area(obj1) << "\n\n";

    Cone obj2; // ��������� ������ ��'��� ����� (������������� ����� �����������)

    cout << "������ �������� ������: ";
    double Radius;
    cin >> Radius;
    obj2.SetRadius(Radius); // ��������� ������ � �������� �������� �������� ������

    cout << "������ �������� ������: ";
    double Height;
    cin >> Height;
    obj2.SetHeight(Height); // ��������� ������ � �������� �������� �������� ������

    obj2.Print(); // ��������� ������� ������ �� ����� ������ �� ������

    /* ��������� ������� ����������� ��'��� �� ����� ����� ������, �������� �� ����� */
    cout << "��'�� ������: " << obj2.Volume(obj2) << endl;
    cout << "����� ����� ������� ������: " << obj2.Area(obj2) << endl;

    return 0;
}