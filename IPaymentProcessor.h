#pragma once
#include <string>

class IPaymentProcessor {
public:
    virtual ~IPaymentProcessor() = default;
    virtual std::string process(double amount) const = 0;
};
