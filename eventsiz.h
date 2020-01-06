#ifndef EVENTSIZ_H
#define EVENTSIZ_H

#include <QObject>
#include <QDate>

class EventSiz
{
public:
    EventSiz();
    void setId(int id);
    void setNumber(QString number);
    void setType(QString number);
    int getId() const;
    QString getNumber() const;
    QString getType() const;
private:
    int id;
    QString number;
    QString type;
    QString object;
    QString sotrudnik;
    QDate verivicationEnd;
    QDate inspection;
    int typeEvent;

};

#endif // EVENTSIZ_H
