//Habiba Elsayed Hemayed_20255110_Reem Mohamed Behairy_20246053_G3
#include "FoodItem.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
FoodItem::FoodItem() {
    itemName = "";
    price = 0.0;
    quantity = 0;
}
FoodItem::FoodItem(string n, double p, int q) {
    itemName = n;
    price = p;
    quantity = q;
}
string FoodItem::getItemName() const {return itemName;}
double FoodItem::getPrice() const {return price;}
int FoodItem::getQuantity() const {return quantity;}
void FoodItem::setItemName(const string& name) {itemName = name;}
void FoodItem::setPrice(double newPrice) {price = newPrice;}
void FoodItem::setQuantity(int newQuantity) {quantity = newQuantity;}
double FoodItem::calculateItemTotal() const {return price * quantity;}

void FoodItem::displayItem() const {
    cout << itemName << " x" << quantity << " @ " << price << " EGP = " << calculateItemTotal() << " EGP" << endl;
}