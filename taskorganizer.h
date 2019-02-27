#ifndef TASKORGANIZER_H
#define TASKORGANIZER_H

#include <taskorganizerentry.h>

#include <QObject>
#include <QList>

class TaskOrganizer : public QObject
{
    Q_OBJECT
public:

    typedef QList<TaskOrganizerEntry*> Entries;

    explicit TaskOrganizer(QObject *parent = nullptr);

    Entries entries() const;

    TaskOrganizerEntry* createEntry();
    bool deleteEntry (TaskOrganizerEntry *entry);

signals:

    void entryAdded(TaskOrganizerEntry *entry);
    void entryRemoved(TaskOrganizerEntry *entry);

public slots:

private:
    Entries m_entries;
};

#endif // TASKORGANIZER_H
