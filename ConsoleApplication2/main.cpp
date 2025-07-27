#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;


void clearInputBuffer() {
    setlocale(LC_ALL, "RU");
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayHeader() {
    setlocale(LC_ALL, "RU");
    cout << "=================================\n";
    cout << "  ����������� ������� ��� ����������\n";
    cout << "=================================\n\n";
}

void displayMacronutrients(double calories, double protein, double weight) {
    setlocale(LC_ALL, "RU");
    cout << "\n\n=== ������������� ������� ����� ===\n";
    cout << fixed << setprecision(1);
    cout << "�������: " << calories << " ����\n";
    cout << "�����: " << protein << " � (" << protein * 4 << " ����)\n";

    double fat = weight * 0.8; // 0.8� �� �� ����
    cout << "����: " << fat << " � (" << fat * 9 << " ����)\n";

    double remainingCals = calories - (protein * 4 + fat * 9);
    double carbs = remainingCals / 4;
    cout << "��������: " << carbs << " � (" << carbs * 4 << " ����)\n";

    cout << "\n����������� ���:\n";
    cout << "�����: " << (protein * 4) / calories * 100 << "%\n";
    cout << "����: " << (fat * 9) / calories * 100 << "%\n";
    cout << "��������: " << (carbs * 4) / calories * 100 << "%\n";
}

void displayActivityLevels() {
    setlocale(LC_ALL, "RU");
    cout << "\n�������� ������� ����������:\n";
    cout << "1. ������� ����� ����� (������� ��������)\n";
    cout << "2. ������ ���������� (������ ���������� 1-3 ���/������)\n";
    cout << "3. ��������� ���������� (���������� 3-5 ����/������)\n";
    cout << "4. ������� ���������� (����������� ���������� 6-7 ����/������)\n";
    cout << "5. ������������� ���������� (������� ���������� � ���������� ������)\n";
}

double getActivityMultiplier(int activityLevel) {
    switch (activityLevel) {
    case 1: return 1.2;
    case 2: return 1.375;
    case 3: return 1.55;
    case 4: return 1.725;
    case 5: return 1.9;
    default: return 1.2;
    }
}

void displayGoals() {
    setlocale(LC_ALL, "RU");
    cout << "\n�������� ���� ����:\n";
    cout << "1. ��������� (������� �������)\n";
    cout << "2. ����������� ����\n";
    cout << "3. ����� �������� ����� (�������� �������)\n";
}

double getGoalMultiplier(int goal) {
    switch (goal) {
    case 1: return 0.85; // 15% �������
    case 2: return 1.0;
    case 3: return 1.15; // 15% ��������
    default: return 1.0;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    displayHeader();

    // ���� ������ ������������
    double weight, height;
    int age, gender, activityLevel, goal;

    cout << "������� ��� ��� (��): ";
    while (!(cin >> weight) || weight <= 0) {
        cout << "�������� ����. ����������, ������� ������������� �����: ";
        clearInputBuffer();
    }

    cout << "������� ��� ���� (��): ";
    while (!(cin >> height) || height <= 0) {
        cout << "�������� ����. ����������, ������� ������������� �����: ";
        clearInputBuffer();
    }

    cout << "������� ��� �������: ";
    while (!(cin >> age) || age <= 0) {
        cout << "�������� ����. ����������, ������� ������������� �����: ";
        clearInputBuffer();
    }

    cout << "�������� ��� (1 - �������, 2 - �������): ";
    while (!(cin >> gender) || (gender != 1 && gender != 2)) {
        cout << "�������� ����. ����������, ������� 1 ��� 2: ";
        clearInputBuffer();
    }

    displayActivityLevels();
    cout << "��� �����: ";
    while (!(cin >> activityLevel) || activityLevel < 1 || activityLevel > 5) {
        cout << "�������� ����. ����������, ������� ����� �� 1 �� 5: ";
        clearInputBuffer();
    }

    displayGoals();
    cout << "��� �����: ";
    while (!(cin >> goal) || goal < 1 || goal > 3) {
        cout << "�������� ����. ����������, ������� ����� �� 1 �� 3: ";
        clearInputBuffer();
    }

    // ������ �������� ����������� (������� �������-���������)
    double bmr;
    if (gender == 1) {
        bmr = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    }
    else {
        bmr = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }

    // ���� ������ ����������
    double tdee = bmr * getActivityMultiplier(activityLevel);

    // ���� ����
    double dailyCalories = tdee * getGoalMultiplier(goal);

    // ������ ����� (1.6-2.2�/�� ��� ������ �����, 1.2-1.6�/�� ��� ������ �����)
    double protein;
    if (goal == 3) {
        protein = weight * 2.0; // ������ ����� ��� ������ ����
    }
    else {
        protein = weight * 1.6; // ��������� ���������� �����
    }

    // ����� �����������
    displayMacronutrients(dailyCalories, protein, weight);

    cout << "\n\n=== �������������� ������������ ===\n";
    cout << "1. ����� ������� " << weight * 35 << " �� ���� � ����\n";
    cout << "2. ������������� ����� �� 3-5 ������� ����\n";
    cout << "3. ��������� ������������ ������� ���������\n";
    cout << "4. ��� ������ �����: �������� 10-15% �� �����\n";
    cout << "5. ��� ���������: ������� 15-20% �� �����\n";

    cout << "\n������� Enter ��� ������...";
    clearInputBuffer();
    cin.get();

    return 0;
}