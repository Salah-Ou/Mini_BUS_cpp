#include <iostream>     // For input/output operations (cin, cout, etc.)
#include <vector>       // For using vector container (dynamic array)
#include <string>       // For using string data type
#include <ctime>        // For time/date functions
#include <iomanip>      // For formatting output (setprecision, fixed)
#include <fstream>      // For file operations (reading/writing files)

#ifdef _WIN32
    // Windows-specific includes :
    #include <windows.h>  // Windows API - provides console handling functions Used for: COORD structure, SetConsoleCursorPosition()
                        // Allows precise cursor positioning in Windows console
    #include <thread>       // For multithreading support (though not heavily used)
    #include <chrono>       // For time operations (milliseconds, etc.)
    #include <time.h>       // Alternative time header (ctime is usually enough)
#else
    // Linux/Unix/Mac includes :
    #include <unistd.h>     // POSIX API - provides usleep(), system calls Used for: sleep functions, file operations
    #include <cstdlib>      // C standard library - provides system(), exit() Used for: system("clear"), exit() function
#endif

using namespace std;

// Cursor Positioning :
void gotoxy(int x, int y) {
    #ifdef _WIN32
        COORD c;
        c.X = x;
        c.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    #else
        cout << "\033[" << y << ";" << x << "H";
    #endif
}

class BUS {
    private:

        void clear_screen() {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
        }

        void pause_screen() {
            #ifdef _WIN32
                system("pause");
            #else
                cout << "\033[1;30mPress Enter to continue...";
                cin.ignore();
                cin.get();
            #endif
        }

        float calculate_price(float kilom) {
            float price = 3.50f;
            if (kilom <= 10) {
                price *= 1.00f;
            } else if (kilom <= 15) {
                price += 0.50f;
            } else if (kilom <= 25) {
                price += 2.50f;
            } else if (kilom <= 40) {
                price += 6.50f;
            } else if (kilom <= 60) {
                price += 12.00f;
            } else {
                price += 16.50f;
            }
            return price;
        }

    public:
        struct Tickets {
            string name;
            int ID;
            string source;
            string destination;
            float price ;
            float kilom;
        };
        vector<Tickets> Ticket;

        void set_reminder() {
            clear_screen();
            gotoxy(88, 3);
            time_t now = time(0);
            tm* endOftime = localtime(&now);
            cout << "\033[1;4;31m" << asctime(endOftime) << "\033[0m" << endl;
        }

        void Set_Ticket() {
            set_reminder();
            Tickets new_ticket;
            int id ;
            string filename = "reservations.txt";
            ifstream file(filename);
            gotoxy(36, 5);
            cout << "------------------------ Set Ticket ------------------------";
            gotoxy(40, 7);
            cout << "* Enter ID : ";
            cin >> new_ticket.ID;
            if (file.is_open()){
                // Read existing reservations from file
                string line;
                while (getline(file, line)){
                    if (line.find("Ticket ID") != string::npos) {
                        id = stoi(line.substr(line.find(":") + 1));
                        if (id == new_ticket.ID) {
                            gotoxy(55, 13);
                            cout << "\033[1;31mThis ID already exists.\033[0m";
                            gotoxy(53, 15);
                            pause_screen();
                            file.close();
                            return;
                        }
                    }
                }
            }
            gotoxy(40, 9);
            cout << "* Enter Name : ";
            cin >> new_ticket.name;
            gotoxy(40, 11);
            cout << "* Enter Source : ";
            cin.ignore();
            getline(cin, new_ticket.source);
            gotoxy(40, 13);
            cout << "* Enter Destination : ";
            getline(cin, new_ticket.destination);
            gotoxy(40, 15);
            cout << "* Enter the distance in kilometers between ";
            gotoxy(40,16);
            cout << "your source point and destination : ";
            cin >> new_ticket.kilom ;
            new_ticket.price = calculate_price(new_ticket.kilom);
            gotoxy(54, 18);
            cout << "\033[1;33m Ticket Price: " << fixed << setprecision(2) << new_ticket.price << " DH\033[0m";
            Ticket.push_back(new_ticket);
            gotoxy(36, 20);
            cout << "------------------------------------------------------------";
            gotoxy(49, 22);
            cout << "\033[1;32mThe ticket was successfully received.\033[1;0m";
            gotoxy(54, 24);
            pause_screen();
        }

        void view_reservs() {
            cout << "";
            set_reminder();
            if (Ticket.empty()) {
                cout << "\n\n\t\t\t\t\t\033[1;31mNo reservations available\033[0m";
            } else {
                cout << "\n\n\t\t\t\t\t  All Reservations : ";
                cout << "\n\t-----------------------------------------------------------------------------------------";
                for (const auto& ticket : Ticket) {
                    cout << "\n\t   ID: " << ticket.ID << " | Name: " << ticket.name << " | Source: " << ticket.source 
                        << " | Destination: " << ticket.destination << " | Price: " << fixed << setprecision(2) <<  ticket.price << " DH" ;
                    cout << "\n\t-----------------------------------------------------------------------------------------";
                }
            }
            cout << "\n\n\t\t\t\t\t" ;
            pause_screen();
        }

        void edit_a_reserv() {
            set_reminder();
            int choice ;
            int found = false ;
            if (Ticket.empty()) {
                gotoxy(50,20);
                cout << "\033[1;31mNo reservations available\033[0m";
            } else {
                int ID;
                gotoxy(40,5);
                cout << "Enter TIcket ID to edit : ";
                cin >> ID;
                clear_screen();
                set_reminder();
                for (auto& ticket : Ticket) {
                    if (ticket.ID == ID) {
                        found = true ;
                        gotoxy(50,7);
                        cout << "what do you want to edit : " ;
                        gotoxy(40,9);
                        cout << "-----------------------------------------------";
                        gotoxy(44,11);
                        cout << "1. Name" ;
                        gotoxy(44,13);
                        cout << "2. Source - Destination" ;
                        gotoxy(40,15);
                        cout << "-----------------------------------------------";
                        gotoxy(52,17);
                        cout << "Your choice : " ;
                        cin >> choice ;
                        switch(choice){
                            case 1 :  gotoxy(48,19);
                                cout << "* Enter your new Name : ";
                                cin >> ticket.name;
                                gotoxy(44,21);
                                cout << "\033[1;32mThe ticket has been successfully modified.\033[1;0m";
                                break ;
                            case 2 : gotoxy(40,19);
                                cout << "* Enter Source : ";
                                cin.ignore();
                                getline(cin, ticket.source);
                                gotoxy(40, 21);
                                cout << "* Enter Destination : ";
                                getline(cin, ticket.destination);
                                gotoxy(40, 23);
                                cout << "* Enter the distance in kilometers between ";
                                gotoxy(40,24);
                                cout << "your source point and destination : ";
                                cin >> ticket.kilom ;
                                ticket.price = calculate_price(ticket.kilom);
                                gotoxy(51, 26);
                                cout << "\033[1;33m Ticket Price: " << fixed << setprecision(2) << ticket.price << " DH\033[0m";
                                gotoxy(45,28);
                                cout << "\033[1;32mThe ticket has been successfully modified..\033[1;0m";
                                break ;
                            default : gotoxy(55,25);
                                cout << "\033[1;31mInvalid Choice!!!"; 
                                break;
                        }
                    }
                }
                if (!found) {
                    gotoxy(48,22);
                    cout << "\033[1;31mNo ticket found with that ID.\033[0m";
                }
            }
            gotoxy(50,30);
            pause_screen();
        }

        void save_to_file() {
            set_reminder();
            if (Ticket.empty()) {
                gotoxy(45, 18);
                cout << "\033[1;31mNo reservations to save.\033[0m";
                gotoxy(47, 23);
                pause_screen();
                return;
            }

            string filename = "reservations.txt";
            ofstream file("reservations.txt");
            
            
            if (!file.is_open()) {
                gotoxy(40, 10);
                cout << "\033[1;31mError: Could not open file for writing.\033[0m";
                gotoxy(47, 13);
                pause_screen();
                return;
            }

            time_t now = time(0);
            tm* t = localtime(&now);

            file << "============================================================\n";
            file << "           MINI BUS BOOKING SYSTEM - RESERVATIONS\n";
            file << "============================================================\n";
            file << "  Saved on : " << asctime(t);
            file << "  Total Tickets : " << Ticket.size() << "\n";
            file << "============================================================\n\n";

            for (const auto& ticket : Ticket) {
                file << "------------------------------------------------------------\n";
                file << "  Ticket ID     : " << ticket.ID << "\n";
                file << "  Passenger     : " << ticket.name << "\n";
                file << "  Source        : " << ticket.source << "\n";
                file << "  Destination   : " << ticket.destination << "\n";
                file << "  Distance      : " << fixed << setprecision(2) << ticket.kilom << " km\n";
                file << "  Price         : " << fixed << setprecision(2) << ticket.price << " DH\n";
                file << "------------------------------------------------------------\n\n";
            }

            file << "============================================================\n";
            file << "               Thank you for traveling with us.\n";
            file << "============================================================\n";

            file.close();

            gotoxy(28, 10);
            cout << "------------------------------------------------------------";
            gotoxy(38, 12);
            cout << "\033[1;32mAll reservations saved successfully to:\033[0m";
            gotoxy(48, 14);
            cout << "\033[1;33m\"" << filename << "\"\033[0m";
            gotoxy(28, 16);
            cout << "------------------------------------------------------------";
            gotoxy(45, 18);
            pause_screen();
        }

        void print_a_ticket() {
            set_reminder();
            if (Ticket.empty()) {
                gotoxy(45,18);
                cout << "\033[1;31mNo reservations available\033[1;0m";
            } else {
                int ID;
                gotoxy(45,5);
                cout << "\t\tEnter seat number to print ticket : ";
                cin >> ID;
                clear_screen();
                set_reminder();
                for (const auto& ticket : Ticket) {
                    if (ticket.ID == ID) {
                        gotoxy(53,5);
                        cout << "\033[1;33m BUS Receipt \033[0m";
                        gotoxy(35,7);
                        cout << "--------------------------------------------------";
                        gotoxy(39,9);
                        cout << "\033[1;34mTicket for seat No.   : \033[1;30m" << ticket.ID;
                        gotoxy(39,11);
                        cout << "\033[1;34mPassenger Name        : \033[1;30m" << ticket.name;
                        gotoxy(39,13);
                        cout << "\033[1;34mPassenger Source      : \033[1;30m" << ticket.source;
                        gotoxy(39,15);
                        cout << "\033[1;34mPassenger Destination : \033[1;30m" << ticket.destination;
                        gotoxy(39,17);
                        cout << "\033[1;34mPassenger Price       : \033[1;30m" << fixed << setprecision(2) << ticket.price << " DH\033[1;0m";
                        gotoxy(35,19);
                        cout << "--------------------------------------------------";
                        gotoxy(44,21);
                        cout << "\033[1;32mThank you for traveling with us.";
                    }
                }
            }
            gotoxy(47,23);
            pause_screen();
        }

};

int main() {
    int choice;
    BUS b;
    string filename = "reservations.txt";
    ifstream file(filename);
    // Load existing reservations from file on startup
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find("Ticket ID") != string::npos) {
                BUS::Tickets ticket;
                ticket.ID = stoi(line.substr(line.find(":") + 1));
                getline(file, line);
                ticket.name = line.substr(line.find(":") + 1);
                getline(file, line);
                ticket.source = line.substr(line.find(":") + 1);
                getline(file, line);
                ticket.destination = line.substr(line.find(":") + 1);
                getline(file, line);
                ticket.kilom = stof(line.substr(line.find(":") + 1));
                getline(file, line);
                ticket.price = stof(line.substr(line.find(":") + 1));
                b.Ticket.push_back(ticket);
            }
        }
        file.close();
    }
    while (true) {
        b.set_reminder();
        gotoxy(42, 5);
        cout << "Welcome To Mini Bus Booking System :";
        gotoxy(35, 7);
        cout << "-----------------------------------------------";
        gotoxy(45, 9);
        cout << "1. Set a Ticket.";
        gotoxy(45, 11);
        cout << "2. View Reservations.";
        gotoxy(45, 13);
        cout << "3. Edit a Reservation.";
        gotoxy(45, 15);
        cout << "4. Print a Ticket.";
        gotoxy(45, 17);
        cout << "5. Save to File.";
        gotoxy(45, 19);
        cout << "6. Exit.";
        gotoxy(35, 21);
        cout << "-----------------------------------------------";
        gotoxy(45, 23);
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice) {
            case 1: b.Set_Ticket(); break;
            case 2: b.view_reservs(); break;
            case 3: b.edit_a_reserv(); break;
            case 4: b.print_a_ticket(); break;
            case 5: b.save_to_file(); break;
            case 6:
                gotoxy(52, 25);
                cout << "\033[1;30mExit Program...\n\n";
                exit(0);
                break;
            default:
                gotoxy(50, 25);
                cout << "\033[1;31mInvalid Choice!!!";
                break;
        }
    }
}