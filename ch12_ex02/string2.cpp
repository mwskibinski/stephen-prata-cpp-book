#include "string2.h"
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany() {
	return num_strings;
}

String::String(const char * s) {
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}
String::String() {
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
String::String(const String & st) {
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}
String::~String() {
	--num_strings;
	delete [] str;
}

const String & String::stringlow() {
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
	return *this;
}
const String & String::stringup() {
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
	return *this;
}
int String::countCh(char ch) const {
	int count = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == ch)
			count++;
	return count;
}

String & String::operator=(const String & st) {
	if (this != &st) {
		delete [] str;
		len = st.len;
		str = new char[len + 1];
		std::strcpy(str, st.str);
	}
	return *this;
}
String & String::operator=(const char * s) {
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}
char & String::operator[](int i) {
	return str[i];
}
const char & String::operator[](int i) const {
 	return str[i];
}
//String String::operator+(const String & rhs) const {
//	char * sum_str = new char [len + rhs.len + 1];
//	strcpy(sum_str, str);
//	strcat(sum_str, rhs.str);
//
//	String result(sum_str);
//
//	delete sum_str;
//
//	return result;
//}

bool operator<(const String & st1, const String & st2) {
	return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String & st1, const String & st2) {
	return st2 < st1;
}
bool operator==(const String & st1, const String & st2) {
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st) {
	os << st.str;
	return os;
}
istream & operator>>(istream & is, String & st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

String operator+(const String & lhs, const String & rhs) {
	char * sum_str = new char [lhs.len + rhs.len + 1];
	strcpy(sum_str, lhs.str);
	strcat(sum_str, rhs.str);

	String result(sum_str);

	delete sum_str;

	return result;
}
