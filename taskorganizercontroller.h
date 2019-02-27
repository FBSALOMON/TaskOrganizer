#ifndef TASKORGANIZERCONTROLLER_H
#define TASKORGANIZERCONTROLLER_H

#include <taskorganizer.h>

#include <QObject>

class TaskOrganizerController : public QObject
{
    Q_OBJECT
public:
    explicit TaskOrganizerController(TaskOrganizer *taskOrganizer, QObject *parent = nullptr);

    TaskOrganizerEntry * createEntry();
    bool deleteEntry (TaskOrganizerEntry * entry);


signals:

public slots:

private:

    TaskOrganizer * m_taskOrganizer;

};

#endif // TASKORGANIZERCONTROLLER_H
