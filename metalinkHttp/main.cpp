#include <QCoreApplication>
#include <kapplication.h>
#include <kaboutdata.h>
#include <klocalizedstring.h>
#include <kcmdlineargs.h>
#include <QtCore/QDebug>

#include "metalinkHttp.h"


int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    metalinkHttp foo(KUrl("http://download.services.openoffice.org/files/du.list"));
    if (foo.isMetalinkHttp()) {
      qDebug() << "Yes it is metalinkHttp" ;
    }
    else {
      qDebug() << " No this is not metalinkHttp ";
    }
}
