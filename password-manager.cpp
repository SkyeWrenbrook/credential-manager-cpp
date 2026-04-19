// This program is a basic C++ password manager that stores login credentials and lets the user manage them through a text based menu.


#include <iostream>
#include <vector>
#include <string>

struct Credential {
    std::string site;
    std::string username;
    std::string password;
};
// Displays the main menu to the user
void showMenu() {
    std::cout << "\nPassword Manager Menu\n";
    std::cout << "1. Add credential\n";
    std::cout << "2. View all credentials\n";
    std::cout << "3. Search credentials\n";
    std::cout << "4. Delete credential\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice = 0;

    // Stores all saved credentials during program execution
    std::vector<Credential> credentials;

    // Temporary object used when entering a new credential
    Credential newCredential;

    // Keep running until the user chooses to exit
    while (choice != 5) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
		// Collect a new credential from the user
                std::cout << "\nEnter site: ";
                std::cin >> newCredential.site;

                std::cout << "Enter username: ";
                std::cin >> newCredential.username;

                std::cout << "Enter password: ";
                std::cin >> newCredential.password;

		// Save the new credential in the list
                credentials.push_back(newCredential);
                std::cout << "Credential added.\n";
                break;
            }

            case 2: {
		// Show every saved credential
                std::cout << "\nViewing credentials\n";

                if (credentials.empty()) {
                    std::cout << "No credentials stored yet.\n";
                } else {
                    for (size_t i = 0; i < credentials.size(); i++) {
                        std::cout << "\nCredential " << (i + 1) << "\n";
                        std::cout << "Site: " << credentials[i].site << "\n";
                        std::cout << "Username: " << credentials[i].username << "\n";
                        std::cout << "Password: " << credentials[i].password << "\n";
                    }
                }
                break;
            }

            case 3: {
		// Search for a matching site, username, or password
                std::string searchTerm;
                bool found = false;

                std::cout << "Enter site, username, or password to search: ";
                std::cin >> searchTerm;

                for (size_t i = 0; i < credentials.size(); i++) {
                    if (searchTerm == credentials[i].site ||
                        searchTerm == credentials[i].username ||
                        searchTerm == credentials[i].password) {
                        std::cout << "\nMatch found:\n";
                        std::cout << "Site: " << credentials[i].site << "\n";
                        std::cout << "Username: " << credentials[i].username << "\n";
                        std::cout << "Password: " << credentials[i].password << "\n";
                        found = true;
                    }
                }
		// Tell the user if nothing matched
                if (!found) {
                    std::cout << "No matches found.\n";
                }
                break;
            }

            case 4: {
		// Delete a credential by its displayed number
                int deletionIndex;

                if (credentials.empty()) {
                    std::cout << "No credentials to delete.\n";
                    break;
                }

                std::cout << "Enter the number you wish to delete:\n";
                for (size_t i = 0; i < credentials.size(); i++) {
                    std::cout << (i + 1) << ". " << credentials[i].site
                              << " / " << credentials[i].username << "\n";
                }

                std::cin >> deletionIndex;

                if (deletionIndex < 1 || deletionIndex > static_cast<int>(credentials.size())) {
                    std::cout << "That number does not exist.\n";
                } else {
                    credentials.erase(credentials.begin() + (deletionIndex - 1));
                    std::cout << "Credential deleted successfully.\n";
                }
                break;
            }

            case 5:
		// End the program
                std::cout << "Exiting...\n";
                break;

            default:
		// Handle invalid menu input
                std::cout << "Invalid choice.\n";
                break;
        }
    }

    return 0;
}
