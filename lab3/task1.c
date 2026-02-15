import random

class Environment:
    def __init__(self):
        self.components = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I']
        self.status = {}
        for component in self.components:
            self.status[component] = random.choice(['Safe', 'Vulnerable'])
    
    def get_percept(self, component):
        return self.status[component]
    
    def patch_component(self, component):
        self.status[component] = 'Safe'

class SecurityAgent:
    def __init__(self):
        self.vulnerable_list = []
    
    def scan_component(self, percept, component):
        if percept == 'Vulnerable':
            print(f"WARNING: Component {component} is vulnerable!")
            self.vulnerable_list.append(component)
        else:
            print(f"SUCCESS: Component {component} is secure.")
    
    def patch_all(self, environment):
        print("\n--- Patching Vulnerabilities ---")
        for component in self.vulnerable_list:
            environment.patch_component(component)
            print(f"Component {component} has been patched.")

environment = Environment()
agent = SecurityAgent()

print("Initial System State:")
for comp in environment.components:
    print(f"Component {comp}: {environment.status[comp]}")

print("\n--- System Scan ---")
for comp in environment.components:
    percept = environment.get_percept(comp)
    agent.scan_component(percept, comp)

agent.patch_all(environment)

print("\nFinal System State:")
for comp in environment.components:
    print(f"Component {comp}: {environment.status[comp]}")
