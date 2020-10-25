>This Project demenstrates the use of Data File Handling in C++. The program is pretty straight forward, just pull the entire repository and open with any C++ Compiler/IDE.

#Main Menu:
```
==================================================
==========GROCERY STORE AND E-BILLING=============
==================================================


                MAIN MENU

                 01. CUSTOMER

                 02. ADMINISTRATOR

                 03. EXIT

                Please Select Your Option (1-3) :
```
*Enter your Option above.

#Customer Menu:
```
                ITEM MENU
===============================================
INO.            NAME            PRICE
===============================================
1               Bread           40
2               Eggs            6
3               Pickles         120
4               Chicken         320
5               Fish            860
6               Milk            60
7               Butter          250
8               Paneer          260
9               Sugar           40
10              Rice            80
===============================================
 PLACE YOUR ORDER
===============================================

Enter The Item Code of The Item : 2
Quantity in Number : 6

Do You Want To Order Another Item ?(Y/N) :
```
*Enter your Order Details above.

#Billing Menu:
```
                                INVOICE
============================================================================
 Ino    Item    Quantity        Price   Amount  Amount After Discount
============================================================================
 1      Bread   2               40      80              80
 2      Eggs    1               6       6               6
 3      Pickles 1               120     120             115.2
============================================================================

                        Take out Total       =          201.2
                        SGST @9.00%          =           18.108
                        CGST @9.00%          =           18.108
                        Total (incl.taxes)   =          237.416
                        Rounding Off         =            0.42

                        Total Due            =          237


                        **THANK YOU FOR VISITING US**

                        **PLEASE COME AGAIN**
```

#Admin Menu:
```
=======================================================
=============GROCERY STORE AND E-BILLING===============
=======================================================


        ADMIN MENU

        1.CREATE ITEM

        2.DISPLAY ALL PRODUCTS

        3.QUERY(SEARCH BY ITEM CODE)

        4.MODIFY ITEM

        5.DELETE ITEM

        6.VIEW ITEM MENU

        7.LOGOUT AND BACK TO MAIN MENU

        8.LOGOUT AND EXIT

        Please Enter Your Choice (1-7) :
```
*In above Menu you can access Admin Privileges.