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

#include "metalinkHttp.h"
#include <kdebug.h>

metalinkHttp::metalinkHttp(const KUrl& Url)
  : m_MetalinkHSatus(false),
   m_Url(Url)
{
  
}

metalinkHttp::~metalinkHttp()
{

}

bool metalinkHttp::isMetalinkHttp()
{

  KIO::SimpleJob *job;
  //job = KIO::get(KUrl("http://download.services.openoffice.org/files/du.list"));
  job = KIO::get(m_Url);
  job->addMetaData("PropagateHttpHeader","true");
  job->setRedirectionHandlingEnabled(false);//In case this is set true of left to the defaults the URL is being redirected.
  connect(job, SIGNAL(result(KJob*)), this, SLOT(slotResult(KJob*)));
  return m_MetalinkHSatus;
}

void metalinkHttp::slotHeaderResult(KJob* kjob)
{
  KIO::Job* job = qobject_cast<KIO::Job*>(kjob);
  const QString httpHeaders = job ? job->queryMetaData("HTTP-Headers") : QString();
  qDebug() << "HTTP HEADERS:" << httpHeaders;
  m_MetalinkHSatus = true;
  
}

#include "metalinkHttp.moc"