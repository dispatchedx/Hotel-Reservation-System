#include "../pch.h"
#include "iostream"
#include "../include/Hotel.h"
std::vector<Room> rooms_List;
std::vector<Book> books_List;
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

Book* Hotel::get_book_by_code(int book_id) { // anaktisi kratisis apo kodiko
	for (int i = 0; i < books_List.size(); i++) {
		if (books_List.at(i)->getBookNumber() == book_id)
			return books_List.at(i);
	}
	return NULL;
}

bool Hotel::add_book_to_room(Book* book, int roomcode) { //prosthiki kratisis se domatio
	bool test = get_room_by_code(roomcode)->addBook(book); // TODO fix id is always 0 and last book is also the new book?
	if (test) {
		books_List.push_back(book);
		std::cout << "Reservation with id: " << book->getBookNumber() << " added to room with id: " << roomcode << std::endl;
		return true;
	}
	else {
		std::cout << "Booking was unsuccessful." << std::endl;
		return false;

	}
}

int Hotel::add_booking(Book* book) //prosthiki kratisis
{
	int value = 0;
	for (int i = 0; i < rooms_List.size()-1; i++){
		if (rooms_List.at(i)->addBook(book)){
			books_List.push_back(book);
			std::cout << "Booking was successful!The booking code is " << book->getBookNumber() << std::endl;
			return value = rooms_List.at(i)->getRoomNumber();
		}
	}


	std::cout << "Booking was not succesfull!" << std::endl;

	return value;
}

void Hotel::cancel_booking(int book_code) {//akurosi kratisis		*might not work*
	bool test;
	Book* reservation = get_book_by_code(book_code);
	Room room = reservation->getRoom(); //here we get acess violation when we get in, availability[i]->stuff are null
	test = room.cancelBook(book_code);
	if (test) {
		books_List.erase(books_List.begin() + book_code); // might need parenthesis instead
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

void Hotel::booking_plan() { //plano kratiseon
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

