import random

class Environment:
    def __init__(self):
        self.components = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I']
        self.status = {}
        for comp in self.components:
            self.status[comp] = random.choice(['Safe', 'Low Risk Vulnerable', 'High Risk Vulnerable'])
    
    def get_percept(self, component):
        return self.status[component]
    
    def patch_low_risk(self, component):
        if self.status[component] == 'Low Risk Vulnerable':
            self.status[component] = 'Safe'

class UtilityAgent:
    def __init__(self):
        self.utilities = {
            'Safe': 10,
            'Low Risk Vulnerable': -5,
            'High Risk Vulnerable': -20
        }
    
    def calculate_utility(self, percept):
        return self.utilities[percept]
    
    def scan_and_patch(self, environment):
        total_utility = 0
        for comp in environment.components:
            percept = environment.get_percept(comp)
            utility = self.calculate_utility(percept)
            total_utility += utility
            
            if percept == 'Low Risk Vulnerable':
                print(f"WARNING: Component {comp} has LOW risk vulnerability - Patching...")
                environment.patch_low_risk(comp)
            elif percept == 'High Risk Vulnerable':
                print(f"CRITICAL: Component {comp} has HIGH risk vulnerability - Premium service required!")
            else:
                print(f"SUCCESS: Component {comp} is safe.")
        
        print(f"\nTotal System Utility: {total_utility}")
        return total_utility

environment = Environment()
agent = UtilityAgent()

print("Initial System State:")
for comp in environment.components:
    print(f"Component {comp}: {environment.status[comp]}")

print("\n--- System Scan ---")
final_utility = agent.scan_and_patch(environment)

print("\nFinal System State:")
for comp in environment.components:
    print(f"Component {comp}: {environment.status[comp]}")
