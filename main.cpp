#include "checkout.h"
#include "PaymentModes.h"
#include "PaymentRegistry.h"
#include "PaymentProcessors.h"
#include "PaymentRegistration.h"
#include <memory>
#include <iostream>
#include <string>

int main() {
    registerProcessors();

    double amount = 150.75;
    checkout(PaymentMode::PayPal, amount);
    checkout(PaymentMode::GooglePay, amount);
    checkout(PaymentMode::CreditCard, amount);
    checkout(PaymentMode::Unknown, amount);

    return 0;
}
