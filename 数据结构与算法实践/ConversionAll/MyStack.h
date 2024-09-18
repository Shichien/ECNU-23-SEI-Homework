/*
*  Projected By Deralive (10235101526), release on 08/03/2024
*/

#define Maxsize 100

//  Define enumeration variables as return values for subsequent functions
enum State {
    Lessstack,
    SuccessOperate,
    Overstack,
};

template <class T>
class MyStack {

public:

    MyStack(); // Constuctor Function
    void InitStack(); // Init The Stack To The Init State
    bool Empty() const; // Check the stack is empty or not, if so, return 1.

    State Stackpop(T &Out); //  Pop an element from the stack
    State Stackpush(const T &Item); //  Pushing a newly acquired element onto the stack
    State StackTop(T &Top); //  Output an element at the top of the stack to the user interface, but do not pop that element out of the stack
    
private:

    int cnt;
    T Stack[Maxsize];
    
};