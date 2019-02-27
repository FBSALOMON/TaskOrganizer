#include "taskorganizerentry.h"

TaskOrganizerEntry::TaskOrganizerEntry(QObject *parent) : QObject(parent)
{

}

QString TaskOrganizerEntry::name() const
{
    return m_name;
}

void TaskOrganizerEntry::setName(const QString &name)
{
    if(m_name != name) {
        m_name = name;
        emit nameChanged();
    }

}

QString TaskOrganizerEntry::email() const
{
    return m_email;
}

void TaskOrganizerEntry::setEmail(const QString &email)
{
    if(m_email != email) {
        m_email = email;
        emit emailChanged();
    }
}

QString TaskOrganizerEntry::exam() const
{
    return m_exam;
}

void TaskOrganizerEntry::setExam(const QString &exam)
{
    if(m_exam != exam) {
        m_exam = exam;
        emit examChanged();
    }
}

QString TaskOrganizerEntry::phone() const
{
    return m_phone;
}

void TaskOrganizerEntry::setPhone(const QString &phone)
{
    if(m_phone != phone) {
        m_phone = phone;
        emit phoneChanged();
    }
}

QString TaskOrganizerEntry::status() const
{
    return m_status;
}

void TaskOrganizerEntry::setStatus(const QString &status)
{
    if(m_status != status) {
        m_status = status;
        emit statusChanged();
    }
}

bool TaskOrganizerEntry::CO() const
{
    return m_CO;
}

void TaskOrganizerEntry::setCO(bool CO)
{
    if(m_CO != CO) {
        m_CO = CO;
        emit COChanged();
    }
}

bool TaskOrganizerEntry::EO() const
{
    return m_EO;
}

void TaskOrganizerEntry::setEO(bool EO)
{
    if(m_EO != EO) {
        m_EO = EO;
        emit EOChanged();
    }
}

bool TaskOrganizerEntry::CE() const
{
    return m_CE;
}

void TaskOrganizerEntry::setCE(bool CE)
{
    if(m_CE != CE){
        m_CE = CE;
        emit CEChanged();
    }
}

bool TaskOrganizerEntry::EE() const
{
    return m_EE;
}

void TaskOrganizerEntry::setEE(bool EE)
{
    if(m_EE != EE){
        m_EE = EE;
        emit EEChanged();
    }
}

bool TaskOrganizerEntry::QCM() const
{
    return m_QCM;
}

void TaskOrganizerEntry::setQCM(bool QCM)
{
    if (m_QCM != QCM) {
        m_QCM = QCM;
        emit QCMChanged();
    }
}

QDate TaskOrganizerEntry::date() const
{
    return m_date;
}

void TaskOrganizerEntry::setDate(const QDate &date)
{
    if(m_date != date) {
        m_date = date;
        emit dateChanged();
    }
}
