#include <iostream>
#include "iloc.h"
#include <string>

int main(){
   while (true) {

       //gets input for expressions or termination of program
       std::string choice = "";
       std::cout << "Give expression or type -1 to end:  ";
       std::cin >> choice;

       //check if it's not -1
       if (choice != "-1") {
           //turning the string into characters
           int count = choice.length();
           char array [count];

           // appending all characters in the array
           for (int i = 0; i < count; i++) {
               array[i] = choice[i];
           }

           //reset the stack from previous expression
           while (!isEmpty<char>()) {
               pop<char>();
           }

           //tracks whether any mismatch/error has occurred, this is to avoid double printing messages
           bool valid = true;

           //putting the characters in the stack
           for (int i = 0; i < count; i++) {
               char temp = array[i];

               //checking if it's anything other than an open delimiter
               //the push function has the "if" condition for checking balancing characters
               if (temp != ')' && temp != '}' && temp != ']') {
                   push<char>(temp);
               }

               //if it's a closing delimiter, but with an empty stack this will print out
               else if (isEmpty<char>()) {
                   std::cout << "stack is empty..\n";
                   valid = false;
                   break;
               }

               //if it's an open delimiter with a stack, it'll run this
               else {
                   //popping the character
                   char tempC = pop<char>();

                   //checking if characters mismatch
                   switch (tempC) {
                       case '(':
                           if (temp == ')') {
                               break;
                           }
                           else {
                               std::cout << "Error has Occured! Not Valid!\n";
                               valid = false;
                               break;
                           }
                       case '{':
                           if (temp == '}') {
                               break;
                           }
                           else {
                               std::cout << "Error has Occured! Not Valid!\n";
                               valid = false;
                           }
                           break;
                       case '[':
                           if (temp == ']') {
                               break;
                           }
                           else {
                               std::cout << "Error has Occured! Not Valid!\n";
                               valid = false;
                           }
                           break;

                   }
                   //uses our boolean value to check if we've already found an error
                   if (!valid) {
                       break;
                   }
               }
           }
           //checks if the stack is not empty
           //important that this has an "and" statement so it can get skipped if it's already invalid
           if (valid && !isEmpty<char>()) {
               std::cout << "Error has Occured! Not Valid!\n";
               valid = false;
           }
           //only reached if no mismatch, no premature closer, and nothing left over
           if (valid) {
               std::cout << "Valid!\n";
           }
       }
       //if it's -1 then it will terminate the program
       else {
           return 0;
       }
   }
    return 0;
}