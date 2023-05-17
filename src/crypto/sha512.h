// Copyright (c) 2014-2022 The Monacoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MONACOIN_CRYPTO_SHA512_H
#define MONACOIN_CRYPTO_SHA512_H

#include <cstdlib>
#include <stdint.h>

/** A hasher class for SHA-512. */
class CSHA512
{
private:
    uint64_t s[8];
    unsigned char buf[128];
    uint64_t bytes{0};

public:
    static constexpr size_t OUTPUT_SIZE = 64;

    CSHA512();
    CSHA512& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    CSHA512& Reset();
    uint64_t Size() const { return bytes; }
};

#endif // MONACOIN_CRYPTO_SHA512_H
