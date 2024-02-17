class Person:
    def set_name(self):
        self.name = "Bob"  # I want this to have type: str | None

    def call_name(self):
        print(self.name)


Person().set_name()
