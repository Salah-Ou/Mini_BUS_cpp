#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <thread>
#include <chrono>
#include <time.h>

using namespace std;

class BUS {
    private : 
        struct Books {
            string name ;
            int seat_no ;
            string source ;
            string destination ;
            float price ;
        };
        vector <Books> Book ;
    public : 

        void book_seat(){
            cout << "\n\t\t   " ;
            set_reminder();
            Books new_book ;
            cout << "\t\tEnter Name : " ;
            cin >> new_book.name ;
            cout << "\t\tEnter Seat No : " ;
            cin >> new_book.seat_no ;   
            cout << "\t\tEnter Source : " ;
            cin.ignore();
            getline(cin, new_book.source);
            cout << "\t\tEnter Destination : " ;
            getline(cin, new_book.destination); 
            cout << "\t\tEnter Price : " ;
            cin >> new_book.price ;
            Book.push_back(new_book) ;
            cout << "\n\t\tSeat booked successfully\n" ;
            cout << "\n\t    " ;
            system("pause");
        }

        void view_reservs(){
            cout << "\n\t\t   " ;
            set_reminder();
            if (Book.empty()){
                cout << "\n\t\t\033[1;31mNo reservations available\n\033[1;32m" ;
            }
            else{
                cout << "\n\t\t\t\t     All Reservations : \n\n" ;
                cout << "\t\tSeat No.      Name         Source     Destination    Price  " ;
                cout << "\n\t\t-------------------------------------------------------------\n" ;
                for(const auto& book : Book){
                    cout << "\t        " << book.seat_no << "\t      " << book.name 
                    << "\t   " << book.source << "\t" << book.destination 
                    << "\t      " << book.price << " DH" ;
                    cout << "\n\t\t-------------------------------------------------------------\n" ;
                }
            }
            cout << "\n\t\t\t" ;
            system("pause");
        }

        void edit_a_reserv(){
            set_reminder();
            if(Book.empty()){
                cout << "\n\t\t\033[1;31mNo reservations available\n\033[1;32m" ;
            }
            else{
                int seat_no ;
                cout << "\t\tEnter seat number to edit : " ;
                cin >> seat_no ;
                for(auto& book : Book){
                    if(book.seat_no == seat_no){
                        cout << "\t\tEnter Name : " ;
                        cin >> book.name ;
                        cout << "\t\tEnter Source : " ;
                        cin.ignore();
                        getline(cin,book.source) ;
                        cout << "\t\tEnter Destination : " ;
                        cin.ignore();
                        getline(cin,book.destination);
                        cout << "\t\tEnter Price : " ;
                        cin >> book.price ;
                        if (book.price == 3.50 || book.price == 4.00){
                            cout << "\n\t\tReservation edited successfully\n" ;
                        }
                        else{
                            cout << "\n\t\tP\033[1;31mrice is not valid\n\033[1;32m" ;
                        }
                    }
                }
                cout << "\n\t\t" ;
                system("pause");
            }
        }

        void print_a_ticket(){
            set_reminder();
            if (Book.empty()){
                cout << "\n\t\tNo reservations available\n" ;
            }
            else{
                int seat_no ;
                cout << "\t\tEnter seat number to print ticket : " ;
                cin >> seat_no ;
                for(const auto& book : Book){
                    if(book.seat_no == seat_no){
                        cout << "\n\t\t\t   \033[1;33m BUS Receipt \033[1;32m\n" ;
                        cout << "\t --------------------------------------------------\n" ;
                        cout << "\n\t\tTicket for seat No.   : " << book.seat_no ;
                        cout << "\n\t\tPassenger Name        : " << book.name ;
                        cout << "\n\t\tPassenger Source      : " << book.source ;
                        cout << "\n\t\tPassenger Destination : " << book.destination ;
                        cout << "\n\t\tPassenger Price       : " << book.price << " DH\n\n" ;
                        cout << "\t --------------------------------------------------\n" ;
                        cout << "\t\t Thank you for traveling with us.\n" ;
                    }
                }
            }
            cout << "\n\t\t" ;
            system("pause");
        }

        set_reminder(){
            system("cls");
            cout << "\n\t\t   " ;
            time_t now = time(0);
            tm endOftime = *localtime(&now);
            endOftime.tm_min = endOftime.tm_min ;
            endOftime.tm_sec = endOftime.tm_sec ;
            mktime(&endOftime);
            cout << asctime(&endOftime) << endl ;
        }

};

int main(){ 
    system("cls");
    system("color A");
    int choice ;
    BUS b ;
    while(true){
        system("cls");
        b.set_reminder();
        cout << "\n\t    Welcome To Mini Bus Booking System : \n" ;
        cout << "\n\n\t-----------------------------------------------" ;
        cout << "\n\t\t1. Book a Seat.\n" ;
        cout << "\t\t2. View Reservations.\n" ;
        cout << "\t\t3. Edit a Reservations.\n" ;
        cout << "\t\t4. Print a Ticket.\n" ;
        cout << "\t\t5. Exit.\n" ;
        cout << "\t-----------------------------------------------\n" ;
        cout << "\t\tEnter your choice : " ;
        cin >> choice ;
        switch(choice){
            case 1 : b.book_seat(); break ;
            case 2 : b.view_reservs(); break ;
            case 3 : b.edit_a_reserv(); break ;
            case 4 : b.print_a_ticket(); break ;
            case 5 : cout << "\n\t\t\tExiting Program...\n\n" ; exit(0); break ;
            default : cout << "Invalid Choice!!!" ; break ;
        }
    }
}