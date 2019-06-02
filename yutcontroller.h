#ifndef YUTCONTROLLER_H
#define YUTCONTROLLER_H

#include <QObject>

class YutController : public QObject
{
    Q_OBJECT
public:
    explicit YutController(QObject *parent = nullptr);

signals:

public slots:
};

#endif // YUTCONTROLLER_H
