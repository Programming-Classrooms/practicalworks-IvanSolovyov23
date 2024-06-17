#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <fstream>
#include <sstream>
#include "../Train/Train.h"


struct Student
{
	std::string name;
	std::string surname;
	std::string patronymic;
	size_t group;
	size_t course;

	std::string get_full_name() const {
		return surname + " " + name + " " + patronymic;
	}
};


bool is_digit_string(const std::string& s) {
	for (const auto& x : s) {
		if (!isdigit(x)) {
			return false;
		}
	}
	return true;
}

void read_words_in_file(std::vector<std::string>& vector_of_string, const std::string& file_name) {
	std::ifstream fin("src/data/Text.txt");
	if (!fin) {
		throw std::runtime_error("Bad file");
	}
	std::string words;
	while (fin >> words) {
		vector_of_string.push_back(words);
	}
}

void print_vector_of_string(std::vector<std::string> vector_of_string) {
	std::copy(vector_of_string.begin(), vector_of_string.end(), std::ostream_iterator<std::string>(std::cout, "\t"));
	std::cout << std::endl;
}

void checking_word_of_first_letter(char letter, std::vector<std::string>& vector_of_string) {
	size_t counter = 0;
	std::cout << "The following words begin with this letter: " << "\n";
	for (auto const& n : vector_of_string) {
		if (n[0] == letter) {
			std::cout << n << "\t";
			++counter;
		}
	}
	if (counter == 0) {
		std::cout << "\\_('_')_/" << std::endl;
	}
	std::cout << std::endl;
}

void delete_word_of_first_letter(char letter, std::vector<std::string>& vector_of_string) {
	for (auto const& n : vector_of_string) {
		if (n[0] == letter) {
			vector_of_string.erase(std::remove_if(vector_of_string.begin(), vector_of_string.end(), [letter](const std::string& word) {return (word[0] == letter);}), vector_of_string.end());
		}
	}
	std::cout << std::endl;
}

void create_matrix(int& rows, int& columns) {
	std::cout << "Enter the quantity of rows:\t";
	std::cin >> rows;
	if (rows < 0) { throw std::invalid_argument("Invalid size"); };
	std::cout << "\nEnter the quanity of columns:\t";
	std::cin >> columns;
	if (columns < 0) { throw std::invalid_argument("Invalid size"); };
	std::cout << std::endl;
}

void filling_matrix(std::vector<std::vector<int>>& matrix, int& rows, int& columns) {
	std::cout << "Enter elements your matrix: " << "\n";
	for (size_t i = 0; i < rows; ++i) {
		std::vector<int> row;
		for (size_t j = 0; j < columns; ++j) {
			int element = 0;
			std::cout << "[" << i << "]" << "[" << j << "]" << ":\t";
			std::cin >> element;
			row.push_back(element);
		}
		matrix.push_back(row);
	}
}
 
void print_matrix(std::vector<std::vector<int>> matrix) {
	std::cout << "Matrix: " << std::endl;
	for (const auto& row : matrix) {
		for (const auto& element : row) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
}

void create_random_matrix(std::vector<std::vector<int>>& matrix, int& rows, int& columns) {
	int max_value = 0;
	int min_value = 0;
	srand(static_cast<unsigned>(time(0)));
	std::cout << "Enter min and max value in your matrix:\n";
	std::cout << "Min:\t";
	std::cin >> min_value;
	std::cout << "Max:\t";
	std::cin >> max_value;
    for (auto& row : matrix) {
        for (auto& element : row) {
            element = min_value + rand() % (max_value - min_value + 1);
        }
    }
}

void remove_max_element_row_column(std::vector<std::vector<int>>& matrix) {
	if (matrix.empty() || matrix[0].empty()) {
		throw std::runtime_error("Matrix is empty");
	}

	int max_element = matrix[0][0];
	int max_row = 0;
	int max_col = 0;

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[i].size(); ++j) {
			if (matrix[i][j] > max_element) {
				max_element = matrix[i][j];
				max_row = i;
				max_col = j;
			}
		}
	}

	matrix.erase(matrix.begin() + max_row);
	for (auto& row : matrix) {
		row.erase(row.begin() + max_col);
	}
}

int sum_elements_row(std::vector<int> row) {
	return std::accumulate(row.begin(), row.end(), 0);
}

void sort_matrix(std::vector<std::vector<int>>& matrix, int& rows, int& columns) {
	for (size_t i = 0; i < matrix.size() - 1; ++i) {
		for (size_t j = 0; j < matrix.size() - i - 1; ++j) {
			if (sum_elements_row(matrix[j]) > sum_elements_row(matrix[j + 1])) {
				std::swap(matrix[j], matrix[j + 1]);
			}
		}
	}
}

std::vector<Student> read_fio_student(const std::string& file_name) {
	std::vector<Student> students;
	std::ifstream fin(file_name);
	if (!fin) {
		throw std::runtime_error("File is bad");
	}
	std::string line;
	while (getline(fin, line)) {
		std::stringstream ss(line);
		Student student;
		ss >> student.surname >> student.name >> student.patronymic >> student.course >> student.group;
		students.push_back(student);
	}

	fin.close();
	return students;
}

void write_students_by_surname(std::vector<Student>& students, const std::string& filename) {
	std::ofstream out(filename);

	if (!out) {
		throw std::runtime_error("Bad file");
	}

	for (const auto& student : students) {
		out << student.get_full_name() << " " << student.course << " " << student.group << std::endl;
	}

	out.close();
}

void write_sudents_by_course_and_group(std::vector<Student>& students, const std::string& filename) {
	std::ofstream out(filename);

	if (!out) {
		throw std::runtime_error("Bad File");
	}

	for (const auto& student : students) {
		out << student.get_full_name() << " " << student.course << " " << student.group << std::endl;
	}

	out.close();
}

void read_trains(const std::string& filename, std::vector<Train>& trains) {
	std::ifstream fin(filename);
	if (!fin) {
		throw std::runtime_error("Bad file");
	}

	std::string line;
	while (getline(fin, line)) {
		trains.push_back(Train::time_to_string(line));
	}
	fin.close();
}

void sort_trains_by_departure_time(std::vector<Train>& trains) {
	std:sort(trains.begin(), trains.end(), Train::compare_by_departure_time);
}

void print_trains_in_time_range(const std::vector<Train>& trains, const std::string& start, const std::string& end) {
	for (const auto& n : trains) {
		if (n.get_time_departure() >= start && n.get_time_departure() <= (start + end)) {
			std::cout << n << std::endl;
		}
	}
}

void print_trains_to_destination(const std::vector<Train>& trains, const std::string& destination) {
	for (const auto& n : trains) {
		if (n.get_name_station() == destination) {
			std::cout << n << std::endl;
		}
	}
}

void print_express_trains_to_destination(const std::vector<Train>& trains, const std::string& destination) {
	for (const auto& n : trains) {
		if (n.get_name_station() == destination && n.get_type_train() == all_type_of_train::freight) {
			std::cout << n << std::endl;
		}
	}
}

void find_fastest_train_to_destination(const std::vector<Train>& trains, const std::string& destination) {
	const Train* fastest_train = nullptr;
	for (const auto& n : trains) {
		if (n.get_name_station() == destination) {
			if (fastest_train == nullptr || Train::compare_by_departure_time(n, *fastest_train)) {
				fastest_train = &n;
			}
		}
	}
	if (fastest_train) {
		std::cout << "Fastest train to " << destination << ": " << *fastest_train << std::endl;
	}
	else {
		std::cout << "No train found to " << destination << std::endl;
	}
}



int main()
{

	setlocale(LC_ALL, "RU");

	try {
		/*================================================================*/
		/*========================= Task 1 ===============================*/
		/*================================================================*/



		std::cout << "=====================================================\n";
		std::cout << "================== Task 1 ===========================\n";
		std::cout << "=====================================================\n";


		std::cout << "\nEnter elements in your vector: (To complete, enter 0) " << std::endl;
		std::vector<int> vector_of_integer;
		int terminal = 0;
		std::string numbers_into_vector;
		while (true) {
			std::cin >> numbers_into_vector;
			if (is_digit_string(numbers_into_vector)) {
				auto number = stoi(numbers_into_vector);
				auto check_on_terminal_value = (number != terminal);
				if (check_on_terminal_value || (!check_on_terminal_value && vector_of_integer.size() == 0)) {
					if (check_on_terminal_value) {
						vector_of_integer.push_back(number);
					}
				}
				else {
					break;
				}
			}
			else {
				throw std::logic_error("Not digit string");
			}
		}
		for (const auto& n : vector_of_integer) {
			std::cout << n << "\t";
		}
		std::cout << std::endl;

		

		std::cout << "\n1)" << "\n";
		auto sum = std::accumulate(vector_of_integer.begin(), vector_of_integer.end(), 0);
		std::cout << "Sum of elements of vector = " << sum << std::endl;



		std::cout << "\n2)" << "\n";
		auto size = vector_of_integer.size();
		std::cout << "The total number of numbers in the vector: " << size << std::endl;



		std::cout << "\n3)" << "\n";
		std::cout << "Enter chizlo, which there is in vector: ";
		auto chizlo = 0;
		std::cin >> chizlo;
		auto count = std::count(vector_of_integer.begin(), vector_of_integer.end(), chizlo);
		std::cout << "Your number is found in the array: " << count << std::endl;



		std::cout << "\n4)" << "\n";
		auto value = std::count_if(vector_of_integer.begin(), vector_of_integer.end(), [&chizlo](int x) {return x > chizlo; });
		std::cout << "The number of numbers is greater than yours: " << value << std::endl;



		std::cout << "\n5)" << "\n";
		int average = sum / size;
		std::replace(vector_of_integer.begin(), vector_of_integer.end(), chizlo, average); 
		std::cout << "Vector after replacing your chizlo with the arithmetic mean: " << std::endl;
		std::copy(vector_of_integer.begin(), vector_of_integer.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;



		std::cout << "\n6)" << "\n";
		std::cout << "Sum of all numbers in vector and sum of interval: " << "\n";
		int min_value_interval = 0; int max_value_interval = 0;
		std::cout << "Enter your interval: " << "\n";
		std::cout << "Lower bounds:\t";
		std::cin >> min_value_interval; 
		std::cout << "Upper bounds:\t";
		std::cin >> max_value_interval;
		auto it_left = std::find(vector_of_integer.begin(), vector_of_integer.end(), min_value_interval);
		auto it_right = std::find(vector_of_integer.begin(), vector_of_integer.end(), max_value_interval);
		if (it_left == vector_of_integer.end() || it_right == vector_of_integer.end())
		{
			throw std::invalid_argument("This number there is not in vector");
		}
		auto result_of_interval = std::accumulate(it_left, it_right + 1, 0);
		std::cout << "Res of interval sum: " << result_of_interval << "\n";
		std::cout << "Vector after this manipulation: " << "\n";
		for (auto& n : vector_of_integer) { n += result_of_interval; }
		std::copy(vector_of_integer.begin(), vector_of_integer.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;



		std::cout << "\n7)" << "\n";
		auto max_el = *(std::max_element(vector_of_integer.begin(), vector_of_integer.end()));
		auto min_el = *(std::min_element(vector_of_integer.begin(), vector_of_integer.end()));
		auto diff = max_el - min_el;
		std::cout << "Diff (max - min): " << diff << "\n";
		std::replace_if(vector_of_integer.begin(), vector_of_integer.end(), [](int x) {
			if (!((abs(x) & 1) == 1)) {
				return true;
			}
			else {
				return false;
			}
	    }, diff);
		std::copy(vector_of_integer.begin(), vector_of_integer.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;



		std::cout << "\n8)" << "\n";
		std::cout << "Remove all modulo-equal numbers from the sequence except the first one:" << "\n";
		std::sort(vector_of_integer.begin(), vector_of_integer.end());
		auto lst = std::unique(vector_of_integer.begin(), vector_of_integer.end());
		vector_of_integer.erase(lst, vector_of_integer.end());
		std::copy(vector_of_integer.begin(), vector_of_integer.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << "\n\n" << std::endl;
		system("pause");
		system("cls");



		/*================================================================*/
		/*========================= Task 2 ===============================*/
		/*================================================================*/



		std::cout << "=====================================================\n";
		std::cout << "================== Task 2 ===========================\n";
		std::cout << "=====================================================\n";

		std::vector<std::string> vector_of_string;


		std::cout << "\n1)" << "\n";
		read_words_in_file(vector_of_string, "src/data/Text.txt");
		std::cout << "Your vector of string:" << "\n";
		print_vector_of_string(vector_of_string);
		std::cout << "Vector after sorting: " << "\n";
		std::sort(vector_of_string.begin(), vector_of_string.end());
		print_vector_of_string(vector_of_string);


		std::cout << "\n2)" << "\n";
		std::cout << "Enter letter:\t";
		char letter;
		std::cin >> letter;
		checking_word_of_first_letter(letter, vector_of_string);



		std::cout << "\n3)" << "\n";
		std::cout << "Enter letter for delete all words, which start with this letter:\t";
		std::cin >> letter;
		delete_word_of_first_letter(letter, vector_of_string);
		std::cout << "Vector after this manipulation: " << std::endl;
		print_vector_of_string(vector_of_string);
		std::cout << "\n\n" << std::endl;
		system("pause");
		system("cls");



		/*================================================================*/
		/*========================= Task 3 ===============================*/
		/*================================================================*/



		std::cout << "=====================================================\n";
		std::cout << "================== Task 3 ===========================\n";
		std::cout << "=====================================================\n";

		std::vector<std::vector<int>> matrix;
		int rows = 0;
		int columns = 0;
		create_matrix(rows, columns);
		filling_matrix(matrix, rows, columns);
		print_matrix(matrix);


		std::cout << "\n1)" << "\n";
		std::cout << "Random matrix: " << std::endl;
		create_random_matrix(matrix, rows, columns);
		print_matrix(matrix);



		std::cout << "\n2)" << "\n";
		std::cout << "Arrange the rows of the matrix in ascending order of the sums of the row elements:\n";
		sort_matrix(matrix, rows, columns);
		print_matrix(matrix);



		std::cout << "\n3)" << "\n";
		std::cout << "Delete row and column of which is the maximum element of the matrix\n";
		remove_max_element_row_column(matrix);
		print_matrix(matrix);
		system("pause");
		system("cls");



		/*================================================================*/
		/*========================= Task 4 ===============================*/
		/*================================================================*/



		std::cout << "=====================================================\n";
		std::cout << "================== Task 4 ===========================\n";
		std::cout << "=====================================================\n";

		std::cout << "\n1) and 2) check file FIO.txt and Groups.txt " << "\n";
		std::vector<Student> vector_of_student = read_fio_student("src/data/Students.txt");
		std::sort(vector_of_student.begin(), vector_of_student.end(), [](const Student& a, const Student& b) {return a.surname < b.surname;});
		write_students_by_surname(vector_of_student, "src/data/Fio.txt");
		std::sort(vector_of_student.begin(), vector_of_student.end(), [](const Student& a, const Student& b) {
			if (a.course != b.course)
				return a.course < b.course;
			if (a.group != b.group)
				return a.group < b.group;
			return a.surname < b.surname;
			});
		write_sudents_by_course_and_group(vector_of_student, "src/data/Groups.txt");
		system("pause");
		system("cls");



		/*================================================================*/
		/*========================= Task 5 ===============================*/
		/*================================================================*/



		std::cout << "=====================================================\n";
		std::cout << "================== Task 5 ===========================\n";
		std::cout << "=====================================================\n";

		std::vector<Train> vector_of_trains;
		read_trains("src/data/Trains.txt", vector_of_trains);
		std::cout << "\nAll trains sorted by departure time:\n";
		sort_trains_by_departure_time(vector_of_trains);
		std::cout << std::endl;
		for (const auto& n: vector_of_trains) {
			std::cout << n << std::endl << std::endl;
		}

		std::cout << "Enter time interval:\n";
		std::string start_time;
		std::cout << "Since:\t";
		std::cin >> start_time;
		std::string end_time;
		std::cout << "For:\t";
		std::cin >> end_time;
		std::cout << "\nTrains in time range:" << std::endl;
		print_trains_in_time_range(vector_of_trains, start_time, end_time);

		std::string destination;
		std::cout << "\nEnter name of station:\t";
		std::cin >> destination;
		std::cout << "\nTrains to destination " << destination << ":" << std::endl;
		print_trains_to_destination(vector_of_trains, destination);

		std::cout << "\nExpress trains to destination " << destination << ":" << std::endl;
		print_express_trains_to_destination(vector_of_trains, destination);

		std::cout << "\nFastest train to destination " << destination << ":" << std::endl;
		find_fastest_train_to_destination(vector_of_trains, destination);

	}
	catch (const std::exception& re) {
		std::cerr << "Exception caught: " << re.what() << "\n";
	}
	return 0;
}
