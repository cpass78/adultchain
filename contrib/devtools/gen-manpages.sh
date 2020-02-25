#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

ADULTCHAIND=${ADULTCHAIND:-$BINDIR/adultchaind}
ADULTCHAINCLI=${ADULTCHAINCLI:-$BINDIR/adultchain-cli}
ADULTCHAINTX=${ADULTCHAINTX:-$BINDIR/adultchain-tx}
ADULTCHAINQT=${ADULTCHAINQT:-$BINDIR/qt/adultchain-qt}

[ ! -x $ADULTCHAIND ] && echo "$ADULTCHAIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($ADULTCHAINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for adultchaind if --version-string is not set,
# but has different outcomes for adultchain-qt and adultchain-cli.
echo "[COPYRIGHT]" > footer.h2m
$ADULTCHAIND --version | sed -n '1!p' >> footer.h2m

for cmd in $ADULTCHAIND $ADULTCHAINCLI $ADULTCHAINTX $ADULTCHAINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
