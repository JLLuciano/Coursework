#ifndef STACKOFINT_H
#define STACKOFINT_H

class StackOfInt {
	class StackImp; // Class declaration only 
	StackImp* next;
public:
	void initialize();
	void cleanup();
	int read(int);
	void push(int);
	int size();
};
#endif // STACKOFINT_H ///:~ 