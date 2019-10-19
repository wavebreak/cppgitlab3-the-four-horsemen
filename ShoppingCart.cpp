#include <iostream>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}


void ShoppingCart::AddItem(ItemToPurchase item) {
  cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name) {
  for (int i = 0; i < cartItems.size(); i++){
    if(cartItems.at(i).GetName() == name){
      cartItems.erase(cartItems.begin()+i);   
    }
  }
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {

}

int ShoppingCart::GetNumItemsInCart() {
  int counter = 0;

        for (int i = 0; i < cartItems.size(); ++i){
            counter +=  cartItems.at(i).GetQuantity();
        }

        return counter;
    } 



double ShoppingCart::GetCostOfCart() {
  double all = 0;

        for (int i = 0; i < cartItems.size(); i++){
            all += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
        }

        return all; 
    }

void ShoppingCart::PrintTotal() {
    unsigned i;
    int totalCost;

    totalCost = 0;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

    if(cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemCost();
        }
    }

    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    totalCost = GetCostOfCart();

    cout << endl << "Total: $" << totalCost << endl;
}

void ShoppingCart::PrintDescriptions() {
    unsigned i;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;

    if(cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemDescription();
        }
    }

    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
}

