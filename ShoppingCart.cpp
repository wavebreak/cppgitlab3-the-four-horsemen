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

}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    unsigned k;
    string tempName = item.GetName();
    int tempPrice = item.GetPrice();
    string tempCartName;
    string tempDesc = "";
    int tempQuan = item.GetQuantity();


    for(k = 0; k < cartItems.size(); ++k) {
        if (tempName == cartItems.at(k).GetName()) {
            if (cartItems.at(k).GetQuantity() == 0) {
                //cout << "Enter the item quantity:"<<endl;
                //cin >> tempQuan;
                cartItems.at(k).SetQuantity(tempQuan);
            }
            if (cartItems.at(k).GetPrice() == 0) {
                cout << "Enter the item price:" << endl;
                cin >> tempPrice;
                cartItems.at(k).SetPrice(tempPrice);
            }
            if (cartItems.at(k).GetDescription() == "none") {
                cout << "Enter the item description:" << endl;
                cin.ignore();
                getline(cin, tempDesc);

                cartItems.at(k).SetDescription(tempDesc);
            }
            break;
        } else if (tempName != tempCartName && k == cartItems.size() - 1) {
            break;
        }
    }

    if(tempName != cartItems.at(k+0).GetName()){
        cout<< "Item not found in cart. Nothing modified.";
    }
}

int ShoppingCart::GetNumItemsInCart() {
    return 0;
}

double ShoppingCart::GetCostOfCart() {
    return 2.0;
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