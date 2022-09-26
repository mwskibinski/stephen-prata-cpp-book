#ifndef PERSON_H_
#define PERSON_H_

// Nie podoba mi się to, ale w deklaracji klasy tak zostały zdefiniowane typy danych.
using namespace std;

class Person {
private:
	static const int LIMIT = 256;
	string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = '\0'; }
	Person(const string & ln, const char * fn = "HejTy");

	void Show() const;
	void FormalShow() const;
};

#endif // PERSON_H_
