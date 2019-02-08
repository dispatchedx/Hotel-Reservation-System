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
	std::vector<Book*> books_List; //used to be private
	void add_Room(Room* newroom);

	Room* get_room_by_code(int room_id);

	Book* get_book_by_code(int book_id);

	bool add_book_to_room(Book* book, int roomcode);
	int add_booking(Book* book);
	void cancel_booking(int book_code);

	double calculate_income(int room_code);

	double calculate_income();

	void booking_plan();


	
};
#endif // !HOTEL_H
