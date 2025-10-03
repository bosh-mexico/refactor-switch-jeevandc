#include "PaymentModes.h"
#include "PaymentRegistry.h"
#include "PaymentProcessors.h"
#include "PaymentRegistration.h"
#include <iostream>
#include <string>
#include <vector>

// Helper for test
std::string get_payment_message(PaymentMode mode, double amount) {
    const IPaymentProcessor* processor = PaymentRegistry::instance().getProcessor(mode);
    if (processor) {
        return processor->process(amount);
    }
    return "Invalid payment mode selected!";
}

struct PaymentTestScenario {
    PaymentMode mode;
    double amount;
    std::string expected;
    std::string description;
};

void run_payment_tests() {
    std::vector<PaymentTestScenario> scenarios = {
                {
            PaymentMode::PayPal, 150.75,
            "Processing PayPal payment of $150.750000",
            "PayPal payment with valid amount"
        },
        {
            PaymentMode::GooglePay, 99.99,
            "Processing GooglePay payment of $99.990000",
            "GooglePay payment with valid amount"
        },
        {
            PaymentMode::CreditCard, 0.0,
            "Processing Credit Card payment of $0.000000",
            "CreditCard payment with zero amount"
        },
        {
            PaymentMode::PayPal, -10.0,
            "Processing PayPal payment of $-10.000000",
            "PayPal payment with negative amount"
        },
        {
            PaymentMode::GooglePay, 1e6,
            "Processing GooglePay payment of $1000000.000000",
            "GooglePay payment with large amount"
        },
        {
            PaymentMode::Unknown, 150.75,
            "Invalid payment mode selected!",
            "Unknown payment mode"
        },
        {
            PaymentMode::Unknown, 0.0,
            "Invalid payment mode selected!",
            "Unknown payment mode with zero amount"
        },
        {
            PaymentMode::Unknown, -5.0,
            "Invalid payment mode selected!",
            "Unknown payment mode with negative amount"
        }
    };

    for (const auto& scenario : scenarios) {
        std::string result = get_payment_message(scenario.mode, scenario.amount);
        std::cout << "Scenario: " << scenario.description << "\n"
                  << "  When checkout is called with amount " << scenario.amount << "\n"
                  << "  Then result should be: " << scenario.expected << "\n"
                  << "  Actual result: " << result << "\n"
                  << ((result == scenario.expected) ? "  [PASS]\n" : "  [FAIL]\n")
                  << std::endl;
    }
}

int main() {
    registerProcessors();
    run_payment_tests();
    return 0;
}
