import std;

int main() {
    auto trace = std::stacktrace::current();
    for ( auto && frame : trace ) { std::print( "{}\n", frame.description() ); }
    return 0;
}