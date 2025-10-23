#include "Subscriber.h"
#include <cstring>
#include <iostream>
#include <ostream>

Subscriber* Subscriber::home_numbers_book = nullptr;
Subscriber* Subscriber::phone_book = nullptr;
int Subscriber::home_numbers_count = 0;
int Subscriber::phone_count = 0;

void Subscriber::SortPhoneBook() {
    for (int i = 0; i < phone_count - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < phone_count; j++) {
            if (strcmp(phone_book[j].phone_number, phone_book[min_idx].phone_number) < 0)
                min_idx = j;
        }

        if (min_idx != i) {
            Subscriber temp = phone_book[i];
            phone_book[i] = phone_book[min_idx];
            phone_book[min_idx] = temp;
        }
    }
}

void Subscriber::SortHomeBook() {
    for (int i = 0; i < home_numbers_count - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < home_numbers_count; j++) {
            if (strcmp(home_numbers_book[j].home_number, home_numbers_book[min_idx].home_number) < 0)
                min_idx = j;
        }

        if (min_idx != i) {
            Subscriber temp = home_numbers_book[i];
            home_numbers_book[i] = home_numbers_book[min_idx];
            home_numbers_book[min_idx] = temp;
        }
    }
}

void Subscriber::PrintHomeNumbers() {
    std::cout << std::endl;
    for (int i = 0; i < home_numbers_count; i++) {
        std::cout << "[HOLDER]: " << home_numbers_book[i].number_holder
        << "\n[HOME NUMBER]: " << home_numbers_book[i].home_number
        << "\n[PHONE NUMBER]: " << home_numbers_book[i].phone_number << std::endl;
        std::cout << "-----------------------------\n";
    }
}

void Subscriber::PrintPhoneNumbers() {
    std::cout << std::endl;
    for (int i = 0; i < phone_count; i++) {
        std::cout << "[HOLDER]: " << phone_book[i].number_holder
        << "\n[HOME NUMBER]: " << phone_book[i].home_number
        << "\n[PHONE NUMBER]: " << phone_book[i].phone_number << std::endl;
        std::cout << "-----------------------------\n";
    }
}


Subscriber & Subscriber::operator=(const Subscriber &sub) {
    if (this == &sub) return *this;

    delete[] number_holder;
    delete[] home_number;
    delete[] phone_number;

    number_holder = new char[strlen(sub.number_holder) + 1];
    strcpy(number_holder, sub.number_holder);

    home_number = new char[strlen(sub.home_number) + 1];
    strcpy(home_number, sub.home_number);

    phone_number = new char[strlen(sub.phone_number) + 1];
    strcpy(phone_number, sub.phone_number);

    return *this;
}

void Subscriber::AddPhoneNumber(const Subscriber& sub) {
    Subscriber* temp = new Subscriber[phone_count + 1];

    for (int i = 0; i < phone_count; i++) temp[i] = phone_book[i];

    temp[phone_count] = sub;

    delete[] phone_book;
    phone_book = temp;
    phone_count++;
}

Subscriber::Subscriber(const Subscriber& other) {
    number_holder = new char[strlen(other.number_holder) + 1];
    strcpy(number_holder, other.number_holder);

    home_number = new char[strlen(other.home_number) + 1];
    strcpy(home_number, other.home_number);

    phone_number = new char[strlen(other.phone_number) + 1];
    strcpy(phone_number, other.phone_number);
}
void Subscriber::AddHomeNumber(const Subscriber& sub) {
    Subscriber* temp = new Subscriber[home_numbers_count + 1];

    for (int i = 0; i < home_numbers_count; i++) temp[i] = home_numbers_book[i];

    temp[home_numbers_count] = sub;

    delete[] home_numbers_book;
    home_numbers_book = temp;
    home_numbers_count++;
}

Subscriber::Subscriber() {
    number_holder = new char[8];
    strcpy(number_holder, "No name");

    home_number = new char[9];
    strcpy(home_number, "No number");

    phone_number = new char[9];
    strcpy(phone_number, "No number");
}

Subscriber::Subscriber(const char *number_holder, const char *home_number, const char *phone_number) {
    if (number_holder != nullptr) {
        this->number_holder = new char[strlen(number_holder) + 1]{};
        strcpy(this->number_holder, number_holder);
    }
    else {
        this->number_holder = new char[8];
        strcpy(this->number_holder, "No name");
    }

    if (home_number != nullptr) {
        this->home_number = new char[strlen(home_number) + 1]{};
        strcpy(this->home_number, home_number);
    }
    else {
        this->home_number = new char[10];
        strcpy(this->home_number, "No number");
    }

    if (phone_number != nullptr) {
        this->phone_number = new char[strlen(phone_number) + 1]{};
        strcpy(this->phone_number, phone_number);
    }
    else {
        this->phone_number = new char[10];
        strcpy(this->phone_number, "No number");
    }
}

void Subscriber::PrintInfo() const {
    std::cout << "Subscriber number: " << number_holder
    <<  "\nHome number: " << home_number
    << "\nPhone number: " << phone_number;
}



