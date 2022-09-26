#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void showStr(const std::string & s) {
	std::cout << s << std::endl;
}

class Store {
private:
	std::ofstream & fout;
public:
	Store(std::ofstream & of) : fout(of) {}
	void operator()(const std::string & s);
};

void Store::operator()(const std::string & s) {
	int str_len = s.size();
	fout.write((char *) &str_len, sizeof str_len);
	fout.write((char *) s.data(), str_len);
}

void getStrs(std::ifstream & fin, std::vector<std::string> & vs) {
	int str_len = 0;
	while (fin.read((char *) &str_len, sizeof str_len)) {
		std::string tmp(str_len, ' ');
		fin.read((char *) &tmp[0], str_len);
		vs.push_back(tmp);
	}
}

int main() {
	using namespace std;
	vector<string> vostr;
	string temp;

	cout << "Podaj łańcuchy (aby zakończyć, wprowadź pusty wiersz):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Oto twoje dane wejściowe.\n";
	for_each(vostr.begin(), vostr.end(), showStr);

	ofstream fout("lancuchy.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string> vistr;
	ifstream fin("lancuchy.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		cerr << "Nie można otworzyć pliku do odczytu.\n";
		exit(EXIT_FAILURE);
	}

	getStrs(fin, vistr);
	cout << "\nOto łańcuchy odczytane z pliku:\n";
	for_each(vistr.begin(), vistr.end(), showStr);

	return 0;
}
