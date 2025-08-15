class BankAccount:
    def __init__(self, accno, balance):
        self.__accno = accno
        self.__balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
            print(f"Deposited {amount}. New balance: {self.__balance}")

    def withdraw(self, amount):
        if 0 < amount <= self.__balance:
            self.__balance -= amount
            print(f"Withdraw {amount}. New balance: {self.__balance}")
        else:
            print("Insufficient funds")

    def get_balance(self):
        return self.__balance
    

account = BankAccount('231267358132', 4500)
account.deposit(500)
account.withdraw(200)
print(f"Current balance: {account.get_balance()}")