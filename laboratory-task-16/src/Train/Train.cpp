#include "Train.h"


/*================================================================*/
/*===================== Private Method ===========================*/
/*================================================================*/

int Train::time_to_minutes(const std::string& time_str)
{
	int hours = stoi(time_str.substr());
	int minutes = stoi(time_str.substr());
	return hours * 60 + minutes;
}




/*================================================================*/
/*===================== Constructors =============================*/
/*================================================================*/

Train::Train() : number_train(1521), name_station("Vitebsk"), time_departure("6:33"), time_in_road(3) {
	type_train = all_type_of_train::passenger;
}
Train::Train(size_t init_number_train, std::string init_name_station, all_type_of_train init_type_train, std::string init_time_departure, size_t init_time_in_road) :
	number_train(init_number_train), 
	name_station(init_name_station),
	type_train(init_type_train),
	time_departure(init_time_departure),
	time_in_road(init_time_in_road)
{}
Train::Train(const Train& rhs) :
	number_train(rhs.number_train),
	name_station(rhs.name_station),
	type_train(rhs.type_train),
	time_departure(rhs.time_departure),
	time_in_road(rhs.time_in_road)
{}
Train::~Train() {}




/*================================================================*/
/*========================= Getters ==============================*/
/*================================================================*/

size_t Train::get_number_train() const {
	return this->number_train;
}

std::string Train::get_name_station() const
{
	return this->name_station;
}

all_type_of_train Train::get_type_train() const
{
	return this->type_train;
}

std::string Train::get_time_departure() const
{
	return this-> time_departure;
}

size_t Train::get_time_in_road() const
{
	return this->time_in_road;
}




/*================================================================*/
/*========================= Setters ==============================*/
/*================================================================*/

void Train::set_number_train(const size_t init_number_train) {
	this->number_train = init_number_train;
}

void Train::set_name_station(const std::string init_name_station) {
	this->name_station = init_name_station;
}

void Train::set_type_train(const all_type_of_train init_type_train) {
	this->type_train = init_type_train;
}

void Train::set_time_departure(const std::string init_time_departure) {
	this->time_departure = init_time_departure;
}

void Train::set_time_in_road(const size_t init_time_in_road) {
	this->time_in_road = init_time_in_road;
}




/*================================================================*/
/*=================== Assignment operator ========================*/
/*================================================================*/

Train& Train::operator=(const Train& rhs) {
	if (this != &rhs) {
		this->number_train = rhs.number_train;
		this->name_station = rhs.name_station;
		this->type_train = rhs.type_train;
		this->time_departure = rhs.time_departure;
		this->time_in_road = rhs.time_in_road;
	}
	return *this;
}




/*================================================================*/
/*=================== Ñomparison operator ========================*/
/*================================================================*/

bool Train::operator==(const Train& rhs) {
	return (this->number_train == rhs.number_train ? true : false);
}




/*================================================================*/
/*==================== Output operator ===========================*/
/*================================================================*/

std::ostream& operator<<(std::ostream& os, const Train& rhs)
{
	os << "Train number: " << rhs.number_train << ", Station: " << rhs.name_station
		<< ", Type: " << (rhs.type_train == all_type_of_train::passenger ? "Passenger" : "Express")
		<< ", Departure time: " << rhs.time_departure
		<< ", Travel time: " << rhs.time_in_road;
	return os;
}




/*================================================================*/
/*==================== Methods for conversion ====================*/
/*================================================================*/

Train Train::time_to_string(const std::string& line) {
	std::stringstream ss(line);
	size_t number = 0;
	size_t travel_time = 0;
	std::string destination, type_str, departure_time;
	ss >> number >> destination >> type_str >> departure_time >> travel_time ;

	all_type_of_train type = (type_str == "Ïàññàæèğñêèé") ? all_type_of_train::passenger : all_type_of_train::freight;

	return Train(number, destination, type, departure_time, travel_time);
}

bool Train::compare_by_departure_time(const Train& a, const Train& b)
{
	return time_to_minutes(a.get_time_departure()) < time_to_minutes(b.get_time_departure());
}




