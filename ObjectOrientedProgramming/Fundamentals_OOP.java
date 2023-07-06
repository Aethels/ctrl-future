// Abstract class representing a bank account
abstract class BankAccount {
    private String accountNumber;
    private double balance;
    private String customerName;
    private String email;
    private String phoneNumber;

    public BankAccount(String accountNumber, double balance, String customerName, String email, String phoneNumber) {
        this.accountNumber = accountNumber;
        this.balance = balance;
        this.customerName = customerName;
        this.email = email;
        this.phoneNumber = phoneNumber;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    public String getCustomerName() {
        return customerName;
    }

    public String getEmail() {
        return email;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }
    // Abstract methods to be implemented by subclasses
    public abstract void deposit(double amount);
    public abstract void withdraw(double amount);
}

// Savings account implementation
class SavingsAccount extends BankAccount {
    private double interestRate;

    public SavingsAccount(String accountNumber, double balance, String customerName, String email, String phoneNumber, double interestRate) {
        super(accountNumber, balance, customerName, email, phoneNumber);
        this.interestRate = interestRate;
    }

    public double getInterestRate() {
        return interestRate;
    }

    @Override
    public void deposit(double amount) {
        if (amount > 0) {
            double interest = amount * interestRate / 100;
            double totalAmount = amount + interest;
            double newBalance = getBalance() + totalAmount;
            setBalance(newBalance);
            System.out.println("Deposit of " + totalAmount + " made. New balance is " + newBalance);
        } else {
            System.out.println("Invalid amount. Deposit amount must be greater than 0.");
        }
    }

    @Override
    public void withdraw(double amount) {
        if (getBalance() >= amount) {
            double newBalance = getBalance() - amount;
            setBalance(newBalance);
            System.out.println("Withdrawal of " + amount + " processed. Remaining balance is " + newBalance);
        } else {
            System.out.println("Insufficient balance. Withdrawal failed.");
        }
    }
}

// Current account implementation
class CurrentAccount extends BankAccount {
    private double overdraftLimit;

    public CurrentAccount(String accountNumber, double balance, String customerName, String email, String phoneNumber, double overdraftLimit) {
        super(accountNumber, balance, customerName, email, phoneNumber);
        this.overdraftLimit = overdraftLimit;
    }

    public double getOverdraftLimit() {
        return overdraftLimit;
    }

    @Override
    public void deposit(double amount) {
        if (amount > 0) {
            double newBalance = getBalance() + amount;
            setBalance(newBalance);
            System.out.println("Deposit of " + amount + " made. New balance is " + newBalance);
        } else {
            System.out.println("Invalid amount. Deposit amount must be greater than 0.");
        }
    }

    @Override
    public void withdraw(double amount) {
        if (getBalance() + overdraftLimit >= amount) {
            double newBalance = getBalance() - amount;
            setBalance(newBalance);
            System.out.println("Withdrawal of " + amount + " processed. Remaining balance is " + newBalance);
        } else {
            System.out.println("Insufficient balance. Withdrawal failed.");
        }
    }
}

// Main class
public class Fundamentals_OOP {
    // Main method for testing the bankaccounts
    public static void main(String[] args) {
        BankAccount savingsAccount = new SavingsAccount("SA001", 1000.0, "John Doe", "john.doe@example.com", "1234567890", 50.0);
        BankAccount currentAccount = new CurrentAccount("CA001", 500.0, "Jane Smith", "jane.smith@example.com", "9876543210", 1000.0);

        savingsAccount.deposit(500.0);
        savingsAccount.withdraw(200.0);

        currentAccount.deposit(300.0);
        currentAccount.withdraw(800.0);
    }
}
