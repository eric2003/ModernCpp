#include <concepts>

template <typename T>
concept Renderable = requires(T Object){
  { Object.Render() } -> std::same_as<int>;
};

template <Renderable T>
void Render(T Object){ Object.Render(); }

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
	Render(Tree{});
	Render(Rock{});
	return 0;
}
