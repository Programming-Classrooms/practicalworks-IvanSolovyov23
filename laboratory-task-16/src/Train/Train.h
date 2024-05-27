#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <sstream>

enum class all_type_of_train { passenger, freight };

class Train {
private:

	size_t number_train;
	std::string name_station;
	all_type_of_train type_train;
	std::string time_departure;
	size_t time_in_road;

	static int time_to_minutes(const std::string&);

public:
	// Constructors and destructor
	Train();
	Train(size_t, std::string, all_type_of_train, std::string, size_t);
	Train(const Train&);
	~Train();

	// Getters
	size_t get_number_train() const;
	std::string get_name_station() const;
	all_type_of_train get_type_train() const;
	std::string get_time_departure() const;
	size_t get_time_in_road() const;

	// Setters
	void set_number_train(const size_t);
	void set_name_station(const std::string);
	void set_type_train(const all_type_of_train);
	void set_time_departure(const std::string);
	void set_time_in_road(const size_t);

	// Operator =
	Train& operator=(const Train&);

	// Operator ==
	bool operator==(const Train&);

	// Operator <<
	friend std::ostream& operator<<(std::ostream&, const Train&);

	// Methods for conversion
	static Train time_to_string(const std::string&);
	static bool compare_by_departure_time(const Train&, const Train&);
	
};
#endif // TRAIN_H

