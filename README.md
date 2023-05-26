### Gilded Rose
These are the instructions we were given for this assignment
<br><br>

This homework is different from, but was inspired by this refactoring exercise:
https://github.com/emilybache/GildedRose-Refactoring-Kata

Purpose: To teach you how to use hash maps to break the speed of light and
transcend mortality in the context of a general store in a video game.

To begin, the user will enter the name of a file.

This file contains a series of items that will be sold in the store.
Each item has the following attributes (one on each line):

1) A name (string) - one or more words. If an item with that name is already
in the inventory, die.

2) A price (int) - ranges between 1 and 100. If the value is outside this
range in the input file, die. Values are in "gold pieces" (written gp).

3) The sell-by date (int) - after the sell-by date is passed, the price
will drop by 1 each day. If it drops to 0 or below, it is removed from the
system. You can think of this as the expiration date in a grocery store, or as
the date after which the item will start going on sale if it doesn't sell.

4) A special property (string). It can have only one special
property, or "None". Special properties include:
"Conjured" - After the expiration date has passed the value declines twice as
fast losing -2gp from its value per day that goes past instead of -1gp.
"Aging" - The value goes up by one every day (ignore its expiration date, it is
not used), up to a maximum of 100.
"Legendary" - The value can go over 100.
"Limited Time" - The value goes up by 2 each day until the expiration date,
and then the value drops to 0.

Example file with three items: Iron Helmet (a normal item worth 10gp with an expiration
date of day 1000), Sulfuras (a legendary item worth 222 gold pieces, with a
sell-by date of day 7), and Château Latour (an aging item that starts off worth 47gp to
begin, and going up +1 gp in value per day until it hits 100gp in price).

Iron Helmet
10gp
1000
None
Sulfuras
222gp
7
Legendary
Château Latour
47gp
0
Aging

After you have read in the starting items, the day will be set to Day 1 and
the program begins for real.

The user will repeatedly give one of these four commands:
1) Stock Item - This will add a new item to be sold in the shop. It follows
the same rules as reading in the items from the file above.
2) Purchase Item - This will delete an item from the shop. The price of the
item is added to the tab of the user. At the end of the program, you will
print out the total amount of money spent by the user in the shop.
3) Stock Check - The program will print out how many items are in stock, and
then the user can query if a given item is in stock or not. If it is not in
stock, it will print "ITEM NOT IN STOCK". If it is in stock, it will print out
the information for the item, including the current price (not the original
price).
4) Advance Day - The day moves forward by 1. This will adjust the price of
items in stock following the rules above.

Any other input, the program will quit and print out the total price of the
purchases by the user.

Notes:
1. All of the code for your Item class should be held in item.h. Use proper class
design. This includes not using "using namespace std" in the header file.
2. You must write a operator<< for the Item class to handle outputting it to the screen (from Stock Check)
3. You must write an operator>> for the Item class to handle reading it from a
file and the keyboard
4. You can either put everything into the header file, or you can split it
into a header and implementation file.
