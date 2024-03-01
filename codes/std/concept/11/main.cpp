//#include <concepts>

template <typename ArgType>
class Object {
public:
  void Render(ArgType Arg){}
};

template <typename T, typename ArgType>
void Render(T Object, ArgType Arg){
  Object.Render(Arg);
}

int main(int argc, char* argv[])
{
	Object<int> MyObject;
	Render(MyObject, 5);
	return 0;
}
