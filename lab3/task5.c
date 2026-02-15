class HospitalEnvironment:
    def __init__(self):
        self.locations = ['Medicine Storage', 'Room 101', 'Room 102', 'Room 103', 'Nurse Station']
        self.medicines = {
            'Room 101': 'Paracetamol',
            'Room 102': 'Antibiotic',
            'Room 103': 'Insulin'
        }
        self.patient_schedules = {
            'Room 101': '09:00 AM',
            'Room 102': '10:30 AM',
            'Room 103': '02:00 PM'
        }
        self.delivery_status = {room: 'Pending' for room in self.medicines.keys()}
    
    def get_pending_deliveries(self):
        pending = []
        for room, status in self.delivery_status.items():
            if status == 'Pending':
                pending.append(room)
        return pending

class DeliveryRobot:
    def __init__(self, environment):
        self.position = 'Medicine Storage'
        self.inventory = []
        self.environment = environment
    
    def pick_up_medicine(self, room):
        medicine = self.environment.medicines[room]
        self.inventory.append(medicine)
        print(f"Picked up {medicine} for {room}")
    
    def move_to(self, location):
        print(f"Moving from {self.position} to {location}")
        self.position = location
    
    def scan_patient_id(self, room):
        print(f"Scanning patient ID at {room}... Verification successful!")
    
    def deliver_medicine(self, room):
        if self.inventory:
            medicine = self.inventory.pop(0)
            print(f"Delivering {medicine} to {room}")
            self.environment.delivery_status[room] = 'Delivered'
            self.scan_patient_id(room)
    
    def alert_staff(self, room):
        print(f"ALERT: Staff assistance needed at {room}!")
    
    def execute_goal(self):
        print("=== Hospital Delivery Robot Starting ===")
        pending_rooms = self.environment.get_pending_deliveries()
        
        for room in pending_rooms:
            self.move_to('Medicine Storage')
            self.pick_up_medicine(room)
            self.move_to(room)
            self.deliver_medicine(room)
            
            if room == 'Room 103':
                self.alert_staff(room)
            
            print(f"Delivery completed for {room} at {self.environment.patient_schedules[room]}\n")

hospital = HospitalEnvironment()
robot = DeliveryRobot(hospital)
robot.execute_goal()

print("Final Delivery Status:")
for room, status in hospital.delivery_status.items():
    print(f"{room}: {status}")
