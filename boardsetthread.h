#ifndef BOARDSETTHREAD_H
#define BOARDSETTHREAD_H

#include <QThread>

class BoardSetThread : public QThread
{
    Q_OBJECT
public:
    explicit BoardSetThread(QObject *parent = nullptr);

signals:
    void threadEnd();
    void updateEnableMal();

public slots:
    void malClicked();
    void boardButtonClicked();
    void updateQueue(bool isEmpty);
    void init();
    void restart();
private:
    void run();
    QObject* parent;
    bool check = true;
    bool isMalClicked = false;
    bool isBoardButtonClicked = false;
    bool isInit = true;

};

#endif // BOARDSETTHREAD_H
