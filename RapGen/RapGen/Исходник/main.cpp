#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

int file_length_rap = 0; //о ужас, это же глобальные переменные!
int file_length_user = 0;
int verses_num = 1;
string dict_name = "";

string allocate_num(string test) { //выделяет из данной строки только часть с цифрами
	string buffer = "";

	for (int i = 0; i < test.length(); i++) {
		if (test[i] > 47 && test[i] < 58) {
			buffer = buffer + test[i];
		}
	}

	return buffer;
}


int convert_to_int(string buffer) { //преобразовывает строку с цифрами в число
	int summ = 0;
	for (int i = 0; i < buffer.length(); ++i) {
		char c = buffer[i];
		summ += c - '0';
		//if (!( i = buffer.length() - 1 ) )
		summ = summ * 10;
	}

	summ = summ / 10;

	return summ;
}

string imenno = "Заметь, сам признался\n";

void constants() { //процедура чтения конфигов из файла
	int is_found; 

	ifstream configs;
	configs.open("configs.txt", ios::in);

	string rap_length, user_length, verses_length, user_dict_name;

	do { //ищется строка с первым конфигом, далее чтение идет строго последовательно
		getline(configs, rap_length);
		is_found = rap_length.find("rap_dict");
	} while (is_found == string::npos);

	
	configs.seekg(0); //перемещение "каретки" на начало файла

	do {
		getline(configs, user_length);
		is_found = user_length.find("user_dict");
	} while (is_found == string::npos);

	configs.seekg(0);

	do {
		getline(configs, verses_length);
		is_found = verses_length.find("verses_num");
	} while (is_found == string::npos);

	configs.seekg(0);

	do {
		getline(configs, user_dict_name);
		is_found = user_dict_name.find("user_dict_name");
	} while (is_found == string::npos);

	rap_length = allocate_num(rap_length);
	user_length = allocate_num(user_length);
	verses_length = allocate_num(verses_length);

	//cout << rap_length <<  " " << user_length << "\n";


	file_length_rap = convert_to_int(rap_length);
	file_length_user = convert_to_int(user_length);
	verses_num = convert_to_int(verses_length);
	//cout << file_length_rap << " " << file_length_user << "\n";

	size_t pos = user_dict_name.find("\"") + 1; //выделение из строки с именем только имени
	dict_name = user_dict_name.substr(pos);		//просто режется все, что не между кавычками
	pos = dict_name.find("\"");
	dict_name = dict_name.substr(0, pos);
	
	configs.close();
}

const string name = "mamku ebal";

string word_out_rap() { //процедура, вытаскивающая рандомное слово из рэперского словаря

	int random_num, random_buffer = 0;
	int count = -1; //да, считаем с -1, так надо

	ifstream file;
	file.open("dict_rap.txt", ios::in);

	string line;
	if (file) {
		random_num = rand() % (file_length_rap + 1); 
		
		if (random_num == random_buffer) {
			while (random_num == random_buffer) {		
				random_num = rand() % (file_length_rap + 1);
			}
			//cout << "-ликвидировано совпадение- ";
		}
		random_buffer = random_num;

		while (getline(file, line)) {
			count++;

			if (count == random_num) {
				getline(file, line);
				break;
				//cout << line << " ";
			}
		}

	}
	else cout << "Ошибка при открытии файла\n";
	file.close();

	return line;
}

const string pravda = "edinorogi govno";

void azaza() {
	const int _azaza_num = 16;

	string _ptr_rap_a[_azaza_num] = { "полыхает", "бомбит", "пиздец", "сука", "мразь", "мать цветное", "огребаешь",
		"баттхерт", "разорву", "нахуй", "убъю за мать", "молчи", "бохнакажэт", "сдохни", "я тебя найду", "как ты посмел" };

	int r, r1 = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3 + rand() % 2; j++) {
			r = rand() % _azaza_num;
			while (r1 == r) {
				if (r1 == r) {
					r = rand() % _azaza_num;
				}
			}
			r1 = r;
			cout << _ptr_rap_a[r] << " "; 
		}
		cout << "\n";
	}
}

string word_out_user() { //аналогично рэперской, просто словарь другой

	int random_num, random_buffer = 0;
	int count = -1;

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
				//cout << line << " ";
			}
		}
	} else cout << "Ошибка при открытии файла\n";
	file.close();

	return line;
}


void rap(string filename) {
	//ifstream file;
	ofstream file;
	string line = "", line_buffer = "";

	//file.open("dict_rap.txt", ios::in);

	file.open(filename);
	//if (file) {
		for (int abz = 0; abz < 4; abz++) { //4 абзаца
			for (int strok = 0; strok < 4; strok++) { //4 строки в абзаце
				for (int slov = 0; slov < (3 + rand() % 2); slov++) { //рандомно 3 или 4 слова в строке

					if (line_buffer == line) {
						while (line_buffer == line) {
							line = word_out_rap();						
						}
					}

					cout << line << " ";
					setlocale(0, ".1251");
					file << line << " ";
					line_buffer = line;

				}
				cout << "\n";
				file << "\n";
			}
			cout << "\n\n";
			file << "\n\n";
		}
	//}

	//file.close();
}

void rap() {

	string line = "", line_buffer = "";

	for (int abz = 0; abz < 4; abz++) { //4 абзаца
		for (int strok = 0; strok < 4; strok++) { //4 строки в абзаце
			for (int slov = 0; slov < (3 + rand() % 2); slov++) { //рандомно 3 или 4 слова в строке

				if (line_buffer == line) {
					while (line_buffer == line) {
						line = word_out_rap();
					}
				}

				cout << line << " ";
				setlocale(0, ".1251");
				line_buffer = line;

			}
			cout << "\n";
		}
		cout << "\n\n";
	}

}

void user(string filename) {

	ofstream file;

	file.open(filename);
	string line = "", line_buffer = "";

	if (file) {
		for (int verse = 0; verse < verses_num; verse++) { //аналогично, только число абзацев произвольно
			for (int strok = 0; strok < 4; strok++) {
				for (int slov = 0; slov < (3 + rand() % 2); slov++) {

					if (line_buffer == line) {
						while (line_buffer == line) {
							line = word_out_user();
						}
					}

					cout << line << " ";
					file << line << " ";
					line_buffer = line;

				}
				cout << "\n";
				file << "\n";
			}
			cout << "\n\n";
			file << "\n\n";
		}
	}
}

void user() {
	string line = "", line_buffer = "";

	for (int verse = 0; verse < verses_num; verse++) { //аналогично, только число абзацев произвольно
		for (int strok = 0; strok < 4; strok++) {
			for (int slov = 0; slov < (3 + rand() % 2); slov++) {

				if (line_buffer == line) {
					while (line_buffer == line) {
						line = word_out_user();
					}
				}

				cout << line << " ";
				line_buffer = line;

			}
			cout << "\n";
		}
		cout << "\n\n";
	}
}

int main() { //все просто
	
	srand(time(0));

	string line;
	string com;

	size_t pos;
	string filename = "";
	bool rapflag = false, userflag = false;

	constants();

	setlocale(0, ".1251");
	cout << "Генератор рэпа 1.05 by DeadlyManul\n\n";
	cout << "Словарь Ивана-рэпера - 1, " << dict_name << " - 2\n";
	cout << "Для вывода текста в файл: <номер генератора> -f <имя файла>\n";
	
	setlocale(0, ".866");
	getline(cin, com);

	setlocale(0, ".1251");

	if (com == pravda) {
		cout << imenno;
	}

	if (com == name) {
		azaza();
	}

	setlocale(0, ".866");



	switch (com[0]) {

		case '1':

			if (com.find("-f") != string::npos) {
				rapflag = true;
				pos = com.find("-f");
				filename = com.substr(pos+3);
			}

			setlocale(0, ".1251");
			if (rapflag) {
				cout << "\n";
				rap(filename);
			}
			else {
				cout << "\n";
				rap();
			}
			break;

		case '2':

			if (com.find("-f") != string::npos) {
				userflag = true;
				pos = com.find("-f");
				filename = com.substr(pos + 3);
			}

			setlocale(0, ".1251");

			if (userflag) {
				cout << "\n";
				user(filename);
			}
			else {
				cout << "\n";
				user();
			}
			break;

		default:
			break;
	};

	system("pause");
	return 0;
}