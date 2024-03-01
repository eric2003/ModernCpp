export module importable;
import <iostream>;

export int from_import()
{
    std::cout << "hello from_import!" << std::endl;
    return 0;
}
