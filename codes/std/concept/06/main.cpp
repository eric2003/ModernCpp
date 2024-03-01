template <typename T>
concept Renderable =
requires(T Object){
  Object.Render();
  Object.hasRendered;
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
  void Render(){}
};

int main(int argc, char* argv[])
{
    Render(Tree{});
    Render(Rock{});
	return 0;
}
