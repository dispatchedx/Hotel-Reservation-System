#include "../pch.h"
#include "iostream"
#include "../include/Hotel.h"
std::vector<Room> rooms_List;
std::vector<Book> reservations_List;
void Hotel::add_Room(Room* newroom) { //always adds room, and not roomtype
	rooms_List.push_back(newroom);
}

Room* Hotel::get_room_by_code(int code)// anaktisi domatiou apo kodiko
{
	for (int i = 0; i <= (int)rooms_List.size() - 1; i++)
		if (code == rooms_List.at(i)->getRoomNumber()){
			return rooms_List.at(i);
		}
	return 0;

}

Book* Hotel::get_reservation_by_code(int reservation_id) { // anaktisi kratisis apo kodiko
	for (int i = 0; i < reservations_List.size(); i++) {
		if (reservations_List.at(i)->getBookNumber() == reservation_id)
			return reservations_List.at(i);
	}
	return NULL;
}

bool Hotel::add_reservation_to_room(Book* reservation, int roomcode) { //prosthiki kratisis se domatio
	bool test = get_room_by_code(roomcode)->addBook(reservation); // TODO check id with deletion
	if (test) {
		reservations_List.push_back(reservation);
		std::cout << "Reservation with id: " << reservation->getBookNumber() << " added to room with id: " << roomcode << std::endl;
		return true;
	}
	else {
		std::cout << "Booking was unsuccessful." << std::endl;
		return false;

	}
}

int Hotel::add_reservation(Book* reservation) //prosthiki kratisis
{
	int value = 0;
	for (int i = 0; i < rooms_List.size()-1; i++){
		if (rooms_List.at(i)->addBook(reservation)){
			reservations_List.push_back(reservation);
			std::cout << "Booking was successful!The reservation code is " << reservation->getBookNumber() << std::endl;
			return value = rooms_List.at(i)->getRoomNumber();
		}
	}


	std::cout << "Booking was not succesfull!" << std::endl;

	return value;
}

void Hotel::cancel_reservation(int reservation_code) {//akurosi kratisis		*might not work*
//	bool test;
	Book* reservation = get_reservation_by_code(reservation_code);
	Room* room = reservation->getRoom();
	int test = room->cancelBook(reservation_code); //TODO room still has income and numbers dont match up with id or something
	if (test) {
		for (int i = 0; i < reservations_List.size(); i++) {
			if (reservations_List[i]->getBookNumber() == reservation_code) {
				reservations_List.erase(reservations_List.begin()+i); // might need catch error for 
			}
		}
		std::cout << "Booking cancellation was successful." << std::endl;
	}
	else
		std::cout << "Booking cancellation was unsuccessful." << std::endl;
}

double Hotel::calculate_income(int room_code) { //upologismos esodon;esoda domatiou apo kodiko
	return rooms_List.at(room_code)->pricing();
}

double Hotel::calculate_income() {	// upologismos esodon;sunolika esoda
	double final_income = 0;
	for (int i = 0; i < rooms_List.size(); i++) {
		final_income += rooms_List.at(i)->pricing();
	}
	return final_income;
}

void Hotel::reservation_plan() { //plano kratiseon
	std::cout << " Room    01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30" << std::endl;
	for (int i = 0; i<rooms_List.size(); i++) {
		std::cout << "  " << rooms_List.at(i)->getRoomNumber() << "_ \t ";
		for (int j = 0; j<30; j++) {
			if (rooms_List.at(i)->availability[j] == NULL)
				std::cout << "_  ";
			else
				std::cout << "*  ";
		}
		std::cout << "\n\n";
	}
	std::cout << "" << std::endl;
}

