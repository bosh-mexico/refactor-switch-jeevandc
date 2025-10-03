#include "PaymentModes.h"
#include <map>
#include <string>

// Refactored: Use a map for payment messages and logic
std::string checkout(PaymentMode mode, double amount) {
    static const std::map<PaymentMode, std::string> modeMessages = {
        {PaymentMode::PayPal,     "Processing PayPal payment of $"},
        {PaymentMode::GooglePay,  "Processing GooglePay payment of $"},
        {PaymentMode::CreditCard, "Processing Credit Card payment of $"}
    };

    auto it = modeMessages.find(mode);
    if (it != modeMessages.end()) {
        // Placeholder for future payment API integration
        return it->second + std::to_string(amount);
    }
    return "Invalid payment mode selected!";
}
