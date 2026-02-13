🏦 Advanced Bank Management System (C++ OOP)

🌟 Overview
This is a comprehensive, console-based Banking System built with C++ using Object-Oriented Programming (OOP). It focuses on clean architecture, secure data handling via flat-files, and a professional user-permission system.

The project is designed with Separation of Concerns in mind, keeping the Business Logic independent of the Presentation Layer (UI).

🛠️ Core Features
1. 👥 Client Management
Complete CRUD: Create, Read, Update, and Delete client profiles.

Smart Search: Instant lookup by account number.

File Persistence: All data is saved and managed through structured text files.

2. 💰 Financial Transactions (Advanced Logic)
Deposit & Withdraw: Real-time balance validation and updates.

💸 Secure Money Transfer: A robust logic to transfer funds between accounts with automated balance checks for both parties.

Total Balances: High-level summary reports for all bank assets.

3. 🔐 Security & User Management
Multi-User Login: Secure authentication system.

Granular Permissions: Bitwise-based permission system allows administrators to define exactly what each user can or cannot access (e.g., restricted access to Delete or Transfer screens).

4. 📜 Professional Audit Logs (Login Register)
Login History Tracking: Automatically records every login attempt.

Detailed Logs: Captures Username, Timestamp, Password used, and Permissions at the moment of entry.

Self-Healing Data: The system is designed to automatically create or append to log files, ensuring no runtime crashes if files are missing.

🏗️ Technical Architecture
Encapsulation & Inheritance: Clear hierarchy starting from a base clsPerson class.

Decoupled Screens: Every screen is a separate class, preventing Circular Dependencies and making the code highly maintainable.

Memory Management: Efficient use of STL Vectors and File Streams (fstream) for data processing.

Input Validation: A dedicated utility class to handle and sanitize user inputs, preventing system errors.

🚀 How to Run
Clone the repository.

Ensure you have the Course11 folder structure intact.

Compile the Main.cpp using any C++ compiler (C++11 or higher recommended).

Run the executable and use the admin credentials found in Users.txt.

👨‍💻 My Philosophy
I believe that "Clean code is code that looks like it was written by someone who cares." This project isn't just about functionality; it's about writing readable, scalable, and professional code that follows industry best practices.
