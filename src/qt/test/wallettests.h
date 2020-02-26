#ifndef ADULTCHAIN_QT_TEST_WALLETTESTS_H
#define ADULTCHAIN_QT_TEST_WALLETTESTS_H

#include <QObject>
#include <QTest>

class WalletTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void walletTests();
};

#endif // ADULTCHAIN_QT_TEST_WALLETTESTS_H
