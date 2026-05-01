# Credential Manager (C++ CLI)

## Overview
This project is part of a larger system exploring how credential data is collected, structured, and stored.
It focuses on the application layer, where user input is handled and organized before being stored or analyzed.

[Related database project:](https://github.com/SkyeWrenbrook/credential-database-sqlite)

## System Behavior
The application collects credential data through a CLI interface and structures it into objects containing:

- site
- username
- password

These entries are stored in memory using a vector, allowing basic operations such as:

- insertion (adding new credentials)
- retrieval (viewing stored credentials)
- filtering (searching for specific entries)
- deletion

This project demonstrates how application-layer logic organizes and interacts with sensitive data before it is stored.

## What I Learned

- how application-layer logic structures and manages sensitive data
- how user input limitations can affect data integrity
- how temporary in-memory storage differs from persistent storage
- how early design decisions impact future security and scalability

## Security Notice

Credentials are stored in plaintext in this version.

In a real system, this would introduce significant risk and would require:
- hashing or encryption
- secure storage practices
- proper access controls

This highlights how early design decisions affect system security.

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
- Add persistent storage (file I/O or database integration) to retain data across sessions
- Improve input handling to support full strings and prevent malformed entries
- Introduce password hashing or encryption to protect stored credentials
- Refactor into a structured class-based design for better scalability and maintainability
- Integrate with a database layer (SQLite) for long-term storage and querying
- Add validation and error handling to improve data integrity

These improvements reflect the transition from a simple application prototype to a more secure and scalable system.
