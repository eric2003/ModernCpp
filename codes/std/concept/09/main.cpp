template <typename T>
concept Renderable =
requires(T Object, int Size){
  Object.Render(Size);
};

template <Renderable T>
void Render(T Object, int Size){
  Object.Render(Size);
}

class Tree {
public:
  void Render(int Size){}
};

class Rock {
public:
  void Render(){}
};

int main(int argc, char* argv[])
{
	Render(Tree{}, 42);
	Render(Rock{}, 42); 
	return 0;
}
