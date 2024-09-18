enum Error_code{not_present, overflow, underflow, duplicate_error, success};

const int maxstack = 50;   //  small value for testing
template<class Stack_entry>
class MyStack {
public:
   MyStack();
   bool empty() const;
   Error_code pop();
   Error_code top(Stack_entry &item) const;
   Error_code push(const Stack_entry &item);
   int size() const;
private:
   int count;
   Stack_entry entry[maxstack];
};