//: C05:Handle.h
// Handle classes 
#ifndef HANDLE_H 
#define HANDLE_H 

class Handle {
	struct Cheshire; // Class declaration only 
	Cheshire* smile;
public:
	//void initialize();
	Handle();//constructor will replace initialize()
	//void cleanup();
	int read();
	void change(int); 
	~Handle(); //at the end of scope the desctructor will automatically be called.
};
#endif // HANDLE_H ///:~ 