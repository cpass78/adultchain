// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ADULTCHAIN_QT_ADULTCHAINADDRESSVALIDATOR_H
#define ADULTCHAIN_QT_ADULTCHAINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class AdultChainAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AdultChainAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Adultchain address widget validator, checks for a valid adultchain address.
 */
class AdultChainAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AdultChainAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // ADULTCHAIN_QT_ADULTCHAINADDRESSVALIDATOR_H
