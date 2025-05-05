#include <string>

typedef unsigned int uint;

struct MyCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[11];
    char stringdata1[22];
    char stringdata2[1];
};

#define QT_MOC_LITERAL(ofs, len) \
uint(sizeof(MyCLASS_t::offsetsAndSizes) + ofs), len

constinit static const MyCLASS_t var = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(33, 0)   // ""
    },
    "MainWindow",
    "on_pushButton_clicked",
    ""
};


int main(int argc, char* argv[])
{
    var;
    int len1 = std::string( "MainWindow" ).length();
    int len2 = std::string( "on_pushButton_clicked" ).length();
    int off = sizeof( MyCLASS_t::offsetsAndSizes );
    return 0;
}
