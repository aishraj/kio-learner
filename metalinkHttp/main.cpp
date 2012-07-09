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
    //The following URLS are metalink. Should produce a yes response.
    //metalinkHttp foo(KUrl("http://download.services.openoffice.org/files/du.list"));
    metalinkHttp foo(KUrl("http://download.services.openoffice.org/files/stable/3.3.0/OOo-SDK_3.3.0_Linux_x86-64_install-deb_en-US.tar.gz"));
    //The following URLs are not metalink. Should produce a NO response.
    //metalinkHttp foo(KUrl("http://www.example.com"));//Not a metalink
    //metalinkHttp foo(KUrl("http://releng.archlinux.org/isos/2012.06.05_04-00-01/archlinux-2012.06.05_04-00-01-core-dual.iso"));
    //foo.checkMetalinkHttp();
    if (foo.isMetalinkHttp()) {
        qDebug() << "Yes it is metalinkHttp" ;
    } else {
        qDebug() << " No this is not metalinkHttp ";
    }
}
