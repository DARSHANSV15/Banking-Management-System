# Banking-Management-System

## Overview

The Banking Management System project aims to create a robust software system for managing banking operations efficiently. This system is developed using C++ programming language with a focus on Object-Oriented Programming (OOP) principles to ensure modularity, extensibility, and ease of maintenance.

### Key Features Implemented:

- **Account Management**:
  - Creation, modification, deletion, and viewing of customer accounts.
- **Transaction Handling**:
  - Deposit, withdraw, and transfer funds between accounts.
- **Security**:
  - Basic authentication mechanism to ensure only authorized access to sensitive operations.
- **Data Persistence**:
  - File-based storage using text files for maintaining account information across sessions.

### Design and Architecture:

- **Object-Oriented Design**:
  - Utilized classes and objects to encapsulate account data and operations, promoting reusability and maintainability.
  - Applied inheritance for creating different types of accounts (e.g., Savings Account, Current Account) with shared functionalities in base classes.
  - Implemented polymorphism to handle operations like deposit and withdraw differently based on account types.
- **File Handling**:
  - Developed file handling routines to read and write account data to persistent storage, ensuring data integrity and availability.

### Technical Stack:

- **Language**: C++
- **Tools**: Visual Studio Code, g++ compiler
- **Version Control**: Git, GitHub

### Usage Instructions:

1. **Clone Repository**:
   ```
   git clone https://github.com/DARSHANSV15/Banking-Management-System.git
   cd Banking-Management-System
   ```
2. **Compile and Run**:
   - Compile the source code using a C++ compiler:
     ```
     g++ bank.cpp -o bank
     ```
   - Run the executable to launch the Banking Management System:
     ```
     ./bank
     ```
3. **Follow On-Screen Instructions**:
   - Use the console interface to navigate through various banking operations as per the implemented functionalities.
4. **Use following credentials during user authentication**:
   - E-mail: abcd@zmail.com
   - PIN: 1234
   - Password: abcd@123

### Future Enhancements:

- Implement more sophisticated authentication mechanisms (e.g., multi-factor authentication).
- Integrate a graphical user interface (GUI) for a more user-friendly experience.
- Enhance error handling and input validation to improve system robustness.
- Add support for additional banking operations such as loan management, transaction histories, etc.

## Contributors:

- **Darshan S V**
