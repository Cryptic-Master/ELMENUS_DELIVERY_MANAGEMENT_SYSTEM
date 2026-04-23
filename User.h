//Habiba Elsayed Hemayed_20255110_Reem Mohamed Behairy_20246053_G3
#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
protected:
    string userId;
    string name;
    string phoneNumber;
    static int totalUsers;

public:
    User();
    User(string userId, string name, string phoneNumber);
    virtual ~User();

    virtual void displayInfo() const = 0;
    virtual double calculateEarnings() const = 0;

    static int getTotalUsers();

    string getUserId() const;
    string getName() const;
    string getPhoneNumber() const;
};

#endif
