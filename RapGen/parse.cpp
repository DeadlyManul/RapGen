#include <string>
#include <fstream>

using namespace std;

int file_length_rap = 0; // о ужас, это же глобальные переменные!
int file_length_user = 0;
int verses_num = 1;
string dict_name = "";


string allocate_num(string test) { // выдел€ет из данной строки только часть с цифрами
	string buffer = "";

	for (unsigned int i = 0; i < test.length(); i++) {
		if (test[i] > 47 && test[i] < 58) { // находим символы чисел, пишем только их
			buffer = buffer + test[i];
		}
	}

	return buffer;
}


int convert_to_int(string buffer) { // преобразовывает строку с цифрами в число
	int summ = 0;

	for (unsigned int i = 0; i < buffer.length(); ++i) {
		char c = buffer[i];
		summ += c - '0'; // если вычесть из кода числа код нул€, то получитс€ как раз само число
						 //if (!( i = buffer.length() - 1 ) )
		summ = summ * 10;
	}

	summ = summ / 10;

	return summ;
}

void getEntry(string name, string * container) {
	ifstream configs;
	configs.open("configs.txt", ios::in);

	string buffer = *container;

	int is_found;

	do { // ищетс€ строка с первым конфигом
		getline(configs, buffer);
		is_found = buffer.find(name);
	} while (is_found == string::npos); //пока не вы€снитс€, что что-то нашлось и строка больше не пуста€

	*container = buffer;

	configs.close();
}

void constants() { // процедура чтени€ конфигов из файла

	string rap_length, user_length, verses_length, user_dict_name;


	//getEntry("rap_dict", &rap_length);
	//getEntry("user_dict", &user_length);
	getEntry("verses_num", &verses_length);
	getEntry("user_dict_name", &user_dict_name);

	//rap_length = allocate_num(rap_length); 
	//user_length = allocate_num(user_length);
	verses_length = allocate_num(verses_length);  //прогон€ем через процедуру поиска цифр, чтобы отсе€ть лишнее


	//file_length_rap = convert_to_int(rap_length); 
	//file_length_user = convert_to_int(user_length);
	verses_num = convert_to_int(verses_length); // оставшиес€ цифры перегон€ютс€ в int


	/* выделение из строки с именем только имени: */

	ifstream rap_file_counter("dict_rap.txt");
	file_length_rap = std::count(istreambuf_iterator<char>(rap_file_counter), istreambuf_iterator<char>(), '\n');
	rap_file_counter.close();

	ifstream user_file_counter("dict_user.txt");
	file_length_user = std::count(istreambuf_iterator<char>(user_file_counter), istreambuf_iterator<char>(), '\n');
	user_file_counter.close();

	size_t pos = user_dict_name.find("\"") + 1; // находим позицию первой кавычки
	dict_name = user_dict_name.substr(pos);		// читаем все, что после первой встреченной кавычки
	pos = dict_name.find("\"");					// обрезаем все, что после второй встреченной кавычки
	dict_name = dict_name.substr(0, pos);

}