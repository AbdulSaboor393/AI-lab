class FireEnvironment:
    def __init__(self):
        self.rooms = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i']
        self.status = {
            'a': 'Safe', 'b': 'Safe', 'c': 'Fire',
            'd': 'Safe', 'e': 'Fire', 'f': 'Safe',
            'g': 'Safe', 'h': 'Safe', 'i': 'Fire'
        }
        self.path = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i']
    
    def display_grid(self, robot_position=None):
        grid = []
        for i in range(0, 9, 3):
            row = []
            for j in range(3):
                room = self.rooms[i + j]
                if robot_position == room:
                    symbol = '🤖'
                elif self.status[room] == 'Fire':
                    symbol = '🔥'
                else:
                    symbol = '⬜'
                row.append(symbol)
            grid.append(' | '.join(row))
        
        print('\n' + '\n---------\n'.join(grid) + '\n')
    
    def extinguish_fire(self, room):
        if self.status[room] == 'Fire':
            self.status[room] = 'Safe'
            return True
        return False

class FireRobot:
    def __init__(self, environment):
        self.position = 'a'
        self.environment = environment
        self.fires_extinguished = 0
    
    def move_to(self, room):
        print(f"Moving to room {room}")
        self.position = room
    
    def check_for_fire(self):
        if self.environment.status[self.position] == 'Fire':
            print(f"🔥 FIRE DETECTED in room {self.position}!")
            self.environment.extinguish_fire(self.position)
            self.fires_extinguished += 1
            print(f"✓ Fire extinguished in room {self.position}")
        else:
            print(f"Room {self.position} is safe")
    
    def run_mission(self):
        print("=== Firefighting Robot Mission Started ===")
        print("\nInitial Building State:")
        self.environment.display_grid()
        
        for room in self.environment.path:
            self.move_to(room)
            self.check_for_fire()
            self.environment.display_grid(self.position)
        
        print(f"\n=== Mission Complete! ===")
        print(f"Total fires extinguished: {self.fires_extinguished}")
        print("\nFinal Building State:")
        self.environment.display_grid()

building = FireEnvironment()
robot = FireRobot(building)
robot.run_mission()
