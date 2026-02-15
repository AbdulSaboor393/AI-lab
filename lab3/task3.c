import random

class BackupTask:
    def __init__(self, name):
        self.name = name
        self.status = random.choice(['Completed', 'Failed'])
    
    def retry(self):
        self.status = 'Completed'

class BackupAgent:
    def __init__(self, tasks):
        self.tasks = tasks
    
    def scan_and_retry(self):
        failed_tasks = []
        for task in self.tasks:
            if task.status == 'Failed':
                failed_tasks.append(task)
        
        if failed_tasks:
            print(f"Found {len(failed_tasks)} failed backups. Retrying...")
            for task in failed_tasks:
                task.retry()
                print(f"Retried {task.name}: Now Completed")
        else:
            print("All backups completed successfully!")

tasks = [BackupTask(f"Backup {i+1}") for i in range(6)]

print("Initial Backup Status:")
for task in tasks:
    print(f"{task.name}: {task.status}")

agent = BackupAgent(tasks)
agent.scan_and_retry()

print("\nFinal Backup Status:")
for task in tasks:
    print(f"{task.name}: {task.status}")
