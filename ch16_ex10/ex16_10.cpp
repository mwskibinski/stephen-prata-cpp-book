#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <cstring>

struct Review {
	std::string title;
	int rating;
	double price;
};

using sptr_Review = std::shared_ptr<Review>;

bool fill_review(Review & rr);
void show_review(const sptr_Review & rr);
void print_header();
bool alfa_sort(const sptr_Review & r1, const sptr_Review & r2);
bool rating_sort(const sptr_Review & r1, const sptr_Review & r2);
bool price_sort(const sptr_Review & r1, const sptr_Review & r2);

int main() {
	using namespace std;

	vector<sptr_Review> books;
	Review temp;
	while (fill_review(temp))
		books.push_back(sptr_Review(new Review(temp)));

	if (books.size() > 0) {
		vector<sptr_Review> books_copy(books);

		cout << "Wybierz opcję wypisywania. Opcje:\n";
		cout << "\t1 - fill, 2 - alfa, 3 - rating asc\n" <<
			"\t4 - rating desc, 5 - price asc, 6 - price desc\n" <<
			"\tx - exit\n" <<
			"> ";
		char choice;
		cin >> choice;
		while (choice != 'x' && choice != 'X') {
			switch (choice) {
			case '1':
				print_header();
				for_each(books.begin(), books.end(), show_review);
				break;
			case '2':
				sort(books_copy.begin(), books_copy.end(), alfa_sort);
				print_header();
				for_each(books_copy.begin(), books_copy.end(), show_review);
				break;
			case '3':
				sort(books_copy.begin(), books_copy.end(), rating_sort);
				print_header();
				for_each(books_copy.begin(), books_copy.end(), show_review);
				break;
			case '4':
				sort(books_copy.begin(), books_copy.end(), rating_sort);
				print_header();
				for_each(books_copy.rbegin(), books_copy.rend(), show_review);
				break;
			case '5':
				sort(books_copy.begin(), books_copy.end(), price_sort);
				print_header();
				for_each(books_copy.begin(), books_copy.end(), show_review);
				break;
			case '6':
				sort(books_copy.begin(), books_copy.end(), price_sort);
				print_header();
				for_each(books_copy.rbegin(), books_copy.rend(), show_review);
				break;
			default:
				cout << "Brak podanej opcji. Spróbuj ponownie.\n";
				break;
			}
			cout << "\nOpcje:\n" <<
				"\t1 - fill, 2 - alfa, 3 - rating asc\n" <<
				"\t4 - rating desc, 5 - price asc, 6 - price desc\n" <<
				"\tx - exit\n" <<
				"> ";
			cin >> choice;
		}
	} else
		cout << "Brak danych.\n";

	cout << "Koniec.\n";

	return 0;
}

bool alfa_sort(const sptr_Review & r1, const sptr_Review & r2) {
	return r1->title < r2->title;
}

bool rating_sort(const sptr_Review & r1, const sptr_Review & r2) {
	return r1->rating < r2->rating;
}

bool price_sort(const sptr_Review & r1, const sptr_Review & r2) {
	return r1->price < r2->price;
}

bool fill_review(Review & rr) {
	std::cout << "Wpisz tytuł książki (koniec, aby zakończyć): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "koniec")
		return false;

	std::cout << "Wpisz ocenę: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;

	std::cout << "Wpisz cenę: ";
	std::cin >> rr.price;
	if (!std::cin)
		return false;

	while (std::cin.get() != '\n')
		continue;

	return true;
}

//void show_review(const sptr_Review & rr) {
//	std::cout <<
//		rr->rating << ", " <<
//		rr->price << ", " <<
//		rr->title << std::endl;
//}

void show_review(const sptr_Review & rr) {
	std::cout <<
		rr->rating << '\t' <<
		rr->price << '\t' <<
		rr->title << std::endl;
}

//inline void print_header() {
//	const char * hdr = "Ocena, Cena, Tytuł\n";
//
//	for (int i = std::strlen(hdr) - 1; i > 0; --i)
//		std::cout << '=';
//	std::cout << '\n';
//
//	std::cout << hdr;
//
//	for (int i = std::strlen(hdr) - 1; i > 0; --i)
//		std::cout << '=';
//	std::cout << '\n';
//}

inline void print_header() {
	std::cout << "=== === === === === === === === === ===\n";
	std::cout << "Ocena\tCena\tTytuł\n";
	std::cout << "=== === === === === === === === === ===\n";
}
