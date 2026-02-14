🏦 Secure Banking System (C++ OOP)

📌 Technical Overview
This is a sophisticated Banking Management System built with C++11, demonstrating advanced Object-Oriented Programming patterns. The project is architected with a strict separation between the Presentation Layer (Screens) and the Business Logic Layer, ensuring maintainability and scalability.

Unlike simple console apps, this system implements File-Based Database Management with custom Encryption Algorithms to ensure data security at rest.

⚙️ Core System Architecture
1. 🛡️ Security & Encryption Engine
Custom Encryption Logic: Implemented strictly in clsUtil, the system uses a Symmetric Encryption Algorithm (Key-based shifting) to scramble data.

Data at Rest Protection: All sensitive files (Clients.txt, Users.txt) are encrypted. If a file is opened externally, the content is unreadable (Ciphertext).

Seamless Decryption: The system automatically decrypts data into objects upon loading, providing a seamless user experience while maintaining high security.

2. 💸 Advanced Financial Operations
Atomic Transfer System: The Transfer operation is designed as an atomic transaction. It validates the sender's balance, withdraws from the source, deposits to the destination, and updates both records in the file system simultaneously.

Transaction Auditing: A dedicated TransferLog system tracks every financial movement.

Accountability Protocol: The code captures the Current Active User (Admin) from the session context and logs their username alongside the transaction, ensuring full traceability of who authorized the transfer.

3. 🏗️ Professional OOP Structure
Abstract Base Classes: Uses clsPerson as a blueprint for clsClient and clsUser.

Static Methods: Extensive use of static methods for utility functions and finding objects, reducing memory overhead.

Composition: The screens utilize clsInputValidate for robust data handling, preventing runtime errors due to invalid inputs.

🚀 Key Features List
CRUD Operations: (Create, Read, Update, Delete) for Clients and Users.

Transaction Screen: Deposit, Withdraw, and Transfer with real-time file updates.

Security Logs:

LoginRegister.txt: Logs entry times and user permissions.

TransferLog.txt: Logs financial activities with User Attribution.

Permission System: Bitwise Access Control to restrict specific features based on user roles.

🛠️ Tech Stack
Language: C++ (Standard 11/17)

Paradigm: OOP (Encapsulation, Inheritance, Polymorphism)

Data Persistence: Flat-file database with Custom Parsing & Encryption.

IDE: VS Code / Visual Studio.
