
# Contact Manager — Console-Based Address Book in C

## Description

This C program implements a simple command-line Contact Manager allowing users to add, delete, modify, display, save, and load contact entries. Contacts are stored dynamically using a doubly-linked list. The program practices dynamic memory management, file handling, and linked list operations.

---

## Features

* Add new contacts (Name, First Name, Phone Number, Email)
* Delete contacts by name and first name
* Modify contact details
* Display all contacts
* Save contacts to a text file
* Load contacts from a file and display them

---

## Project Structure

* `src/main.c` — contains the main menu and program logic
* `src/contacts.h` — defines data structures and functions for managing contacts
* `data/contacts.txt` — example file for saved contacts

---

## Compilation & Execution

```bash
gcc src/main.c -o contact-manager
./contact-manager
```

---

## Usage

1. Run the program.
2. Choose an option from the menu:

   * **1**: Add a new contact
   * **2**: Delete a contact
   * **3**: Modify a contact
   * **4**: Display all contacts
   * **5**: Save contacts to file
   * **6**: Load contacts from file
   * **7**: Exit
3. Follow prompts to enter or confirm contact information or file names.

---

## Data Structure

Contacts are stored as nodes in a doubly-linked list:

```c
typedef struct data {
    char nom[50];
    char prenom[50];
    long num;
    char gmail[66];
} data;

typedef struct liste {
    data contact;
    struct liste *next;
    struct liste *prev;
} liste;
```

---

## Example of Saved Contact Format

```
------------------------------- Contact Information -----------------------------

Name : Doe
First Name : John
Phone Number : 0612345678
Email Address : john.doe@gmail.com

--------------------------------------------------------------------------------
```

---

## License


This project is licensed under the MIT License — you are free to use, copy, modify, merge, publish, and distribute the software, provided that the original author is credited and the license notice is included in all copies or substantial portions of the software.

See the [LICENSE](LICENSE) file for full terms.

---

