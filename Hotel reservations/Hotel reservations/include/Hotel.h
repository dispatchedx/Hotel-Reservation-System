#ifndef HOTEL_H
#define HOTEL_H
#include "Room.h"
#include "vector"
class Hotel {
private:
	std::string hotelName;

public:
	Hotel(std::string hotName) {
		this->hotelName = hotName;
}
	std::vector<Room*> rooms_List;
	std::vector<Book*> reservations_List; //used to be private
	void add_Room(Room* newroom);

	Room* get_room_by_code(int room_id);

	Book* get_reservation_by_code(int reservation_id);

	bool add_reservation_to_room(Book* reservation, int roomcode);
	int add_reservation(Book* reservation);
	void cancel_reservation(int reservation_code);

	double calculate_income(int room_code);

	double calculate_income();

	void reservation_plan();


	
};
#endif // !HOTEL_H
