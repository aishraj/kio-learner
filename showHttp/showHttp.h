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
#ifndef showHttp_H
#define showHttp_H

#include <QtCore/QObject>
#include <KIO/AccessManager>
#include <KIO/Job>
#include <KIO/SimpleJob>
#include <KIO/Scheduler>
#include <QtCore/QMultiMap>

class showHttp : public QObject
{

    Q_OBJECT
public:
    showHttp();
    virtual ~showHttp();

public slots:
    void slotResult(KJob* kjob);
    void output();

private:
    QMultiMap<QString, QString> m_headerInfo;
    void parseHeaders(const QString&);
};

#endif // showHttp_H
