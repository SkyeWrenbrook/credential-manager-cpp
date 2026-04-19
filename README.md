# Password Manager

A simple command-line password manager written in C++.

## How it works
The program stores credentials using a 'vector' of objects containing a site, username, and password.

Users interact with the system through a menu-driven interface to:
- add new credentials
- view stored entries
- search for specific entries
- delete credentials

Data is currently stored only during runtime and is not persisted to disk. 

## What I Learned

- Managing structured data using C++ vectors
- Building a menu-driven CLI application
- Handling user input and its limitations (e.g., issues with spaces)
- Understanding the importance of secure password storage
- Recognizing the need for hashing/encryption and file persistence

## Build and Run
Compile with a C++ compiler such as g++:

```bash
g++ password-manager.cpp -o password-manager
./password-manager
```

## Notes
- This version stores data in memory and is lost when the program exits
- It does not use file storage yet.
- It does not encrypt or hash passwords.
- Input is currently handled with `std::cin`, so values with spaces will be split at the first space.

## Future Improvements
- Add file I/O to save and load credentials
- Add a `PasswordManager` class
- Support input with spaces
- Add password hashing or encryption
