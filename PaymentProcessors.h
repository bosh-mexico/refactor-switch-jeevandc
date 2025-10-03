#pragma once
#include "IPaymentProcessor.h"
#include <string>

// PayPal Processor
class PayPalProcessor : public IPaymentProcessor {
public:
    std::string process(double amount) const override {
        return "Processing PayPal payment of $" + std::to_string(amount);
    }
};

// GooglePay Processor
class GooglePayProcessor : public IPaymentProcessor {
public:
    std::string process(double amount) const override {
        return "Processing GooglePay payment of $" + std::to_string(amount);
    }
};

// CreditCard Processor
class CreditCardProcessor : public IPaymentProcessor {
public:
    std::string process(double amount) const override {
        return "Processing Credit Card payment of $" + std::to_string(amount);
    }
};
