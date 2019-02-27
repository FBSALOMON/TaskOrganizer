#include "taskorganizercontroller.h"

TaskOrganizerController::TaskOrganizerController(
        TaskOrganizer *taskOrganizer, QObject *parent) :
    QObject(parent),
    m_taskOrganizer (taskOrganizer)
{
    Q_ASSERT(taskOrganizer != nullptr);
}

TaskOrganizerEntry *TaskOrganizerController::createEntry()
{
    auto result = m_taskOrganizer->createEntry();
    if (result != nullptr) {
        result->setName(tr("New entry..."));
    }
    return result;
}

bool TaskOrganizerController::deleteEntry(TaskOrganizerEntry *entry)
{
    return m_taskOrganizer->deleteEntry(entry);
}
