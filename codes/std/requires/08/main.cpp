// requiresClause.cpp

#include <iostream>

struct A
{
};

template <typename Iter>
struct S
{
  static_assert(requires(Iter i){ ++i; }, "no increment");
};

int main(int argc, char* argv[])
{
	S<int> s;
	//S<A> sa;

	return 0;
}
