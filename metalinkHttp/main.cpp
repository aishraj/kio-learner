/*
Copyright 2012  Aish Raj Dahal <dahalaishraj at gmail.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of
the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
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
    //metalinkHttp foo(KUrl("http://www.cs.princeton.edu/~rs/AlgsDS07/17GeometricSearch.pdf"));//Not a Metalink
    metalinkHttp foo(KUrl("http://openoffice.mirrorbrain.org/stable/3.3.0/OOo_3.3.0_Linux_x86-64_install-rpm-wJRE_en-US.tar.gz"));//Metalink
    //metalinkHttp foo(KUrl("http://www.kernel.org/pub/linux/kernel/v3.0/linux-3.4.4.tar.bz2"));//Not a metalink
    //foo.checkMetalinkHttp();
    if (foo.isMetalinkHttp()) {
        qDebug() << "Yes it is metalinkHttp" ;
    } else {
        qDebug() << " No this is not metalinkHttp ";
    }
    app.exit(0);
}
