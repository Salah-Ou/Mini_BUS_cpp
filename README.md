# Mini Bus Booking System - README

## Overview
This is a simple console-based Mini Bus Booking System written in C++. The program allows users to book bus seats, view reservations, edit existing reservations, and print tickets.

## Features
- **Book a Seat**: Reserve a bus seat by providing passenger details (name, seat number, source, destination, and price)
- **View Reservations**: Display all current reservations in a formatted table
- **Edit Reservations**: Modify existing reservation details
- **Print Ticket**: Generate a printable ticket for a specific reservation
- **Time Display**: Shows current time in the header of each screen
- **Color Interface**: Uses green text for better visibility

## How to Use
1. Compile the program using a C++ compiler (tested with g++)
2. Run the executable
3. Use the menu to navigate through options:
   - Press 1 to book a seat
   - Press 2 to view all reservations
   - Press 3 to edit a reservation
   - Press 4 to print a ticket
   - Press 5 to exit the program

## Data Structure
The program uses a `vector` to store reservation data. Each reservation contains:
- Passenger name
- Seat number
- Source location
- Destination
- Price (in DH - Dirhams)

## Requirements
- Windows OS (uses Windows.h for system commands)
- C++11 or later compiler

## Limitations
- Data is not persisted between program runs (all reservations are lost when program exits)
- No input validation for seat number conflicts
- Basic error handling

## Screenshots
The program features a clean console interface with:
- Green colored text
- Time display header
- Formatted output for reservations and tickets

## Future Improvements
- Add data persistence (file storage)
- Implement more robust input validation
- Add seat availability checking
- Expand reservation details (date/time of travel, etc.)