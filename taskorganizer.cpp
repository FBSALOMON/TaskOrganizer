#include "taskorganizer.h"

TaskOrganizer::TaskOrganizer(QObject *parent) : QObject(parent)
{

}

TaskOrganizer::Entries TaskOrganizer::entries() const
{
    return m_entries;
}

TaskOrganizerEntry *TaskOrganizer::createEntry()
{
    auto result = new TaskOrganizerEntry(this);
    if (result != nullptr) {
        m_entries.append(result);
        emit entryAdded(result);
    }
    return result;
}

bool TaskOrganizer::deleteEntry(TaskOrganizerEntry *entry)
{
    if (m_entries.contains(entry)) {
        emit entryRemoved(entry);
        m_entries.removeOne(entry);
        delete entry;
        return true;
    }
    return false;
}
