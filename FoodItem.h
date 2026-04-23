#ifndef FOODITEM_H
#define FOODITEM_H
#include<string>
using namespace std;
class FoodItem {
private:
    string itemName;
    double price;
    int quantity;
public:
    FoodItem();
    FoodItem(string name, double price, int quantity);
    void setItemName(const string& name);
    void setPrice(double price);
    void setQuantity(int quantity);
    string getItemName() const;
    double getPrice() const;
    int getQuantity() const;
    double calculateItemTotal() const;
    void displayItem() const;
};
#endif //FOODITEM_H
