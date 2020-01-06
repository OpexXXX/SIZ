#include "eventsiz.h"

EventSiz::EventSiz()
{

}

void EventSiz::setId(int id)
{
    this->id = id;
}
void EventSiz::setNumber(QString number)
{
    this->number=number;
}
void EventSiz::setType(QString type)
{
    this->type=type;
}
int EventSiz::getId() const
{
    return this->id;
}
QString EventSiz::getNumber() const
{
     return this->number;
}
QString EventSiz::getType() const
{
    return this->type;
}
