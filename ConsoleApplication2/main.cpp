#include <iostream>

using namespace std;
int main() {

	//Спрашиваем вес
	int weight;
	cout << "What's your weight ?\n";
	cin >> weight;

	//Спрашиваем рост
	int tall;
	cout << "What is your height ?\n";
	cin >> tall;

	//Спрашиваем возраст
	int age;
	cout << "How old are you ?\n";
	cin >> age;

	//Уточняем пол
	int gender;
	cout << "What is your gender ? Set 1 for Male, set 2 for female\n";
	std::cin >> gender;

	// Формула для мужчин
	if (gender == 1) {
		cout << "You need to eat every day " << 10 * weight + 6.25 * tall - 5 * age + 5 << " calories, including " << weight * 1.5 << " grams of protein per day\n";

	}

	//Формула для женщин
	if (gender == 2) {
		cout << "You need to eat every day " << 10 * weight + 6.25 * tall - 5 * age - 161 << " calories, including " << weight * 1.3 << " grams of protein per day\n";

	}


	return 0;
}

