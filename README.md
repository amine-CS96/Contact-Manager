# 📒 Contact Manager in C

A simple command-line Contact Manager written in C, supporting creation, editing, deletion, saving, and loading of contact entries. The program uses dynamic memory allocation and doubly-linked lists for efficient contact management, along with file handling to persist data.

---

## 📌 Features

- ✅ Add a new contact (Name, First name, Phone number, Email)
- ✅ Delete a contact by name and first name
- ✅ Modify contact details
- ✅ Display all contacts
- ✅ Save contacts to a text file
- ✅ Load and display contacts from a file

---

## 🗂️ Project Structure

contact-manager/
├── src/
│   ├── main.c
│   └── contacts.h
├── data/
│   └── contacts.txt         # Exemple de fichier sauvegardé
└── README.md



---

## 🧠 Data Structure

The program uses a doubly-linked list to store the contacts dynamically:

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

---

## 🛠️ Compilation & Execution


▶️ Compile with GCC (manual)

    # gcc src/main.c -o contact-manager
    # ./contact-manager

---

## 📋 Example Menu

--------------------------------------MENU:-------------------------------------------

   1. Ajouter un nouveau contact
   2. Suppression d'un contact
   3. Modification d'un contact
   4. Affichage de tous les contacts
   5. Sauvegarde des contacts dans un fichier
   6. Chargement des contacts depuis un fichier
   7. Terminer

---------------------------------------------------------------------------------------


## 💾 Example Output (saved file)
-------------------------------les informations de contact  1  :-----------------------------
Nom : Doe
Prenom : John
Numero de telephone  :0612345678
Adresse gmail  : john.doe@gmail.com
---------------------------------------------------------------------------------------------

--

## - 📜 License
This project is for educational purposes. You are free to use, modify, and share it.    
