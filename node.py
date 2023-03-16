class node:
    collector = 0.0
    connections = []

    def __init__(self,connections):
        self.connections = connections
        self.collector = 0.0
    def set_collector(self, collect):
        self.collector = collect
    def __str__(self):
        return str(self.collector)
