#pragma once
#include "PaymentRegistry.h"
#include "PaymentProcessors.h"
#include <memory>

// Registers all payment processors with the registry
inline void registerProcessors() {
    PaymentRegistry::instance().registerProcessor(
        PaymentMode::PayPal, std::make_unique<PayPalProcessor>());
    PaymentRegistry::instance().registerProcessor(
        PaymentMode::GooglePay, std::make_unique<GooglePayProcessor>());
    PaymentRegistry::instance().registerProcessor(
        PaymentMode::CreditCard, std::make_unique<CreditCardProcessor>());
}
