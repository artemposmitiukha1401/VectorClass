#ifndef DIRECTORY_CLASS_SUBSCRIBER_H
#define DIRECTORY_CLASS_SUBSCRIBER_H


class Subscriber {
    char* number_holder = nullptr;
    char* home_number =  nullptr;
    char* phone_number = nullptr;

    static Subscriber* home_numbers_book;
    static int home_numbers_count;
    static Subscriber* phone_book;
    static int phone_count;


public:
    static void SortPhoneBook();
    static void SortHomeBook();
    static void PrintHomeNumbers();
    static void PrintPhoneNumbers();
    Subscriber &operator=(const Subscriber &sub);
    static void AddPhoneNumber(const Subscriber& sub);
     static void AddHomeNumber(const Subscriber& sub);
    Subscriber();
    Subscriber(const Subscriber& other);
    Subscriber(const char* number_holder, const char* home_number, const char* phone_number);
    void PrintInfo() const;
    ~Subscriber() {
        delete[] number_holder;
        delete[] home_number;
        delete[] phone_number;
    }
};


#endif