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
  //job = KIO::get(KUrl("http://download.services.openoffice.org/files/stable/3.3.0/OOo-SDK_3.3.0_Linux_x86-64_install-deb_en-US.tar.gz"));
  job = KIO::get(KUrl("http://download.services.openoffice.org/files/du.list"));
  job->addMetaData("PropagateHttpHeader","true");
  job->setRedirectionHandlingEnabled(false);//In case this is set true of left to the defaults the URL is being redirected.
  //connect (job, SIGNAL(  mimetype(KIO::Job *, const QString & )), this, SLOT(headerIsHere(KIO::Job *)));
  connect(job,SIGNAL(result(KJob*)),this,SLOT(headerIsHere(KJob*)));
}

void showHttp::headerIsHere(KJob* metaJob)
{
  KIO::Job* headerJob = (KIO::Job *) metaJob;
  QString httpHeaders = headerJob->queryMetaData("HTTP-Headers");
  //QVariant httpVarient = metaJob->metaData().toVariant();
  //QString customHeaders = metaJob->queryMetaData("CustomHTTPHeader");
  qDebug() << "data is here";
  qDebug()<< httpHeaders;

  exit(0);

}
#include "showHttp.moc"
