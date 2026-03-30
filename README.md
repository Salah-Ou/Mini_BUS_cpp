# **🚌 Mini Bus Booking System**

- A **console-based C++** application for managing bus ticket reservations with cross-platform support for **Windows, Linux, and macOS.**

## **📋 Table of Contents**

- ####  Features
- ####  System Requirements
- ####  Installation
- ####  How to Use
- ####  File Structure
- ####  Price Calculation
- ####  Code Structure
- ####  Cross-Platform Compatibility
- ####  Troubleshooting
- ####  Future Improvements

## **✨ Features**

- #### **`Create Tickets` :** Add new bus reservations with passenger details.
- #### **`View Reservations` :** Display all existing tickets in a formatted list.
- #### **`Edit Tickets` :** Modify passenger names, routes, or distances.
- #### **`Print Tickets` :** Generate individual ticket receipts.
- #### **`Save to File` :**  Export all reservations to a text file.
- #### **`Persistent Storage` :** Automatically loads existing reservations on startup.
- #### **`Real-time Clock` :** Displays current date and time.
- #### **`Colorful Console Output` :** Enhanced UI with colored text (cross-platform).
- #### **`ID Validation` :** Prevents duplicate ticket IDs.

## **💻 System Requirements**


> ### Minimum Requirements :

- **OS :** Windows 7+, Linux, or macOS.
- **Compiler :** C++11 or later (GCC, Clang, MSVC).
- **RAM :** 128MB minimum.
- **Disk Space :** 10MB for executable and data file.

> ### Recommended :

- **OS :** Windows 10/11, Ubuntu 20.04+, macOS 11+.
- **Compiler :** GCC 9+, Clang 10+, MSVC 2019+.
- **Terminal :** Supports ANSI escape codes (Linux/Mac) or Windows Console (Windows).

## **🔧 Installation**

### Windows (MSVC/Visual Studio) :
> ### bash
```
# Compile with MSVC
cl /EHsc bus_system.cpp

# Or with MinGW
g++ -o bus_system.exe bus_system.cpp
```

### Linux/macOS (GCC/Clang) :
> ### bash
```
# Compile
g++ -o bus_system bus_system.cpp -std=c++11

# Run
./bus_system
```

## **🎮 How to Use** 


> ### Main Menu Options :
##### **1. Set a Ticket**   - Create a new reservation
##### **2. View Reservations**   - Display all tickets
##### **3. Edit a Reservation**  - Modify existing ticket
##### **4. Print a Ticket**   - Show individual receipt
##### **5. Save to File**   - Export data to reservations.txt
##### **6. Exit**    - Close the progra#m

> ### Creating a Ticket :
- #### Select option 1 from main menu.
- #### Enter unique ID number.
- #### Input passenger name.
- #### Specify source location.
- #### Specify destination location.
- #### Enter distance in kilometers.
- #### System automatically calculates price.
- #### Ticket is saved to memory.


> ### Editing a Ticket
- #### Select option 3 from main menu.
- #### Enter the ticket ID to edit.

> ### Choose what to edit :
- #### 1: Change passenger name.
- #### 2: Change route (source/destination/distance) :
- Enter new information.
- Price automatically recalculates if distance changes.

> ### Printing a Ticket :
- #### Select option 4 from main menu.
- #### Enter the seat number (ticket ID).
- #### System displays formatted receipt.

> ### Saving Data :
- ### Select option 5 to save all tickets to file.
- ### Data is saved to reservations.txt in the same directory.
- ### File includes timestamp and total ticket count.

## **💰 Price Calculation**

> ### The system calculates ticket prices based on distance :

>  ----------------------------
> | Distance (km) | Price (DH) |
> |---------------|------------|
> | ≤ 10          |       3.50 |
> | 11 - 15       |       4.00 |
> | 16 - 25       |       6.00 |
> | 26 - 40       |      10.00 |
> | 41 - 60       |      15.50 |
> | > 60          |      20.00 |

> ### Formula Logic :

- Base price: 3.50 DH for first 10 km.
- Incremental increases based on distance brackets.
- Prices are automatically recalculated when distance is edited.

## **🔄 Cross-Platform Compatibility** 

> ### The system automatically detects the operating system and uses appropriate functions :

> ----------------------------------------------------------------------------
> | Operation    | Windows                     | Linux/MacOS                 |  
> | :----------: | :-------------------------: | :-------------------------: |
> | Clear Screen | `system("cls")`             | `system("clear")`           |
> | Pause        | `system("pause")`           | `cin.ignore();` `cin.get();`|
> | Cursor       | Position Windows API (COORD | ANSI escape codes           |
> | Colors       | ANSI codes (Windows 10+)    | ANSI escape codes           |

> ### ANSI Color Codes Used:

- `\033[1;31m-` - Red (errors, warnings)
- `\033[1;32m-` - Green (success messages)
- `\033[1;33m-` - Yellow (prices, highlights)
- `\033[1;34m-` - Blue (labels)
- `\033[1;30m-` - Dark gray (normal text)
- `\033[0m`- Reset to default

## **🐛 Troubleshooting**

> ### Common Issues and Solutions:

**Issue :** "`This ID already exists`" when creating ticket

- **Solution :** Use a unique ID number for each ticket

**Issue :** Screen not clearing properly on Windows

- **Solution :** Ensure you're using Windows 10 or later, or update console settings

**Issue :** Colors not showing on Linux/Mac

- **Solution :** Make sure your terminal supports ANSI escape codes (most modern terminals do)

**Issue :** Cannot open file for writing

- **Solution :** Check write permissions in the current directory

**Issue :** Data not loading on startup

- **Solution :** Ensure reservations.txt exists in the same directory as the executable

> ### Compilation Errors:

- **Error :** `stoi` is not a member of 'std'.

- **Solution :** Add `#include <string>` and compile with C++11 or later : `-std=c++11` Error: SetConsoleCursorPosition undeclared.

- **Solution :** Add #include `<windows.h>` (should already be included for Windows).

## **👥 Authors**

> ### Developed as a C++ learning project demonstrating:

- Object-Oriented Programming.
- File I/O operations.
- Cross-platform development.
- Console UI manipulation.
- Data structure management.

## **🙏 Acknowledgments**

- Uses standard C++ libraries for maximum compatibility.
- Cross-platform console handling techniques.
- ANSI color codes for enhanced terminal output.

> #### 📌 **Note :** This system stores data in memory only until saved to file. Always use the "Save to File" option before exiting to preserve your data.



