#include <QApplication>
#include "mapEditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapEditor editor;
    editor.show();
    return a.exec();
}