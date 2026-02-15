import random

class Server:
    def __init__(self, name):
        self.name = name
        self.load = random.choice(['Underloaded', 'Balanced', 'Overloaded'])
    
    def update_load(self, new_load):
        self.load = new_load

class LoadBalancer:
    def __init__(self, servers):
        self.servers = servers
    
    def scan_and_balance(self):
        overloaded = []
        underloaded = []
        
        for server in self.servers:
            if server.load == 'Overloaded':
                overloaded.append(server)
            elif server.load == 'Underloaded':
                underloaded.append(server)
        
        while overloaded and underloaded:
            overloaded[0].update_load('Balanced')
            underloaded[0].update_load('Balanced')
            print(f"Moved tasks from {overloaded[0].name} to {underloaded[0].name}")
            overloaded.pop(0)
            underloaded.pop(0)

servers = [Server(f"Server {i+1}") for i in range(5)]

print("Initial Server Loads:")
for server in servers:
    print(f"{server.name}: {server.load}")

balancer = LoadBalancer(servers)
balancer.scan_and_balance()

print("\nUpdated Server Loads:")
for server in servers:
    print(f"{server.name}: {server.load}")
