#include <iostream>

using namespace std;
int main() {

	//Ñïðàøèâàåì âåñ
	short weight;
	cout << "What's your weight ?\n";
	cin >> weight;

	//Ñïðàøèâàåì ðîñò
	short tall;
	cout << "What is your height ?\n";
	cin >> tall;

	//Ñïðàøèâàåì âîçðàñò
	short age;
	cout << "How old are you ?\n";
	cin >> age;

	//Óòî÷íÿåì ïîë
	short gender;
	cout << "What is your gender ? Set 1 for Male, set 2 for female\n";
	std::cin >> gender;

	// Ôîðìóëà äëÿ ìóæ÷èí
	if (gender == 1) {
		cout << "You need to eat every day " << 10 * weight + 6.25 * tall - 5 * age + 5 << " calories, including " << weight * 1.5 << " grams of protein per day\n";

	}

	//Ôîðìóëà äëÿ æåíùèí
	if (gender == 2) {
		cout << "You need to eat every day " << 10 * weight + 6.25 * tall - 5 * age - 161 << " calories, including " << weight * 1.3 << " grams of protein per day\n";

	}


	return 0;
}

