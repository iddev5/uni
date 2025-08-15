class DisneyHotstarSubscription:
    def __init__(self, username, password):
        self.username = username
        self.password = password
        self.active_devices = [] # Track active devices

    def display_subscription_details(self):
        print("Disney+ Hotstar Subscription Details:")
        print(f"Username: {self.username}")
        print(f"Active Devices: {self.active_devices}")

    def login(self, device_id):
        # if device_id not in self.active_devices:
            self.active_devices.append(device_id)
            print(f"{self.username} logged in on device {device_id}.")

    def logout(self, device_id):
        # if device_id in self.active_devices:
            self.active_devices.remove(device_id)
            print(f"{self.username} logged out from device {device_id}.")

    def logout_all(self):
        self.active_devices = []
        print(f"{self.username} logged out from all devices.")

class PremiumDisneyHotstarSubscription(DisneyHotstarSubscription):
    def __init__(self, username, password, livematch_broadcasting):
        super().__init__(username, password)
        self.livematch_broadcasting = livematch_broadcasting
        self.live_match_running = False
        self.live_match_device = None # Track device watching live match

    def display_premium_details(self):
        super().display_subscription_details()
        print("Premium Features:")
        print(f"Live Match Broadcasting: {self.livematch_broadcasting}")

    def watch_live_match(self, device_id):
        if self.livematch_broadcasting:
            if not self.live_match_running:
                if device_id in self.active_devices:
                    print(f"{self.username} is watching live match on device {device_id}.")
                    self.live_match_running = True
                    self.live_match_device = device_id
                else:
                    print(f"{self.username} must be logged in on device {device_id} to watch live match")
            else:
                if device_id != self.live_match_device:
                    print(f"Live match is already running on device {self.live_match_device}. Logging out all devices.")
                    self.logout_all()
                else:
                    print(f"{self.username} is already watching on device {device_id}")

        else:
            print("Live match broadcasting is not available in this subscription.")


# Example Usage
premium_sub = PremiumDisneyHotstarSubscription("premium_user", "securepass", True)

premium_sub.login(1)
premium_sub.login(2)
premium_sub.watch_live_match(1)
premium_sub.watch_live_match(2) # Try to watch on another device