#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

extern int file_length_rap; // просто дохренища глобальных переменных, мне очень стыдно, правда =(
extern int file_length_user;
extern int verses_num;
extern string dict_name;

extern vector <string> test_buffer;
vector <string> output_buffer; // научите меня работать с указателями на векторы


const string imenno = "Заметь, сам признался\n"; // и вообще с указателями в принципе
const string name = "mamku ebal";



string word_out_rap() { // процедура, вытаскивающая рандомное слово из рэперского словаря

	int random_num, random_buffer = 0;
	int count = 0; 

	ifstream file;
	file.open("dict_rap.txt", ios::in);

	

	string line;
	if (file) {

		

		random_num = rand() % (file_length_rap + 1); 
		
		if (random_num == random_buffer) {
			while (random_num == random_buffer) {		
				random_num = rand() % (file_length_rap + 1);
			}
			
		}
		random_buffer = random_num;

		while (getline(file, line)) {
			count++;

			if (count == random_num) {
				getline(file, line);
				break;
				
			}
		}

	}
	else cout << "Ошибка при открытии файла\n";
	file.close();

	return line;
}



const string pravda = "edinorogi govno";



void azaza() { // моя фантазия на названия функций иссякла
	const int azaza_count = 16;

	string rap_about_mamka[azaza_count] = { "полыхает", "бомбит", "пиздец", "сука", "мразь", "мать цветное", "огребаешь",
		"баттхерт", "разорву", "нахуй", "убъю за мать", "молчи", "бохнакажэт", "сдохни", "я тебя найду", "как ты посмел" };

	int r, r1 = 0; // ты не поймешь, что значат эти переменные. я же не понимаю.

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3 + rand() % 2; j++) {

			r = rand() % azaza_count;
			while (r1 == r) {
				if (r1 == r) {
					r = rand() % azaza_count;
				}
			}

			r1 = r;
			//cout << rap_about_mamka[r] << " "; 
			output_buffer.push_back(rap_about_mamka[r]);
			output_buffer.push_back(" ");

		}
		//cout << "\n";
		output_buffer.push_back("\n");
	}

	for (unsigned int i = 0; i < output_buffer.size(); i++) {
		cout << output_buffer.at(i);
	}
	//setlocale(0,".866");
}



string word_out_user() { // аналогично рэперской, просто словарь другой

	int random_num, random_buffer = 0;
	int count = 0;

	ifstream file;
	file.open("dict_user.txt", ios::in);

	string line;

	if (file) {
		random_num = rand() % (file_length_user + 1);

	
		while (getline(file, line)) {
			count++;

			if (count == random_num) {
				getline(file, line);
				break;
				
			}
		}
	} else cerr << "Ошибка при открытии файла\n";

	file.close();

	return line;
}


void saveResult(string filename) {

	ofstream saved_file;

	saved_file.open(filename);

	vector <string> azaza;

	
	if (saved_file) {
		for (unsigned int i = 0; i < output_buffer.size(); i++) {
			saved_file << output_buffer.at(i);
		}
	} else
		cerr << "Извините, при создании выходного файла произошла ошибка\n";

	saved_file.close();
}



void rap() {

	string line = "", line_buffer = "";

	for (int abz = 0; abz < 4; abz++) { // 4 абзаца
		for (int row = 0; row < 4; row++) { // 4 строки в абзаце (row - строка)
			for (int slov = 0; slov < (3 + rand() % 2); slov++) { // рандомно 3 или 4 слова в строке

				if (line_buffer == line) {
					while (line_buffer == line) {
						line = word_out_rap();						
					}
				}

				setlocale(0, ".1251");
			
				output_buffer.push_back(line); // слова и пробелы с управляющими символами проталкиваются в вектор
				output_buffer.push_back(" ");  

				line_buffer = line;

			}

			output_buffer.push_back("\n");
		}

		output_buffer.push_back("\n\n");
	}

	for (unsigned int i = 0; i < output_buffer.size(); i++) { // далее из вектора выводится все разом
		cout << output_buffer.at(i);
	}

}



void user() {

	string line = "", line_buffer = "";

	for (int verse = 0; verse < verses_num; verse++) { // аналогично, только число абзацев произвольно
		for (int row = 0; row < 4; row++) {
			for (int slov = 0; slov < (3 + rand() % 2); slov++) {

				if (line_buffer == line) {
					while (line_buffer == line) {
						line = word_out_user();
					}
				}

				setlocale(0, ".1251");

				output_buffer.push_back(line); 
				output_buffer.push_back(" ");
				line_buffer = line;

			}

			output_buffer.push_back("\n");
		}

		output_buffer.push_back("\n\n");
	}


	for (unsigned int i = 0; i < output_buffer.size(); i++) {
		cout << output_buffer.at(i);
	}

}



extern void constants();


int main() { //все просто

	srand( static_cast<unsigned int>(time( 0 ) ) );

	string line;
	string command;

	string filename = "";


	constants();



	setlocale(0, ".1251");
	cout << "Длина словаря рэпа - " << file_length_rap << ", юзера - " << file_length_user << endl;
	cout << "Генератор рэпа 1.1 by DeadlyManul\n\n"
		 << "Словарь Ивана-рэпера - 1, " << dict_name << " - 2\n";
	
	setlocale(0, ".866");
	getline(cin, command);

	setlocale(0, ".1251");

	if (command == pravda) {
		cout << imenno;
	}

	if (command == name) {
		azaza();
	}


	switch (command[0]) {

		case '1':
			rap();
			break;

		case '2':
			user();
			break;
	
	}


	cout << "Вывести результат в файл? (y/n)\n";
	cin >> command[0];

	switch (command[0]) {

		case 'y':
			cout << "Введите имя файла:\n";

			cin >> filename;

			saveResult(filename);

			break;

		case 'n':
			cout << "Как хочешь.\n";
			break;

		default:
			cout << "Несуществующая команда.\n";
			break;
	}

	system("pause");
	return 0;
}