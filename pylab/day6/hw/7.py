class DisneyHotstarSubscription:
    def __init__(self, username, password, num_devices, num_screens, screenshare):
        self.username = username
        self.password = password
        self.num_devices = num_devices
        self.num_screens = num_screens
        self.screenshare = screenshare

    def display_subscription_details(self):
        print("Disney+ Hotstar Subscription Details:")
        print(f"Username: {self.username}")
        print(f"Number of Devices: {self.num_devices}")
        print(f"Number of Screens: {self.num_screens}")
        print(f"Screenshare Allowed: {self.screenshare}")

class PremiumDisneyHotstarSubscription(DisneyHotstarSubscription):
    def __init__(self, username, password, num_devices, num_screens, screenshare, livematch_broadcasting, premier_show, exclusive_release_time):
        super().__init__(username, password, num_devices, num_screens, screenshare)
        self.livematch_broadcasting = livematch_broadcasting
        self.premier_show = premier_show
        self.exclusive_release_time = exclusive_release_time
        self.live_match_running = False #added to track live match status
        self.premier_show_users = {} #added to track premier show users and isps
        self.first_owner = username # stores first owner of the subscription.

    def display_premium_details(self):
        super().display_subscription_details()
        print("Premium Features:")
        print(f"Live Match Broadcasting: {self.livematch_broadcasting}")
        print(f"Premier Shows: {self.premier_show}")
        print(f"Exclusive Release Time (First Day Web Series): {self.exclusive_release_time}")

    def watch_live_match(self, device_id):
        if self.livematch_broadcasting:
            if not self.live_match_running:
                print(f"{self.username} is watching live match on device {device_id}.")
                self.live_match_running = True
            else:
                print("Live match is already running on another device.")
        else:
            print("Live match broadcasting is not available in this subscription.")

    def stop_live_match(self):
        if self.live_match_running:
            print(f"{self.username} stopped watching live match.")
            self.live_match_running = False
        else:
            print("No live match is currently running.")

    def watch_premier_show(self, device_id, isp):
        if self.premier_show:
            if device_id in self.premier_show_users:
                if self.premier_show_users[device_id] == isp:
                    print("Cannot watch premier show on same ISP with same device at same time.")
                else:
                    print(f"{self.username} is watching premier show on device {device_id} using ISP: {isp}.")
                    self.premier_show_users[device_id] = isp
            else:
                print(f"{self.username} is watching premier show on device {device_id} using ISP: {isp}.")
                self.premier_show_users[device_id] = isp
        else:
            print("Premier shows are not available in this subscription.")

    def watch_exclusive_release(self, device_id, username):
        if self.exclusive_release_time:
            if username == self.first_owner:
                if device_id <= 1:
                    print(f"{username} is watching exclusive release on their own device.")
                else:
                    print(f"Exclusive release can only be viewed on one device by the first owner.")
            else:
                print("Exclusive release is only for the first owner of the subscription.")
        else:
            print("Exclusive releases are not available in this subscription.")

basic_sub = DisneyHotstarSubscription("Suraj", "password123", 2, 1, False)
basic_sub.display_subscription_details()

print("\n")

premium_sub = PremiumDisneyHotstarSubscription("Tushar", "securepass", 4, 2, True, True, True, "9:00 AM")
premium_sub.display_premium_details()

print("\n")

premium_sub.watch_live_match(1)
premium_sub.watch_live_match(2)
premium_sub.stop_live_match()
# premium_sub.watch_live_match(3)

print("\n")
premium_sub.watch_premier_show(1, "Jio")
# premium_sub.watch_premier_show(2, "Vi")
# premium_sub.watch_premier_show(1, "Airtel")

print("\n")
premium_sub.watch_exclusive_release(1, "Tushar")
# premium_sub.watch_exclusive_release(2, "Tushar")
# premium_sub.watch_exclusive_release(1, "Pritam")