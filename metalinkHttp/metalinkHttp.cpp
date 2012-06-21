/*
Copyright 2012  Aish Raj Dahal < dahalaishraj at gmail.com >

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
#include <QtCore/QString>

metalinkHttp::metalinkHttp(const KUrl& Url)
    : m_Url(Url),
      m_MetalinkHSatus(false)

{
    checkMetalinkHttp();
}

metalinkHttp::~metalinkHttp()
{

}

void metalinkHttp::checkMetalinkHttp()
{

    KIO::SimpleJob *job;
    job = KIO::get(m_Url);
    job->addMetaData("PropagateHttpHeader", "true");
    job->setRedirectionHandlingEnabled(false);
    connect(job, SIGNAL(result(KJob*)), this, SLOT(slotHeaderResult(KJob*)));
    qDebug() << " Verifying Metalink/HTTP Status" ;
    m_loop.exec();

}

void metalinkHttp::slotHeaderResult(KJob* kjob)
{
    KIO::Job* job = qobject_cast<KIO::Job*>(kjob);
    const QString httpHeaders = job ? job->queryMetaData("HTTP-Headers") : QString();
    parseHeaders(httpHeaders);
    setMetalinkHSatus();
    m_loop.exit();

}

bool metalinkHttp::isMetalinkHttp()
{
    QList<QString> linkList = m_headerInfo.values("link");
    foreach( QString link, linkList) {
        qDebug() << link ;
    }

    return m_MetalinkHSatus;
}

void metalinkHttp::parseHeaders(const QString &httpHeader)
{
    QString trimedHeader = httpHeader.mid(httpHeader.indexOf('\n') + 1).trimmed();

    foreach(QString line, trimedHeader.split('\n')) {
        int colon = line.indexOf(':');
        QString headerName = line.left(colon).trimmed();
        QString headerValue = line.mid(colon + 1).trimmed();
        int lessthan_pos = line.indexOf('<');
        if (lessthan_pos >= 0) {
            headerValue = line.mid(lessthan_pos + 1).trimmed();
        }
        m_headerInfo.insertMulti(headerName, headerValue);
    }
}

void metalinkHttp::setMetalinkHSatus()
{
    bool linkStatus, digestStatus;
    linkStatus = digestStatus = false;
    if (m_headerInfo.contains("link")) {
        QList<QString> linkValues = m_headerInfo.values("link");

        foreach(QString linkVal, linkValues) {
            if (linkVal.contains("rel=duplicate")) {
                linkStatus = true;
                break;
            }
        }
    }

    if (m_headerInfo.contains("digest")) {
        QList<QString> digestValues = m_headerInfo.values("digest");

        foreach(QString digestVal, digestValues) {
            if (digestVal.contains("sha-256", Qt::CaseInsensitive)) {
                digestStatus = true;
                break;
            }
        }
    }

    if ((linkStatus) && (digestStatus)) {
        m_MetalinkHSatus = true;
    }

}

#include "metalinkHttp.moc"
