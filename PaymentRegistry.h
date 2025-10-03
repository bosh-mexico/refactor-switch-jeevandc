#pragma once
#include "IPaymentProcessor.h"
#include "PaymentModes.h"
#include <map>
#include <memory>

class PaymentRegistry {
public:
    static PaymentRegistry& instance() {
        static PaymentRegistry registry;
        return registry;
    }

    void registerProcessor(PaymentMode mode, std::unique_ptr<IPaymentProcessor> processor) {
        processors[mode] = std::move(processor);
    }

    const IPaymentProcessor* getProcessor(PaymentMode mode) const {
        auto it = processors.find(mode);
        if (it != processors.end()) return it->second.get();
        return nullptr;
    }

private:
    std::map<PaymentMode, std::unique_ptr<IPaymentProcessor>> processors;
};
