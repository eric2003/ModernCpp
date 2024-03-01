//#include <concepts>
#include <string>

template <typename T, typename ArgType>
concept Renderable = requires(
  T Object, ArgType Arg
){
  Object.Render(Arg);
};

class Tree {
public:
  int Render(){ return 42; };
};

class Rock {
public:
  float Render(){ return 3.14; };
};

int main(int argc, char* argv[])
{
    // Does Tree have a Render method that accepts an int?
    Renderable<Tree, int>;
    
    // Does Rock have a Render method that accepts a std::string?
    Renderable<Rock, std::string>;
	return 0;
}
