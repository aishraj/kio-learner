#include "showHttp.h"
#include <kdebug.h>

showHttp::showHttp()
{
    output();
}

showHttp::~showHttp()
{}

void showHttp::output()
{
  KIO::SimpleJob *job;
  job = KIO::get(KUrl("http://download.services.openoffice.org/files/stable/3.3.0/OOo-SDK_3.3.0_Linux_x86-64_install-deb_en-US.tar.gz"));
  job->addMetaData("PropagateHttpHeader","true");
  job->setRedirectionHandlingEnabled(false);//In case this is set true of left to the defaults the URL is being redirected.
  connect (job, SIGNAL(  data(KIO::Job *, const QByteArray & )), this, SLOT(headerIsHere(KIO::Job *)));
}

void showHttp::headerIsHere(KIO::Job* metaJob)
{
  QString httpHeaders = metaJob->queryMetaData("HTTP-Headers");
  //QVariant httpVarient = metaJob->metaData().toVariant();
 // QString customHeaders = metaJob->queryMetaData("CustomHTTPHeader");
  qDebug() << "data is here";
  qDebug()<< httpHeaders;

  exit(0);

}
#include "showHttp.moc"
