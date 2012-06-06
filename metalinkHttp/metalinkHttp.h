#ifndef showHttp_H
#define showHttp_H

#include <QtCore/QObject>
#include <KIO/AccessManager>
#include <KIO/Job>
#include <KIO/SimpleJob>
#include <KIO/Scheduler>

class showHttp : public QObject
{

    Q_OBJECT
public:
    showHttp();
    virtual ~showHttp();

public slots:
    void slotResult(KJob* kjob);
    void output();
};

#endif // showHttp_H
