#include <concepts>

int main(int argc, char* argv[])
{
    std::same_as<int, const int> same_as_test; // 编译错误，const int和int不是完全相同的类型
    std::is_same<int, const int> is_same_test; // 编译通过，int和const int是相同的类型
	return 0;
}
