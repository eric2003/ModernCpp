//https://learn.microsoft.com/en-us/cpp/cpp/rvalue-reference-declarator-amp-amp?view=msvc-170
// template-type-deduction.cpp
// Compile with: /EHsc
#include <iostream>
#include <string>

template<typename T> struct S;

// The following structures specialize S by
// lvalue reference (T&), const lvalue reference (const T&),
// rvalue reference (T&&), and const rvalue reference (const T&&).
// Each structure provides a print method that prints the type of
// the structure and its parameter.

template<typename T> struct S<T&> {
   static void print(T& t)
   {
      std::cout << "print<T&>: " << t << std::endl;
   }
};

template<typename T> struct S<const T&> {
   static void print(const T& t)
   {
      std::cout << "print<const T&>: " << t << std::endl;
   }
};

template<typename T> struct S<T&&> {
   static void print(T&& t)
   {
      std::cout << "print<T&&>: " << t << std::endl;
   }
};

template<typename T> struct S<const T&&> {
   static void print(const T&& t)
   {
      std::cout << "print<const T&&>: " << t << std::endl;
   }
};

// This function forwards its parameter to a specialized
// version of the S type.
template <typename T> void print_type_and_value(T&& t)
{
   S<T&&>::print(std::forward<T>(t));
}

// This function returns the constant string "fourth".
const std::string fourth() { return std::string("fourth"); }

int main(int argc, char* argv[])
{
	// The following call resolves to:
	// print_type_and_value<string&>(string& && t)
	// Which collapses to:
	// print_type_and_value<string&>(string& t)
	std::string s1("first");
	print_type_and_value(s1);
	
	// The following call resolves to:
	// print_type_and_value<const string&>(const string& && t)
	// Which collapses to:
	// print_type_and_value<const string&>(const string& t)
	const std::string s2("second");
	print_type_and_value(s2);
	
	// The following call resolves to:
	// print_type_and_value<string&&>(string&& t)
	print_type_and_value(std::string("third"));
	
	// The following call resolves to:
	// print_type_and_value<const string&&>(const string&& t)
	print_type_and_value(fourth());
	
	return 0;
}
