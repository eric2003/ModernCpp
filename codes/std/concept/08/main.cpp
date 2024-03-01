#include <concepts>

template <typename T>
concept Renderable = requires(T Object){
  Object.Render();
} || requires(T Object){
  Object.Draw();
};

template <Renderable T>
void Render(T Object){ Object.Render(); }

template <Renderable T>
void Draw(T Object){ Object.Draw(); }

class Tree {
public:
  void Render(){}
};

class Rock {
public:
  void Draw(){}
};

int main(int argc, char* argv[])
{
	Render(Tree{});
	Draw(Rock{});
	return 0;
}
