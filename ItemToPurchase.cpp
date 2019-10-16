#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;

    return;
}

ItemToPurchase::ItemToPurchase(string name, string description,
                               int price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;

    return;
}

void ItemToPurchase::SetName(string name) {
    itemName = name;

    return;
}

void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;

    return;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;

    return;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;

    return;
}

string ItemToPurchase::GetName() const {
    return itemName;
}

string ItemToPurchase::GetDescription() const {
    return itemDescription;
}

int ItemToPurchase::GetPrice() const {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}

void ItemToPurchase::PrintItemCost() {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice
         << " = $" << itemPrice * itemQuantity << endl;
}

void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}