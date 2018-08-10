#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThreadPool>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

signals:

public slots:

private:
    QThreadPool *workersPool;
};

#endif // CONTROLLER_H
