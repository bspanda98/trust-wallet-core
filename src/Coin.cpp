// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Coin.h"

#include "Aion/Address.h"
#include "Bitcoin/Address.h"
#include "Bitcoin/Bech32Address.h"
#include "Bitcoin/CashAddress.h"
#include "Decred/Address.h"
#include "Ethereum/Address.h"
#include "Icon/Address.h"
#include "NEO/Address.h"
#include "Nimiq/Address.h"
#include "Ontology/Address.h"
#include "Ripple/Address.h"
#include "Stellar/Address.h"
#include "Tendermint/Address.h"
#include "Tezos/Address.h"
#include "Tron/Address.h"
#include "Wanchain/Address.h"
#include "Zcash/TAddress.h"

#include <TrustWalletCore/TWHRP.h>
#include <TrustWalletCore/TWP2PKHPrefix.h>
#include <TrustWalletCore/TWP2SHPrefix.h>

#pragma clang diagnostic push
#pragma clang diagnostic fatal "-Wswitch"

using namespace TW;

std::string TW::loadAddress(TWCoinType coin, const Data& data) {
    switch (coin) {
    case TWCoinTypeAion:
        return Aion::Address(data).string();

    case TWCoinTypeBinance:
        return Tendermint::Address(HRP_BINANCE, data).string();
    case TWCoinTypeCosmos:
        return Tendermint::Address(HRP_COSMOS, data).string();
    case TWCoinTypeBitcoin:
        return Bitcoin::Bech32Address(HRP_BITCOIN, 0, data).string();

    case TWCoinTypeBitcoinCash:
        return Bitcoin::CashAddress(data).string();

    case TWCoinTypeCallisto:
    case TWCoinTypeEthereum:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeGo:
    case TWCoinTypePoa:
    case TWCoinTypeThunderToken:
    case TWCoinTypeTomoChain:
    case TWCoinTypeVeChain:
    case TWCoinTypeXDai:
    case TWCoinTypeTheta:
        return Ethereum::Address(data).string();
    case TWCoinTypeWanChain:
        return Wanchain::Address(data).string();
    case TWCoinTypeICON:
        return Icon::Address(data, TWIconAddressTypeAddress).string();

    case TWCoinTypeLitecoin:
        return Bitcoin::Bech32Address(HRP_LITECOIN, 0, data).string();

    case TWCoinTypeOntology:
        return Ontology::Address(data).string();

    case TWCoinTypeNimiq:
        return Nimiq::Address(data).string();

    case TWCoinTypeRipple:
        return Ripple::Address(data).string();

    case TWCoinTypeTron:
        return Tron::Address(data).string();

    case TWCoinTypeDash:
    case TWCoinTypeZcoin:
        return Bitcoin::Address(data).string();

    case TWCoinTypeZcash:
        return Zcash::TAddress(data).string();

    case TWCoinTypeTezos:
        return Tezos::Address(data).string();
    case TWCoinTypeNEO:
        return NEO::Address(data).string();

    case TWCoinTypeDecred:
    case TWCoinTypeKIN:
    case TWCoinTypeStellar:
        return "";
    }
}

bool TW::validateAddress(TWCoinType coin, const std::string& string) {
    switch (coin) {
    case TWCoinTypeAion:
        return Aion::Address::isValid(string);

    case TWCoinTypeBinance:
        return Tendermint::Address::isValid(string, HRP_BINANCE) ||
               Tendermint::Address::isValid(string, HRP_BINANCE_TEST);

    case TWCoinTypeBitcoin:
        return Bitcoin::Bech32Address::isValid(string, HRP_BITCOIN) ||
               Bitcoin::Address::isValid(string, {TWP2PKHPrefixBitcoin, TWP2SHPrefixBitcoin});

    case TWCoinTypeBitcoinCash:
        return Bitcoin::CashAddress::isValid(string) ||
               Bitcoin::Address::isValid(string, {TWP2PKHPrefixBitcoin, TWP2SHPrefixBitcoin});

    case TWCoinTypeCosmos:
        return Tendermint::Address::isValid(string, HRP_COSMOS);

    case TWCoinTypeDash:
        return Bitcoin::Address::isValid(string, {TWP2PKHPrefixDash, TWP2SHPrefixDash});

    case TWCoinTypeDecred:
        return Decred::Address::isValid(string);

    case TWCoinTypeCallisto:
    case TWCoinTypeEthereum:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeGo:
    case TWCoinTypePoa:
    case TWCoinTypeThunderToken:
    case TWCoinTypeTomoChain:
    case TWCoinTypeVeChain:
    case TWCoinTypeXDai:
    case TWCoinTypeTheta:
        return Ethereum::Address::isValid(string);
    case TWCoinTypeWanChain:
        return Wanchain::Address::isValid(string);
    case TWCoinTypeICON:
        return Icon::Address::isValid(string);

    case TWCoinTypeLitecoin:
        return Bitcoin::Bech32Address::isValid(string, HRP_LITECOIN) ||
               Bitcoin::Address::isValid(string, {TWP2PKHPrefixLitecoin, TWP2SHPrefixLitecoin});

    case TWCoinTypeOntology:
        return Ontology::Address::isValid(string);

    case TWCoinTypeNimiq:
        return Nimiq::Address::isValid(string);

    case TWCoinTypeRipple:
        return Ripple::Address::isValid(string);

    case TWCoinTypeStellar:
    case TWCoinTypeKIN:
        return Stellar::Address::isValid(string);

    case TWCoinTypeTezos:
        return Tezos::Address::isValid(string);

    case TWCoinTypeTron:
        return Tron::Address::isValid(string);

    case TWCoinTypeZcoin:
        return Bitcoin::Address::isValid(string, {TWP2PKHPrefixZcoin, TWP2SHPrefixZcoin});

    case TWCoinTypeZcash:
        return Zcash::TAddress::isValid(string, {TWP2PKHPrefixZcashT, TWP2SHPrefixZcashT});

    case TWCoinTypeNEO:
        return NEO::Address::isValid(string);
    }
}

TWPurpose TW::purpose(TWCoinType coin) {
    switch (coin) {
    case TWCoinTypeAion:
    case TWCoinTypeBinance:
    case TWCoinTypeBitcoinCash:
    case TWCoinTypeCallisto:
    case TWCoinTypeCosmos:
    case TWCoinTypeDash:
    case TWCoinTypeDecred:
    case TWCoinTypeEthereum:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeGo:
    case TWCoinTypeICON:
    case TWCoinTypeNimiq:
    case TWCoinTypeOntology:
    case TWCoinTypePoa:
    case TWCoinTypeRipple:
    case TWCoinTypeStellar:
    case TWCoinTypeTezos:
    case TWCoinTypeThunderToken:
    case TWCoinTypeTomoChain:
    case TWCoinTypeTron:
    case TWCoinTypeVeChain:
    case TWCoinTypeWanChain:
    case TWCoinTypeXDai:
    case TWCoinTypeZcash:
    case TWCoinTypeZcoin:
    case TWCoinTypeNEO:
    case TWCoinTypeKIN:
    case TWCoinTypeTheta:
        return TWPurposeBIP44;
    case TWCoinTypeBitcoin:
    case TWCoinTypeLitecoin:
        return TWPurposeBIP84;
    }
}

TWCurve TW::curve(TWCoinType coin) {
    switch (coin) {
    case TWCoinTypeBinance:
    case TWCoinTypeBitcoin:
    case TWCoinTypeBitcoinCash:
    case TWCoinTypeCallisto:
    case TWCoinTypeDash:
    case TWCoinTypeDecred:
    case TWCoinTypeEthereum:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeGo:
    case TWCoinTypeICON:
    case TWCoinTypeLitecoin:
    case TWCoinTypePoa:
    case TWCoinTypeRipple:
    case TWCoinTypeThunderToken:
    case TWCoinTypeTomoChain:
    case TWCoinTypeTron:
    case TWCoinTypeVeChain:
    case TWCoinTypeWanChain:
    case TWCoinTypeXDai:
    case TWCoinTypeZcash:
    case TWCoinTypeZcoin:
    case TWCoinTypeCosmos:
    case TWCoinTypeTheta:
        return TWCurveSECP256k1;

    case TWCoinTypeNEO:
        return TWCurveNIST256p1;

    case TWCoinTypeAion:
    case TWCoinTypeNimiq:
    case TWCoinTypeStellar:
    case TWCoinTypeTezos:
    case TWCoinTypeKIN:
        return TWCurveEd25519;

    case TWCoinTypeOntology:
        return TWCurveNIST256p1;
    }
}

TWHDVersion TW::xpubVersion(TWCoinType coin) {
    switch (coin) {
    case TWCoinTypeBitcoin:
    case TWCoinTypeLitecoin:
        return TWHDVersionZPUB;

    case TWCoinTypeBitcoinCash:
    case TWCoinTypeDash:
    case TWCoinTypeDecred:
    case TWCoinTypeZcash:
    case TWCoinTypeZcoin:
        return TWHDVersionXPUB;

    case TWCoinTypeAion:
    case TWCoinTypeBinance:
    case TWCoinTypeCosmos:
    case TWCoinTypeCallisto:
    case TWCoinTypeEthereum:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeGo:
    case TWCoinTypeICON:
    case TWCoinTypeNimiq:
    case TWCoinTypeOntology:
    case TWCoinTypePoa:
    case TWCoinTypeRipple:
    case TWCoinTypeStellar:
    case TWCoinTypeTezos:
    case TWCoinTypeThunderToken:
    case TWCoinTypeTomoChain:
    case TWCoinTypeTron:
    case TWCoinTypeVeChain:
    case TWCoinTypeWanChain:
    case TWCoinTypeXDai:
    case TWCoinTypeNEO:
    case TWCoinTypeKIN:
    case TWCoinTypeTheta:
        return TWHDVersionNone;
    }
}

TWHDVersion TW::xprvVersion(TWCoinType coin) {
    switch (coin) {
    case TWCoinTypeBitcoin:
    case TWCoinTypeLitecoin:
        return TWHDVersionZPRV;

    case TWCoinTypeBitcoinCash:
    case TWCoinTypeDash:
    case TWCoinTypeDecred:
    case TWCoinTypeZcash:
    case TWCoinTypeZcoin:
        return TWHDVersionXPRV;

    case TWCoinTypeAion:
    case TWCoinTypeBinance:
    case TWCoinTypeCosmos:
    case TWCoinTypeCallisto:
    case TWCoinTypeEthereum:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeGo:
    case TWCoinTypeICON:
    case TWCoinTypeNimiq:
    case TWCoinTypeOntology:
    case TWCoinTypePoa:
    case TWCoinTypeRipple:
    case TWCoinTypeStellar:
    case TWCoinTypeTezos:
    case TWCoinTypeThunderToken:
    case TWCoinTypeTomoChain:
    case TWCoinTypeTron:
    case TWCoinTypeVeChain:
    case TWCoinTypeWanChain:
    case TWCoinTypeXDai:
    case TWCoinTypeNEO:
    case TWCoinTypeKIN:
    case TWCoinTypeTheta:
        return TWHDVersionNone;
    }
}

DerivationPath TW::derivationPath(TWCoinType coin) {
    switch (coin) {
    case TWCoinTypeBinance:
    case TWCoinTypeBitcoin:
    case TWCoinTypeBitcoinCash:
    case TWCoinTypeCallisto:
    case TWCoinTypeCosmos:
    case TWCoinTypeDash:
    case TWCoinTypeDecred:
    case TWCoinTypeEthereum:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeGo:
    case TWCoinTypeICON:
    case TWCoinTypeLitecoin:
    case TWCoinTypeOntology:
    case TWCoinTypePoa:
    case TWCoinTypeRipple:
    case TWCoinTypeThunderToken:
    case TWCoinTypeTomoChain:
    case TWCoinTypeTron:
    case TWCoinTypeVeChain:
    case TWCoinTypeWanChain:
    case TWCoinTypeXDai:
    case TWCoinTypeZcash:
    case TWCoinTypeZcoin:
    case TWCoinTypeTheta:
        return DerivationPath(purpose(coin), coin, 0, 0, 0);
    case TWCoinTypeAion:
    case TWCoinTypeNEO:
        return DerivationPath{
            DerivationPathIndex(purpose(coin), true),
            DerivationPathIndex(coin, true),
            DerivationPathIndex(0, true),
            DerivationPathIndex(0, true),
            DerivationPathIndex(0, true),
        };
    case TWCoinTypeNimiq:
    case TWCoinTypeTezos:
        return DerivationPath{
            DerivationPathIndex(purpose(coin), true),
            DerivationPathIndex(coin, true),
            DerivationPathIndex(0, true),
            DerivationPathIndex(0, true),
        };

    case TWCoinTypeStellar:
    case TWCoinTypeKIN:
        return DerivationPath{
            DerivationPathIndex(purpose(coin), true),
            DerivationPathIndex(coin, true),
            DerivationPathIndex(0, true)
        };
    }
}

PublicKeyType TW::publicKeyType(TWCoinType coin) {
    switch (coin) {
    case TWCoinTypeBinance:
    case TWCoinTypeBitcoin:
    case TWCoinTypeBitcoinCash:
    case TWCoinTypeCosmos:
    case TWCoinTypeDash:
    case TWCoinTypeDecred:
    case TWCoinTypeLitecoin:
    case TWCoinTypeZcash:
    case TWCoinTypeZcoin:
    case TWCoinTypeRipple:
        return PublicKeyType::secp256k1;

    case TWCoinTypeCallisto:
    case TWCoinTypeEthereum:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeGo:
    case TWCoinTypePoa:
    case TWCoinTypeThunderToken:
    case TWCoinTypeTomoChain:
    case TWCoinTypeVeChain:
    case TWCoinTypeWanChain:
    case TWCoinTypeXDai:
    case TWCoinTypeICON:
    case TWCoinTypeTron:
    case TWCoinTypeTheta:
        return PublicKeyType::secp256k1Extended;

    case TWCoinTypeNEO:
    case TWCoinTypeOntology:
        return PublicKeyType::nist256p1;

    case TWCoinTypeAion:
    case TWCoinTypeKIN:
    case TWCoinTypeNimiq:
    case TWCoinTypeStellar:
    case TWCoinTypeTezos:
        return PublicKeyType::ed25519;
    }
}

std::string TW::deriveAddress(TWCoinType coin, const PrivateKey& privateKey) {
    auto keyType = TW::publicKeyType(coin);
    return TW::deriveAddress(coin, privateKey.getPublicKey(keyType));
}

std::string TW::deriveAddress(TWCoinType coin, const PublicKey& publicKey) {
    switch (coin) {
    case TWCoinTypeBinance:
        return Tendermint::Address(HRP_BINANCE_TEST, publicKey).string();

    case TWCoinTypeCosmos:
        return Tendermint::Address(HRP_COSMOS, publicKey).string();

    case TWCoinTypeBitcoin:
        return Bitcoin::Bech32Address(publicKey, 0, HRP_BITCOIN).string();

    case TWCoinTypeBitcoinCash:
        return Bitcoin::CashAddress(publicKey).string();

    case TWCoinTypeDash:
        return Bitcoin::Address(publicKey, TWP2PKHPrefixDash).string();

    case TWCoinTypeDecred:
        return Decred::Address(publicKey).string();

    case TWCoinTypeCallisto:
    case TWCoinTypeEthereum:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeGo:
    case TWCoinTypePoa:
    case TWCoinTypeThunderToken:
    case TWCoinTypeTomoChain:
    case TWCoinTypeVeChain:
    case TWCoinTypeXDai:
    case TWCoinTypeTheta:
        return Ethereum::Address(publicKey).string();
    case TWCoinTypeWanChain:
        return Wanchain::Address(publicKey).string();
    case TWCoinTypeICON:
        return Icon::Address(publicKey, TWIconAddressTypeAddress).string();

    case TWCoinTypeLitecoin:
        return Bitcoin::Bech32Address(publicKey, 0, HRP_LITECOIN).string();
    case TWCoinTypeOntology:
        return Ontology::Address(publicKey).string();
    case TWCoinTypeNimiq:
        return Nimiq::Address(publicKey).string();

    case TWCoinTypeAion:
        return Aion::Address(publicKey).string();

    case TWCoinTypeRipple:
        return Ripple::Address(publicKey).string();

    case TWCoinTypeTezos:
        return Tezos::Address(publicKey).string();

    case TWCoinTypeTron:
        return Tron::Address(publicKey).string();

    case TWCoinTypeZcash:
        return Zcash::TAddress(publicKey, TWP2PKHPrefixZcashT).string();

    case TWCoinTypeZcoin:
        return Bitcoin::Address(publicKey, TWP2PKHPrefixZcoin).string();

    case TWCoinTypeStellar:
    case TWCoinTypeKIN:
        return Stellar::Address(publicKey).string();

    case TWCoinTypeNEO:
        return NEO::Address(publicKey).string();
    }
}

#pragma clang diagnostic pop
