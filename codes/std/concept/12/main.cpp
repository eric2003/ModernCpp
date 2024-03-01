#include <concepts>
#include <string>

template <typename T>
concept Renderable =
requires(T Object){
  Object.Render();
  requires std::same_as<
    decltype(Object.hasRendered),
    bool>;
};

template <Renderable T>
void Render(T Object){ Object.Render(); }

class Tree {
public:
  bool hasRendered;
  void Render(){}
};

class Rock {
public:
  std::string hasRendered;
  void Render(){}
};

int main(int argc, char* argv[])
{
	Render(Tree{});
	Render(Rock{});
	return 0;
}
