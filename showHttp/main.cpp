#include <QCoreApplication>
#include <kapplication.h>
#include <kaboutdata.h>
#include <klocalizedstring.h>
#include <kcmdlineargs.h>

#include "showHttp.h"


int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    showHttp foo;
    return app.exec();
}
