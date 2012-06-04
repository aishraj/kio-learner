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
  qDebug() << "HTTP HEADERS:" << httpHeaders;
}

#include "showHttp.moc"
