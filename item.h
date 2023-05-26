#pragma once // Header Guard
#include <iostream>
using std::string;

class Item {
        public:
        string name;
        int price;
        int sellBy;
        int initDay = 1;
        int current = 1;
        string attribute;
        int daysActive;
        
        Item() : name("Untitled Goose Game"), price(-1) {} //Nonsense item to show us if we messsed up when creating an item
        Item(const string &new_name, int new_price) : name(new_name), price(new_price) {}

        void set_date(int day) {
                daysActive = day - initDay;
        }
        void set_init(int currentDay) {
                initDay = currentDay;
        }
        void set_current(int currentDay) {
                current = currentDay;
        }
        void set_name(string newName){
                name = newName;
        }
        void set_price(int newPrice){
                if (newPrice > 100 or newPrice <= 0) {
                        std::cout << "BAD INPUT!\n";
                }
                else {
                        price = newPrice;
                }
        }
        void set_sell(int newSell){
                sellBy = newSell;
        }
        void set_attribute(string newAtt){
                attribute = newAtt;
        }

        int get_date() const {
                return daysActive;
        }
        string get_name() const {
                return name;
        }
        int get_init() const {
                return initDay;
        }
        int get_current() const {
                return current;
        }
        int get_price() const {
                int x;

                int daysPast = daysActive - sellBy + 1;


                if (current == initDay && ((price <= 0 or price > 100) && attribute != "Legendary")){
                        std::cout << "BAD INPUT!\n";
                        exit(1);
                }

                if (attribute == "Limited Time"){

//                      std::cout << "current: " << current << std::endl; //debugging strings
//                      std::cout << "init: " << initDay << std::endl;  //debugging strings
                        if (daysPast > 0) {
                                return 0;
                        }

                        else {
                                x = (price + (2 * daysActive));
                                if ( x > 100 ) {
                                        return 100;
                                }
                                else {
//                                      std::cout << "X: " << x << std::endl;
                                        return x;
                                }
                        }
                        }
                else if (attribute == "Aging") {
                        x = (price + (daysActive));
                        if (x > 100) {
                                return 100;
                        }
                        else return x;
                }
                else if (attribute == "Conjured") {
                        if (daysPast > 0) {
                                x = price - 2 * daysPast;
                                if (x == 0) return 0;
                                else return x;
                        }
                        else return price;
                }
                else if (attribute == "Legendary") {
                        if (daysPast > 0) {
                                x = price - daysPast;
                                if (x == 0) return 0;
                                else return x;
                        }
                        else return price;
                }
                else return price;
        }
        int get_sell() const {
                return sellBy;
        }
        string get_attribute() const {
                return attribute;
        }
        //YOU: Write an operator<< and operator>>
        friend std::ostream& operator<<(std::ostream &outs, const Item &output){
                return outs << "Name: " << output.name << std::endl
                        << "Price: " << output.get_price() << "gp" << std::endl
                        << "Sell By: " << output.sellBy << std::endl
                        << "Attribute: " << output.attribute << std::endl;
        }

        friend std::istream& operator>>(std::istream& ins, Item &input){
        //      return ins >> input.name >> input.price >> input.sellBy >> input.attribute;
                int temp;
                getline(ins, input.name);
                ins >> input.price;
                ins.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ins >> input.sellBy;
                ins.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(ins, input.attribute);

//              std::cout << " price: " << input.price << std::endl;

                if (input.price > 100) {

//                      std::cout << " bigger than 100 " << std::endl;
                        if (input.attribute != "Legendary") {
//                               std::cout << input.name << " " << input.price << std::endl;
                                std::cout << "BAD INPUT!\n";
                                exit(0);
                        }
                }
/*              else if (input.price < 0) {
                        std::cout << "name  " << input.name.size()<< "price  " << input.price << std::endl;
                        std::cout << "BAD INPUT!\n";
                        exit(0);
                }
*/              else if (input.price == 0) {
//                      std::cout << input.name << " " << input.price << std::endl;
                        std::cout << "BAD INPUT!\n";
                        exit(1);
                }
                else {
                        return ins;
                }
                return ins;
        }

};
