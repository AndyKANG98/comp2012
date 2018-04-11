using namespace std;
const int STACK_CAPACITY = 64;

template <typename T>
class Stack {
public:
	Stack() {};
	~Stack() {};

	/****** START YOUR DELARATION FOR PART 1 HERE ******/

	// ACCESSOR member functions:
	bool empty() const;    // Check if the stack is empty
	bool full() const;	   // Check if the stack is full
	int size() const;	   // Give the number of data currently stored

	// TODO: Overload operator "~" to retrieve the top item from the stack
	T operator~ () const;
	// TODO: Overload operator "==" to check the equality of stack objects
	bool operator== (const Stack<T>&) const;
	// TODO: Overload operator "<<" to show the items stored in the stack object
	template <typename R>
	friend ostream& operator<< (ostream& , const Stack<R>&);

	// MUTATOR member functions:
	// TODO: Overload operator "+=" to add a new item to the top
	Stack<T>& operator+= (const T&);
	// TODO: Overload operator "--" to remove the top item from the stack
	//       and return the new top item (** SYNTAX: Stack<int> A; --stack; **)
	T operator-- ();

	// TODO: Overload operator "--" to return the top item and remove it
	//       from the stack (** SYNTAX: Stack<int> A; stack--; **)
	T operator-- (int);

	/******* END YOUR DELARATION FOR PART 1 HERE *******/

private:
	T data[STACK_CAPACITY];   // Use an array to store the data
	int top_index {-1};		    // Start from 0; -1 when empty
};

/****** START YOUR IMPLEMENTATION FOR PART 1 HERE ******/
template <typename T>
bool Stack<T>::empty() const{ return (top_index == -1); }

template <typename T>
bool Stack<T>::full() const{ return (top_index >= (STACK_CAPACITY - 1)); }

template <typename T>
int Stack<T>::size() const{ return (top_index + 1); }

template <typename T>
T Stack<T>::operator~ () const{
	if (!empty())
		return data[top_index];
	else{
		cerr << "[ERROR] Stack is empty, returning a garbage value" << endl;
		T garbage;
		return garbage;
	}
}

template <typename T>
bool Stack<T>::operator ==(const Stack<T>& S) const{
	if (this->size() != S.size()) return false;
	for (int i=0; i<=top_index; i++){
		if (data[i] != S.data[i]) return false;
	}
	return true;
}

template <typename T>
ostream& operator<< (ostream& os, const Stack<T>& S){
	for (int i=S.top_index; i>0; i--)
		os<< S.data[i] << endl;
	os<<S.data[0];
	return os;
}

template <typename T>
Stack<T>& Stack<T>::operator+= (const T& item){
	if (full()){
		cerr << "[ERROR] Stack is full, can't add new value" <<endl;
		return *this;
	}
	top_index++;
	data[top_index] = item;
	return *this;
}

template <typename T>
T Stack<T>::operator-- (){
	if (empty()) {
		cerr << "[ERROR] Stack is empty, returning a garbage value" << endl;
		T garbage;
		return garbage;
	}

	top_index--;
	return ~(*this);
}

template <typename T>
T Stack<T>::operator-- (int){
	if (empty()) {
		cerr << "[ERROR] Stack is empty, returning a garbage value" << endl;
		T garbage;
		return garbage;
	}
	T temp = data[top_index];
	top_index--;
	return temp;
}

/******* END YOUR IMPLEMENTATION FOR PART 1 HERE *******/
