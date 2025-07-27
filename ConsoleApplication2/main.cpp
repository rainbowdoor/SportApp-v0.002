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
    cout << "  КАЛЬКУЛЯТОР ПИТАНИЯ ДЛЯ ТРЕНИРОВОК\n";
    cout << "=================================\n\n";
}

void displayMacronutrients(double calories, double protein, double weight) {
    setlocale(LC_ALL, "RU");
    cout << "\n\n=== РЕКОМЕНДУЕМЫЕ ДНЕВНЫЕ НОРМЫ ===\n";
    cout << fixed << setprecision(1);
    cout << "Калории: " << calories << " ккал\n";
    cout << "Белки: " << protein << " г (" << protein * 4 << " ккал)\n";

    double fat = weight * 0.8; // 0.8г на кг веса
    cout << "Жиры: " << fat << " г (" << fat * 9 << " ккал)\n";

    double remainingCals = calories - (protein * 4 + fat * 9);
    double carbs = remainingCals / 4;
    cout << "Углеводы: " << carbs << " г (" << carbs * 4 << " ккал)\n";

    cout << "\nСоотношение БЖУ:\n";
    cout << "Белки: " << (protein * 4) / calories * 100 << "%\n";
    cout << "Жиры: " << (fat * 9) / calories * 100 << "%\n";
    cout << "Углеводы: " << (carbs * 4) / calories * 100 << "%\n";
}

void displayActivityLevels() {
    setlocale(LC_ALL, "RU");
    cout << "\nВыберите уровень активности:\n";
    cout << "1. Сидячий образ жизни (минимум движения)\n";
    cout << "2. Низкая активность (легкие тренировки 1-3 дня/неделю)\n";
    cout << "3. Умеренная активность (тренировки 3-5 дней/неделю)\n";
    cout << "4. Высокая активность (интенсивные тренировки 6-7 дней/неделю)\n";
    cout << "5. Экстремальная активность (тяжелые тренировки и физическая работа)\n";
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
    cout << "\nВыберите вашу цель:\n";
    cout << "1. Похудение (дефицит калорий)\n";
    cout << "2. Поддержание веса\n";
    cout << "3. Набор мышечной массы (профицит калорий)\n";
}

double getGoalMultiplier(int goal) {
    switch (goal) {
    case 1: return 0.85; // 15% дефицит
    case 2: return 1.0;
    case 3: return 1.15; // 15% профицит
    default: return 1.0;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    displayHeader();

    // Ввод данных пользователя
    double weight, height;
    int age, gender, activityLevel, goal;

    cout << "Введите ваш вес (кг): ";
    while (!(cin >> weight) || weight <= 0) {
        cout << "Неверный ввод. Пожалуйста, введите положительное число: ";
        clearInputBuffer();
    }

    cout << "Введите ваш рост (см): ";
    while (!(cin >> height) || height <= 0) {
        cout << "Неверный ввод. Пожалуйста, введите положительное число: ";
        clearInputBuffer();
    }

    cout << "Введите ваш возраст: ";
    while (!(cin >> age) || age <= 0) {
        cout << "Неверный ввод. Пожалуйста, введите положительное число: ";
        clearInputBuffer();
    }

    cout << "Выберите пол (1 - Мужской, 2 - Женский): ";
    while (!(cin >> gender) || (gender != 1 && gender != 2)) {
        cout << "Неверный ввод. Пожалуйста, введите 1 или 2: ";
        clearInputBuffer();
    }

    displayActivityLevels();
    cout << "Ваш выбор: ";
    while (!(cin >> activityLevel) || activityLevel < 1 || activityLevel > 5) {
        cout << "Неверный ввод. Пожалуйста, введите число от 1 до 5: ";
        clearInputBuffer();
    }

    displayGoals();
    cout << "Ваш выбор: ";
    while (!(cin >> goal) || goal < 1 || goal > 3) {
        cout << "Неверный ввод. Пожалуйста, введите число от 1 до 3: ";
        clearInputBuffer();
    }

    // Расчет базового метаболизма (формула Харриса-Бенедикта)
    double bmr;
    if (gender == 1) {
        bmr = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    }
    else {
        bmr = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }

    // Учет уровня активности
    double tdee = bmr * getActivityMultiplier(activityLevel);

    // Учет цели
    double dailyCalories = tdee * getGoalMultiplier(goal);

    // Расчет белка (1.6-2.2г/кг для набора массы, 1.2-1.6г/кг для других целей)
    double protein;
    if (goal == 3) {
        protein = weight * 2.0; // Больше белка для набора мышц
    }
    else {
        protein = weight * 1.6; // Умеренное количество белка
    }

    // Вывод результатов
    displayMacronutrients(dailyCalories, protein, weight);

    cout << "\n\n=== ДОПОЛНИТЕЛЬНЫЕ РЕКОМЕНДАЦИИ ===\n";
    cout << "1. Пейте минимум " << weight * 35 << " мл воды в день\n";
    cout << "2. Распределяйте белок на 3-5 приемов пищи\n";
    cout << "3. Отдавайте предпочтение цельным продуктам\n";
    cout << "4. Для набора массы: профицит 10-15% от нормы\n";
    cout << "5. Для похудения: дефицит 15-20% от нормы\n";

    cout << "\nНажмите Enter для выхода...";
    clearInputBuffer();
    cin.get();

    return 0;
}