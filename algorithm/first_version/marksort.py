#More otimized than the first C version

from random import randint

NUMERICAL_RANGE = 1000
NUM_VALUES = 1000

def get_min_and_max(vector):
    min_value = vector[0]
    max_value = min_value
    for i in vector:
        min_value = min(i, min_value)
        max_value = max(i, max_value)
    return min_value, max_value

def read_values():
    n = int(input())
    vector = []
    min_value = int(input())
    vector.append(min_value)
    max_value = min_value
    for i in range(n-1):
        value = int(input())
        min_value = min(value, min_value)
        max_value = max(value, max_value)
        vector.append(value)
    return vector, max_value, min_value

def fill_appears(vector, max_value, min_value):
    numbers_appears = [None] * len(vector)
    for i in vector:
        pos = i - min_value
        if numbers_appears[pos] != None:
            if type(numbers_appears[pos]) == type(True):
                numbers_appears[pos] = 2
            else:
                numbers_appears[pos] += 1
        else:
            numbers_appears[pos] = True
    return numbers_appears

def fill_result_vector(numbers_appears, min_value):
    result = []
    cont = min_value
    for i in numbers_appears:
        if i != None:
            if i == True:
                result.append(cont)
            else:
                while i != 0:
                    result.append(cont)
                    i -= 1
        cont += 1
    return result

def main():
    opt = int(input("MarkSort\n1 = random\n2 = user input\n> "))
    if opt == 1:
        vector = [randint(0, NUMERICAL_RANGE) for i in range(NUM_VALUES)]
        min_value, max_value = get_min_and_max(vector)
        numbers_appears = fill_appears(vector, max_value, min_value)
        result = fill_result_vector(numbers_appears, min_value)
        print(result)
    elif opt == 2:
        vector, max_value, min_value = read_values()
        numbers_appears = fill_appears(vector, max_value, min_value)
        result = fill_result_vector(numbers_appears, min_value)
        print(result)

if __name__ == "__main__":
    main()
