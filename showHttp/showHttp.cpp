/*
Copyright 2012  Aish Raj Dahal dahalaishraj@gmail.com

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
#include "showHttp.h"
#include <kdebug.h>

showHttp::showHttp()
{
  output();
}

showHttp::~showHttp()
{
}

void showHttp::output()
{
  KIO::SimpleJob *job;
  //job = KIO::get(KUrl("http://download.services.openoffice.org/files/stable/3.3.0/OOo-SDK_3.3.0_Linux_x86-64_install-deb_en-US.tar.gz"));
  job = KIO::get(KUrl("http://download.services.openoffice.org/files/du.list"));
  job->addMetaData("PropagateHttpHeader","true");
  job->setRedirectionHandlingEnabled(false);//In case this is set true of left to the defaults the URL is being redirected.
  connect(job, SIGNAL(result(KJob*)), this, SLOT(slotResult(KJob*)));
}

void showHttp::slotResult(KJob* kjob)
{
  KIO::Job* job = qobject_cast<KIO::Job*>(kjob);
  const QString httpHeaders = job ? job->queryMetaData("HTTP-Headers") : QString();
  //qDebug() << "HTTP HEADERS:" << httpHeaders;
  parseHeaders(httpHeaders);
}

void showHttp::parseHeaders(const QString& httpHeader)
{
  QString trimedHeader = httpHeader.mid(httpHeader.indexOf('\n') + 1).trimmed();
  
  foreach (QString line, trimedHeader.split('\n')) {
    int colon = line.indexOf(':');
    QString headerName = line.left(colon).trimmed();
    QString headerValue = line.mid(colon + 1).trimmed();  
    m_headerInfo.insertMulti(headerName,headerValue);
  }
  
  //Testing code
  
  QList<QString> mirror_values = m_headerInfo.values("link");
  QList<QString> digest_values = m_headerInfo.values("digest");
  qDebug() << "The miror values are";
  for ( int i = 0; i < mirror_values.size(); i++) {
    qDebug() << mirror_values.at(i);
  }
  qDebug() << "The hashes are" ;
  foreach ( QString digest_val, digest_values) {
    qDebug() << digest_val ;
  }
  exit(0);
}

#include "showHttp.moc"
