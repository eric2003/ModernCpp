//https://learn.microsoft.com/en-us/cpp/cpp/rvalue-reference-declarator-amp-amp?view=msvc-170
// reference-overload.cpp
// Compile with: /EHsc
#include <iostream>

// A class that contains a memory resource.
class MemoryBlock
{
   // TODO: Add resources for the class here.
};

void f(const MemoryBlock&)
{
   std::cout << "In f(const MemoryBlock&). This version can't modify the parameter." << std::endl;
}

void f(MemoryBlock&&)
{
   std::cout << "In f(MemoryBlock&&). This version can modify the parameter." << std::endl;
}

int main(int argc, char* argv[])
{
	MemoryBlock block;
	f(block);
	f(MemoryBlock());
	
	return 0;
}
