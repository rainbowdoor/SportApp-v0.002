#include <iostream>

using namespace std;
int main() {

	// ves
	short weight;
	cout << "What's your weight ?\n";
	std::cin >> weight;

	//rost 
	short tall;
	cout << "What is your height ?\n";
	std::cin >> tall;

	//vozrast
	short age;
	cout << "How old are you ?\n";
	std::cin >> age;

	// gender
	short gender;
	cout << "What is your gender ? Set 1 for Male, set 2 for female\n";
	std::cin >> gender;

	// uslovie
	if (gender == 1) {
		std::cout << "You need to eat every day " << 10 * weight + 6.25 * tall - 5 * age + 5 << " calories, including " << weight * 1.5 << " grams of protein per day\n";

	}
	else (gender >= 2); {
		std::cout << "Repeat please";
	}

	// uslovie
	if (gender == 2) {
		std::cout << "You need to eat every day " << 10 * weight + 6.25 * tall - 5 * age - 161 << " calories, including " << weight * 1.3 << " grams of protein per day\n";

	}


	return 0;
}

