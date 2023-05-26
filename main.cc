#include "/public/read.h"
#include "item.h"
#include <unordered_map>
using namespace std;

void die(){
        cout << "BAD INPUT!\n";
        exit(1);
}

int main() {
        //Item testItem;
        //testItem = read("Enter a name, price, sellby, and attribute:\n");
        //cout << testItem;

        unordered_map<string, Item> inventory;
        string fileName = readline("Please enter a file to open:\n");

        int total = 0;
        int day = 1;


        ifstream myfile;
        myfile.open(fileName.c_str());
        if (!myfile) die();

        //Reads in the starter inventory from the opened file
        while(myfile){
                Item temp = read(myfile);
                if (!myfile) break;

                string addKey = temp.get_name();
                inventory.insert({addKey, temp});

        }
        //End initial inventory

        //Begin user-driven actions
        while(true){
                cout << "1. Stock Item" << endl
                        << "2. Purchase Item" << endl
                        << "3. Stock Check" << endl
                        << "4. Advance Day" << endl;
                int choice;
                string choicestr;
                getline(cin, choicestr);
                if (!cin) break;
                else {
                        choice = stoi(choicestr);
                }
                //Stock Item
                if (choice == 1) {
                        Item temp;
                        temp = read();

//                      if (temp.get_price() > 100 && temp.get_attribute() != "Legendary"){
                        if (temp.get_price() == 0){
                                die();
                        }
                        temp.set_init(day);
                        temp.current = day;

                        if (!cin) die();
                        string addKey = temp.get_name();
                        if (inventory.find(addKey) != inventory.end()){
                                die();
                        }
                        else {
                                inventory.insert({addKey, temp});
                        }
                }
                //Purchase Item
                else if (choice == 2) {
                        string checkKey = readline("Please enter the name of the item to buy:\n");
                        int addToTotal = 0;
                        if (inventory.find(checkKey) == inventory.end()) {
                                cout << "ITEM NOT IN STOCK" << endl;
                        }
                        else {
                                inventory.find(checkKey)->second.set_date(day);
                                if (inventory.find(checkKey)->second.get_price() <= 0) {
                                        cout << "ITEM NOT IN STOCK" << endl;
                                }
                                else {
                                        cout << "That will be: " << inventory.find(checkKey)->second.get_price() << "gp" << endl;

                                addToTotal = inventory.find(checkKey)->second.get_price();
//                              cout << addToTotal << endl;
                                total += addToTotal;
                                inventory.erase(checkKey);
                                }
                        }
                }
                //Stock Check
                else if (choice == 3) {
                        string checkKey = readline("Please enter the name of the item to look up:\n");
                        if (inventory.find(checkKey) == inventory.end()) {
                                cout << "ITEM NOT IN STOCK" << endl;
                        }
                        else {
                                inventory.find(checkKey)->second.set_date(day);
                                if (inventory.find(checkKey)->second.get_price() <= 0) {
                                        cout << "ITEM NOT IN STOCK" << endl;
                                        inventory.erase(checkKey);
                                }
                                else {
                                        cout << inventory.find(checkKey)->second;
                                }
                        }
                }
                //Advance Day
        else if (choice == 4) {
            day++;
//                      for (pair<const string, Item> &i : inventory) {
//                              i.second.set_current(day);
//                      }
                }

                /*
                //Print Inventory
                else if (choice == 5) {
                        for (const pair<const string, Item> &i : inventory) {
                                cout << i.second;
                        }
                }
                */

                //Bad Choice
                else break;

        }
      //End user-driven inventory
  

        cout << "Your total bill is: " << total << "gp" <<  endl;

}
        //Prints Out Every Item in Inventory
//      for (const pair<const string, Item> &i : inventory){
///             cout << i.second << endl;
//      }





