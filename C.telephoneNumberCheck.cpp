/*
  Name: telephoneNumberCheck
  Author: roboco
  Date: 02.09.2022 11:20
  Task name: C. Телефонные номера
  Descriprion:	Телефонные номера в адресной книге мобильного телефона имеют один из следующих форматов: +7<код><номер>, 8<код><номер>, <номер>, где <номер> — это семь цифр, а <код> — это три цифры или три цифры в круглых скобках. Если код не указан, то считается, что он равен 495. Кроме того, в записи телефонного номера может стоять знак “-” между любыми двумя цифрами (см. пример). На данный момент в адресной книге телефона Васи записано всего три телефонных номера, и он хочет записать туда еще один. Но он не может понять, не записан ли уже такой номер в телефонной книге. Помогите ему! Два телефонных номера совпадают, если у них равны коды и равны номера. Например, +7(916)0123456 и 89160123456 — это один и тот же номер.
  Формат ввода:
  В первой строке входных данных записан номер телефона, который Вася хочет добавить в адресную книгу своего телефона. В следующих трех строках записаны три номера телефонов, которые уже находятся в адресной книге телефона Васи. Гарантируется, что каждая из записей соответствует одному из трех приведенных в условии форматов.
  Формат вывода:
  Для каждого телефонного номера в адресной книге выведите YES (заглавными буквами), если он совпадает с тем телефонным номером, который Вася хочет добавить в адресную книгу или NO (заглавными буквами) в противном случае.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

int main() {

	std::ifstream file{"input.txt"};

	std::vector <std::string> phoneBook;

	for (std::string line; std::getline(file, line);) phoneBook.push_back(line);

	for (auto &number : phoneBook) {
		number.erase(std::remove_if(number.begin(), number.end(), [](unsigned char c) {
			return !std::isalnum(c);
		}), number.end());
		if (number.size() == 7)
			number.insert(0, "8495");
		else if (number.size() == 11)
			number[0] = '8';
		//std::cout << number << std::endl;
	}

	for (int i = 1; i < phoneBook.size(); i++) {
		if (phoneBook[i] == phoneBook[0]) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}
