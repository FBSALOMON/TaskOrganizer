#ifndef TASKORGANIZERENTRY_H
#define TASKORGANIZERENTRY_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QStringList>
#include <QVector>

class TaskOrganizerEntry : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString exam READ exam WRITE setExam NOTIFY examChanged)
    Q_PROPERTY(QDate date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(QString phone READ phone WRITE setPhone NOTIFY phoneChanged)
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)

public:
    explicit TaskOrganizerEntry(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    QString email() const;
    void setEmail(const QString &email);

    QString exam() const;
    void setExam(const QString &exam);

    QDate date() const;
    void setDate(const QDate &date);

    QString phone() const;
    void setPhone(const QString &phone);

    QString status() const;
    void setStatus(const QString &status);

    bool CO() const;
    void setCO(bool CO);

    bool EO() const;
    void setEO(bool EO);

    bool CE() const;
    void setCE(bool CE);

    bool EE() const;
    void setEE(bool EE);

    bool QCM() const;
    void setQCM(bool QCM);

signals:

    void nameChanged();
    void emailChanged();
    void examChanged();
    void dateChanged();
    void phoneChanged();
    void statusChanged();
    void COChanged();
    void EOChanged();
    void CEChanged();
    void EEChanged();
    void QCMChanged();

public slots:

private:

    QString m_name;
    QString m_email;
    QString m_exam;
    QDate m_date;
    QString m_phone;
    QString m_status;
    bool m_CO = false;
    bool m_EO = false;
    bool m_CE = false;
    bool m_EE = false;
    bool m_QCM = false;
};

#endif // TASKORGANIZERENTRY_H
