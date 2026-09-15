#include <>
using namespace std;

int main() {
    int accountType, transaction;
    double balance, amount;

    cout << "===== Banking Terminal =====" << endl;

    // Account selection
    cout << "\nSelect Account Category:" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Current Account" << endl;
    cout << "3. Student Account" << endl;
    cout << "Enter your choice: ";
    cin >> accountType;

    // Input validation for account type
    if (accountType < 1 || accountType > 3) {
        cout << "Invalid account category!" << endl;
        return 0;
    }

    cout << "Enter available balance: Rs. ";
    cin >> balance;

    if (balance < 0) {
        cout << "Invalid balance!" << endl;
        return 0;
    }

    // Transaction selection
    cout << "\nSelect Transaction:" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdrawal" << endl;
    cout << "3. Balance Inquiry" << endl;
    cout << "Enter your choice: ";
    cin >> transaction;

    // Input validation for transaction
    if (transaction < 1 || transaction > 3) {
        cout << "Invalid transaction choice!" << endl;
        return 0;
    }

    // Nested switch
    switch (accountType) {

        case 1: // Savings Account
            cout << "\n--- Savings Account ---" << endl;

            switch (transaction) {
                case 1: // Deposit
                    cout << "Enter deposit amount: Rs. ";
                    cin >> amount;

                    if (amount > 0) {
                        balance += amount;
                        cout << "Deposit successful!" << endl;
                        cout << "New balance: Rs. " << balance << endl;
                    } else {
                        cout << "Invalid deposit amount!" << endl;
                    }
                    break;

                case 2: // Withdrawal
                    cout << "Enter withdrawal amount: Rs. ";
                    cin >> amount;

                    if (amount > 0 && amount <= balance) {
                        balance -= amount;
                        cout << "Withdrawal successful!" << endl;
                        cout << "Remaining balance: Rs. " << balance << endl;
                    } else {
                        cout << "Withdrawal denied! Insufficient balance." << endl;
                    }
                    break;

                case 3: // Balance Inquiry
                    cout << "Current balance: Rs. " << balance << endl;
                    break;
            }
            break;

        case 2: // Current Account
            cout << "\n--- Current Account ---" << endl;

            switch (transaction) {
                case 1: // Deposit
                    cout << "Enter deposit amount: Rs. ";
                    cin >> amount;

                    if (amount > 0) {
                        balance += amount;
                        cout << "Deposit successful!" << endl;
                        cout << "New balance: Rs. " << balance << endl;
                    } else {
                        cout << "Invalid deposit amount!" << endl;
                    }
                    break;

                case 2: // Withdrawal
                    cout << "Enter withdrawal amount: Rs. ";
                    cin >> amount;

                    // Balance + overdraft limit = maximum withdrawal
                    if (amount > 0 && amount <= balance + 50000) {
                        balance -= amount;
                        cout << "Withdrawal successful!" << endl;
                        cout << "Remaining balance: Rs. " << balance << endl;
                    } else {
                        cout << "Withdrawal denied! Overdraft limit exceeded." << endl;
                    }
                    break;

                case 3: // Balance Inquiry
                    cout << "Current balance: Rs. " << balance << endl;
                    break;
            }
            break;

        case 3: // Student Account
            cout << "\n--- Student Account ---" << endl;

            switch (transaction) {
                case 1: // Deposit
                    cout << "Enter deposit amount: Rs. ";
                    cin >> amount;

                    if (amount > 0) {
                        balance += amount;
                        cout << "Deposit successful!" << endl;
                        cout << "New balance: Rs. " << balance << endl;
                    } else {
                        cout << "Invalid deposit amount!" << endl;
                    }
                    break;

                case 2: // Withdrawal
                    cout << "Enter withdrawal amount: Rs. ";
                    cin >> amount;

                    // Rs. 50 service charge
                    if (amount > 0 && balance - amount - 50 >= 2000) {
                        balance = balance - amount - 50;

                        cout << "Withdrawal successful!" << endl;
                        cout << "Service charge: Rs. 50" << endl;
                        cout << "Remaining balance: Rs. " << balance << endl;
                    } else {
                        cout << "Withdrawal denied!" << endl;
                        cout << "Balance must be at least Rs. 2,000 after withdrawal and service charge." << endl;
                    }
                    break;

                case 3: // Balance Inquiry
                    cout << "Current balance: Rs. " << balance << endl;
                    break;
            }
            break;
    }

    cout << "\nThank you for using the banking terminal!" << endl;

    return 0;
}
