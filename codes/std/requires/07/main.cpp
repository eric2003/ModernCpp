// requiresClause.cpp

#include <iostream>

template <typename T>
void clever_swap(T& a, T& b)
{
  constexpr bool has_member_swap = requires(T a, T b){ 
    a.swap(b); 
  };
 
  if constexpr (has_member_swap) {
    a.swap(b);
  }
  else {
    using std::swap;
    swap(a, b);
  }
}

int main(int argc, char* argv[])
{
	int i = 1;
	int j = 2;
	std::cout << "i = " << i << " j = " << j << '\n';
	clever_swap(i,j);
	std::cout << "i = " << i << " j = " << j << '\n';

	return 0;
}
