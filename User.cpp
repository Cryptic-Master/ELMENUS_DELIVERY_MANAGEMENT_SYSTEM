//Habiba Elsayed Hemayed_20255110_Reem Mohamed Behairy_20246053_G3
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

int User::totalUsers = 0;

User::User() {
    userId = "";
    name = "";
    phoneNumber = "";
    totalUsers++;
}
User::User(string id, string userName, string phone) {
    userId = id;
    name = userName;
    phoneNumber = phone;
    totalUsers++;
}
User::~User() {}
int User::getTotalUsers() {return totalUsers;}
string User::getUserId() const {return userId;}
string User::getName() const {return name;}
string User::getPhoneNumber() const {return phoneNumber;}