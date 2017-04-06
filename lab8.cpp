//============================================================================
// Name        : lab8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class message{
	protected:
		string mess1; //the message needs to be accessed by derived class
	public:
		message(); //default constructor
		message(string); //constructor that takes in message
		virtual ~message();
		virtual void print();//prints message

};

class morseCodeMessage : public message{ //class derived from message
	private:
		string mcm; //morse code message
	public:
		morseCodeMessage(); //default constructor
		morseCodeMessage(string); //parametric constructor if given string initially
		void translate(); //translates to morse code
		void print(); //prints the regular message and morse code message
};

class messageStack{
	private:
		vector <message*> stack; //defines a vector stack of type message
	public:
		messageStack(message*); //constructor takes one message object
		~messageStack(); //to deallocate memory
		void push(message*); //pushes messages onto stack
		message* pop(void); //returns message popped off stack
		void printStack(void); //prints all messages on stack
};

int main() {
	morseCodeMessage* mess = new morseCodeMessage; //calls default constructor & message default constructor
	mess->print(); //calls morseCodeMessage print method

	message test_message1 = {"Hello world."}; //calls parametric message constructor
	test_message1.print(); //shows that message was created properly

	morseCodeMessage* me2 = new morseCodeMessage("My name is Katie."); //calls parametric morseCodeMessage constructor
	me2->print(); //calls print method

	message test_message2; //creates a default message object
	test_message2.print();

	morseCodeMessage* me3 = new morseCodeMessage; //calls default morseCodeMessage constructor & message default constructor
	me3->print(); // calls print method

	morseCodeMessage* me4 = new morseCodeMessage; //calls default morseCodeMessage constructor & message default constructor
	me4->print(); //calls print method

	messageStack stack1(&test_message1); //calls messageStack parametric constructor
	stack1.push(mess); //calls push method and pushes onto stack
	cout << "\nNew Stack:\n";
	stack1.printStack(); //calls printStack method

	stack1.push(me2); //pushes onto stack
	cout << "\nNew Stack:\n";
	stack1.printStack(); //prints new stack

	stack1.push(&test_message2); //pushes a message class to the stack

	stack1.push(me3); //pushes onto stack
	cout << "\nNew Stack:\n";
	stack1.printStack(); //prints new stack

	message* popped = stack1.pop(); //pops message off stack
	cout << "\nPopped message:\n";
	popped->print(); //prints popped message
	cout << "\nNew Stack:\n";
	stack1.printStack(); //prints new stack

	stack1.push(me4); //pushes onto stack
	cout << "\nNew Stack:\n";
	stack1.printStack(); //prints new stack

	return 0;
}

message::message(void){
	cout << "\nPlease enter a message: "; //prompts user for message
	getline(cin, mess1, '\n'); //takes in message
}

message::message(string mess){
	mess1 = mess; //sets given string to string member of class
}

message::~message(void){
	//no memory to be freed
}

void message::print(void){
	cout << mess1 <<endl; //prints message to the string
	return;
}

messageStack::messageStack(message* mess){
	stack.push_back(mess); //pushes first message onto stack
}

messageStack::~messageStack(void){
	//no memory to be freed
}

void morseCodeMessage::translate(void){
	for(auto &c:mess1){ //loops through every character of the string from message
		switch(c){
			case 'A':
			case 'a':
				mcm += ".-";
				break;
			case 'B':
			case 'b':
				mcm += "-...";
				break;
			case 'C':
			case 'c':
				mcm += "-.-.";
				break;
			case 'D':
			case 'd':
				mcm += "-..";
				break;
			case 'e':
			case 'E':
				mcm += ".";
				break;
			case 'F':
			case 'f':
				mcm += "..-.";
				break;
			case 'G':
			case 'g':
				mcm += "--.";
				break;
			case 'H':
			case 'h':
				mcm += "....";
				break;
			case 'I':
			case 'i':
				mcm += "..";
				break;
			case 'J':
			case 'j':
				mcm += ".---";
				break;
			case 'K':
			case 'k':
				mcm += "-.-";
				break;
			case 'L':
			case 'l':
				mcm += ".-..";
				break;
			case 'M':
			case 'm':
				mcm += "--";
				break;
			case 'N':
			case 'n':
				mcm += "-.";
				break;
			case 'O':
			case 'o':
				mcm += "---";
				break;
			case 'P':
			case 'p':
				mcm += ".--.";
				break;
			case 'Q':
			case 'q':
				mcm += "--.-";
				break;
			case 'R':
			case 'r':
				mcm += ".-.";
				break;
			case 'S':
			case 's':
				mcm += "...";
				break;
			case 'T':
			case 't':
				mcm += "-";
				break;
			case 'U':
			case 'u':
				mcm += "..-";
				break;
			case 'V':
			case 'v':
				mcm += "...-";
				break;
			case 'W':
			case 'w':
				mcm += ".--";
				break;
			case 'X':
			case 'x':
				mcm += "-..-";
				break;
			case 'Y':
			case 'y':
				mcm += "-.--";
				break;
			case 'Z':
			case 'z':
				mcm += "--..";
				break;
			case '.':
				mcm += ".-.-.-";
				break;
			case ',':
				mcm += "--..--";
				break;
			case '?':
				mcm += "..--..";
				break;
			case '!':
				mcm += "..--.";
				break;
			case '\'':
				mcm += ".----.";
				break;
			default:
				mcm += " ";
				break;
		}
	}
}

void morseCodeMessage::print(void){ //have to make redifinition
	cout <<  "Text: " << mess1 << endl; //prints text
	cout << "Morse Code: " << mcm << endl; //prints morse code
	return;
}

morseCodeMessage::morseCodeMessage(void){
	translate(); //calls translate when morseCodeMessage is initialized
}

morseCodeMessage::morseCodeMessage(string s) : message(s){  //sends string to message constructor
	translate(); //calls translate when morseCodeMessage is initialized with a given string
}

void messageStack::push(message* mess2){
	stack.push_back(mess2); //appends next message onto stack
	return;
}

message* messageStack::pop(void){
	//defines message to assign the popped message to
	message* mess3 = stack.back(); //assigns the last message to the string
	stack.pop_back(); //deletes the last message from the stack
	return mess3; //returns message
}

void messageStack::printStack(void){
	int len=0;
	len = stack.size(); //finds the size of the vector

	while(len>0){
		stack[len-1]->print(); //prints current element referenced by len
		--len; //decrements len to go to the next element
	}
}
