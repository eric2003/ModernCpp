#include <concepts>
#include <iostream>

class Object;
template <typename T>
concept Animatable =
  std::derived_from<T, Object> &&
  requires(T Object){
    Object.Render();
    Object.Animate();
  };

class Object {
public:
    virtual void Render(){ std::cout << "Render" << std::endl; };
	virtual void Animate(){ std::cout << "Animate" << std::endl; };
};
 
class A : public Object {};
 
class B : public A {};

template <Animatable T>
void Animate(T Object){ 
	Object.Render();
	Object.Animate();
}

int main(int argc, char* argv[])
{
	Animate(A{});
	Animate(B{});
	return 0;
}
