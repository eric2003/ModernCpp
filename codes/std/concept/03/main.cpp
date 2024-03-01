#include <concepts>

class Player {};
class Monster {};
class Goblin : public Monster {};

template <typename T>
  requires std::is_base_of_v<Player, T> ||
           std::is_base_of_v<Monster, T>
void Function(T Character) {}

int main(int argc, char* argv[])
{
	Function(Goblin{});
	return 0;
}
