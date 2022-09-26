#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person
{
private:
	std::string fullname;
	int age;
public:
	Person(const std::string & fn = "brak", int age = 0);
	virtual ~Person();

	virtual void show() const;
	virtual void set();

	const std::string & getFullname() const;
	int getAge() const;
	void setFullname(const std::string & fn);
	void setAge(int a);
};

inline const std::string & Person::getFullname() const
{
	return fullname;
}
inline int Person::getAge() const
{
	return age;
}
inline void Person::setFullname(const std::string & fn)
{
	fullname = fn;
}
inline void Person::setAge(int a)
{
	age = a;
}

#endif // PERSON_H_
