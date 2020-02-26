// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ADULTCHAIN_SCRIPT_ADULTCHAINCONSENSUS_H
#define ADULTCHAIN_SCRIPT_ADULTCHAINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_ADULTCHAIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/adultchain-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBADULTCHAINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define ADULTCHAINCONSENSUS_API_VER 1

typedef enum adultchainconsensus_error_t
{
    adultchainconsensus_ERR_OK = 0,
    adultchainconsensus_ERR_TX_INDEX,
    adultchainconsensus_ERR_TX_SIZE_MISMATCH,
    adultchainconsensus_ERR_TX_DESERIALIZE,
    adultchainconsensus_ERR_AMOUNT_REQUIRED,
    adultchainconsensus_ERR_INVALID_FLAGS,
} adultchainconsensus_error;

/** Script verification flags */
enum
{
    adultchainconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    adultchainconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    adultchainconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    adultchainconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    adultchainconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    adultchainconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    adultchainconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    adultchainconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = adultchainconsensus_SCRIPT_FLAGS_VERIFY_P2SH | adultchainconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               adultchainconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | adultchainconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               adultchainconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | adultchainconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int adultchainconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, adultchainconsensus_error* err);

EXPORT_SYMBOL int adultchainconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, adultchainconsensus_error* err);

EXPORT_SYMBOL unsigned int adultchainconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // ADULTCHAIN_SCRIPT_ADULTCHAINCONSENSUS_H
