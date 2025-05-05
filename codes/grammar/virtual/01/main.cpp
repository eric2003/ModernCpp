struct FooInterface {
    [[nodiscard]] virtual auto func() const -> int = 0;
};

struct Foo final : public FooInterface {
    [[nodiscard]] auto func() const -> int override {
        return 42;
    }
};

int main()
{
    return 0;
}