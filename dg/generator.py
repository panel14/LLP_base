import random
import string
import sys


def generate_random_string():
    length = random.randrange(5, 20)
    letters = string.ascii_lowercase
    rand_string = ''.join(random.choice(letters) for i in range(length))
    return rand_string


def generate_random_int():
    return random.randrange(10, 100000)


def generate_random_bool():
    res = random.randint(0, 1)
    if res == 1:
        return True
    else:
        return False


def generate_random_float():
    return random.uniform(1, 50)


def generate_item(pattern, available_parents):
    item = ''
    if len(available_parents) != 0:
        random_index = random.randint(0, len(available_parents) - 1)
        item += str(available_parents[random_index]) + " "
    else:
        item += "0 "

    for key in pattern:
        item += key + "=" + str(types_generators[pattern[key]]()) + " "

    return item


available_types = ["string", "int", "float", "bool"]
types = {}
types_generators = {"string": generate_random_string,
                    "int": generate_random_int,
                    "bool": generate_random_bool,
                    "float": generate_random_float}
parents = []

if __name__ == '__main__':
    if sys.argv[1] == 'help':
        print("Input format:\npy generator.py <count> <field name>=<field type> ... <output>\n"
              "Possible types: string, int, float, bool\n"
              "<output> - name of output file with extension")
        exit(0)
    for param in sys.argv[2:]:
        key_value = param.split('=')
        if len(key_value) != 2:
            print("Wrong input")
        if param.split('=')[1] in available_types:
            types[param.split('=')[0]] = param.split('=')[1]
        else:
            print("Wrong type")

    with open(sys.argv[3], 'w') as f:
        for i in range(int(sys.argv[1])):
            f.write(generate_item(types, parents)[:-1])
            parents.append(i)
            f.write("\n")
            print("Successful!")
