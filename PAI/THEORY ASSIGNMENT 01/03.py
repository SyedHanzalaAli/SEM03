class Package:
    def __init__(self, packageId, weightInKg):
        self.packageId = packageId
        self.weightInKg = weightInKg

    def __str__(self):
        return f"Package({self.packageId}, {self.weightInKg}kg)"


class Drone:
    def __init__(self, droneId, maxLoadInKg):
        self.droneId = droneId
        self.maxLoadInKg = maxLoadInKg
        self._status = 'idle'
        self.currentPackage = None
        self.timer = 0

    def getStatus(self):
        return self._status

    def setStatus(self, newStatus):
        allowed = ['idle', 'delivering', 'charging']
        if newStatus in allowed:
            self._status = newStatus
        else:
            print(f"Invalid status '{newStatus}' for drone {self.droneId}")

    def assignPackage(self, packageObj):
        if self._status == 'idle' and packageObj.weightInKg <= self.maxLoadInKg:
            self.currentPackage = packageObj
            self.setStatus('delivering')
            self.timer = 2
            print(f"Drone {self.droneId} started delivering {packageObj.packageId}")
            return True
        else:
            print(f"Drone {self.droneId} cannot take {packageObj.packageId}")
            return False

    def updateState(self):
        if self._status == 'delivering':
            self.timer -= 1
            if self.timer <= 0:
                print(f"Drone {self.droneId} finished delivery of {self.currentPackage.packageId}")
                self.currentPackage = None
                self.setStatus('charging')
                self.timer = 2
        elif self._status == 'charging':
            self.timer -= 1
            if self.timer <= 0:
                print(f"Drone {self.droneId} finished charging and is now idle")
                self.setStatus('idle')


class FleetManager:
    def __init__(self):
        self.drones = {}
        self.pendingPackages = []

    def addDrone(self, drone):
        self.drones[drone.droneId] = drone

    def addPackage(self, package):
        self.pendingPackages.append(package)

    def dispatchJobs(self):
        for drone in self.drones.values():
            if drone.getStatus() == 'idle' and self.pendingPackages:
                package = self.pendingPackages.pop(0)
                success = drone.assignPackage(package)
                if not success:
                    self.pendingPackages.insert(0, package)

    def simulationTick(self):
        print("\n=== Simulation Tick ===")
        for drone in self.drones.values():
            drone.updateState()
        self.dispatchJobs()


if __name__ == "__main__":
    manager = FleetManager()
    manager.addDrone(Drone("D1", 5))
    manager.addDrone(Drone("D2", 10))
    manager.addPackage(Package("P1", 3))
    manager.addPackage(Package("P2", 8))
    manager.addPackage(Package("P3", 4))

    for tick in range(6):
        print(f"\n--- Tick {tick+1} ---")
        manager.simulationTick()
