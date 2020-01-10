#ifndef UIDEFINE_H
#define UIDEFINE_H

enum MainSizModelHead
{ id=0,
    number,
    verificationDate,
    endVerificationDate,
    inspectionDate,
    nameSiz,
    object,
    personalDate,
    persona,
    note,
    bool_removed,
    bool_verification,
    verifiPediod,
    inspectPediod,
    personalyty,
    event,
    daysToEvent
};
enum SizEvent{
    noEvent=0,
    verificationExpired,
    inspectionExpired,
    verificationSoon,
    inspectionSoon,
    serviceLifeExpired
};

#define VERIFICATION_EXPIRED_COLOR  QColor( 255,0,0,70)
#define INSPECTION_EXPIRED_COLOR    QColor( 255,99,71,70)
#define VERIFICATION_SOON_COLOR     QColor(0,206,209,40)
#define INSPECTION_SOON_COLOR       QColor(50,205,50,40)
#define SERVICELIFE_EXPIRED_COLOR   QColor( 255,0,0,70)

#endif // UIDEFINE_H
