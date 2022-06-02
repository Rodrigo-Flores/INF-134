import random

def main ():
    with open('numbers.txt', 'w') as f:
        for i in range(1000000):
            f.write(str(random.randint(1, 1000000)) + '\n')

def generate_insert():
    with open('insert.txt', 'w') as f:
        for i in range(1000000):
            f.write(f"arbol.insert({str(random.randint(1, 1000000))});\n")

if __name__ == "__main__":
    generate_insert()
            