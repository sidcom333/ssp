class SymbolTable:
    def __init__(self):
        self.symbols = {}

    def insert(self, name, value, variable_type, size):
        self.symbols[name] = {
            'value': value,
            'type': variable_type,
            'size': size
        }

    def lookup(self, name):
        return self.symbols.get(name, None)

    def display(self):
        print("Symbol Table:")
        print("{:<10} {:<15} {:<10} {:<5}".format("Variable", "Value", "Type", "Size"))
        print("-" * 40)
        for name, info in self.symbols.items():
            value = info['value']
            variable_type = info['type']
            size = info['size']
            print("{:<10} {:<15} {:<10} {:<5}".format(name, value, variable_type, size))

# Example usage:
if __name__ == "__main__":
    symbol_table = SymbolTable()

    # Inserting variables into the symbol table
    
    
    
    symbol_table.insert("w", 20.5, "float", 8)
    symbol_table.insert("x", 10, "int", 4)
    symbol_table.insert("y", 20, "int", 4)
   
    symbol_table.insert("z", "Hello, World!", "str", len("Hello, World!"))

    # Looking up variables in the symbol table
    print("Value of w:", symbol_table.lookup("w"))
    print("Value of x:", symbol_table.lookup("x"))
    print("Value of y:", symbol_table.lookup("y"))
    print("Value of z:", symbol_table.lookup("z"))

    # Displaying the entire symbol table
    symbol_table.display()
