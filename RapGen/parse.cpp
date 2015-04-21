#include <string>
#include <fstream>

using namespace std;

int file_length_rap = 0; // � ����, ��� �� ���������� ����������!
int file_length_user = 0;
int verses_num = 1;
string dict_name = "";


string allocate_num(string test) { // �������� �� ������ ������ ������ ����� � �������
	string buffer = "";

	for (unsigned int i = 0; i < test.length(); i++) {
		if (test[i] > 47 && test[i] < 58) {
			buffer = buffer + test[i];
		}
	}

	return buffer;
}


int convert_to_int(string buffer) { // ��������������� ������ � ������� � �����
	int summ = 0;

	for (unsigned int i = 0; i < buffer.length(); ++i) {
		char c = buffer[i];
		summ += c - '0';
		//if (!( i = buffer.length() - 1 ) )
		summ = summ * 10;
	}

	summ = summ / 10;

	return summ;
}

void constants() { // ��������� ������ �������� �� �����
	int is_found;

	ifstream configs;
	configs.open("configs.txt", ios::in);

	string rap_length, user_length, verses_length, user_dict_name;

	do { // ������ ������ � ������ ��������
		getline(configs, rap_length);
		is_found = rap_length.find("rap_dict");
	} while (is_found == string::npos);


	configs.seekg(0); // ����������� "�������" �� ������ ����� ����� ������� ����� ���������

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

	size_t pos = user_dict_name.find("\"") + 1; // ��������� �� ������ � ������ ������ �����
	dict_name = user_dict_name.substr(pos);		// �������� ���, ��� ����� ������ ����������� �������
	pos = dict_name.find("\"");					// ���������� ���, ��� ����� ������ ����������� �������
	dict_name = dict_name.substr(0, pos);

	configs.close();
}