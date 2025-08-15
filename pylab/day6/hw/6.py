price_list = {'Mango':10,'Banana':20,'Apple':30,'Orange':40}

class ShopingCart:
    def __init__(self):
        self.cart = []

    def add_item(self):
        item = input("Enter the item you want to add: ")
        self.cart.append(item)
        print(f"{item} is added")

    def remove_item(self):
        item=input("Enter the item you want to remove :")
        self.cart.remove(item)
        print(f"{item} is removed")

    def get_total(self):
        total = 0
        for it in self.cart:
            total += price_list[it]
        return total

obj = ShopingCart()
obj.add_item()
obj.add_item()
obj.add_item()
obj.remove_item()
print("Total price is", obj.get_total())