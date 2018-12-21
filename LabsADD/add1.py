import pay as pay


def hello_user():
    print("Enter name")
    name = input()
    print("Hello " + name)


def celsium_to_farengeit(celsium):
    return round(celsium * 9 / 5 + 32, 2)


def console_ctf():
    print("Температура по шкале Цельсия:")
    try:
        degree = float(input())
        print("Температура по шкале Фаренгейта:" + str(celsium_to_farengeit(degree)))
    except ValueError:
        print("Incorrect arg")


# 4. Ввести три числа a, b, c. Подвоїти кожне з них, якщо  a>=b>=c, інакше поміняти значення a  та b.
def lab1(a, b, c):
    if a >= b >= c:
        res = [a, b, c]
        res = [i * 2 for i in res]
        return res


def lab1_to_b(number, system):
    if system == 2:
        return bin(number)
    if system == 8:
        return oct(number)
    if system == 16:
        return hex(number)
    else:
        return "Неподдерживаемая система счисления"


def lab1_from_b(number):
    l = list(number)
    l.reverse()
    sum = 0
    i = 0
    for it in l:
        if it == '0' or it == '1':
            sum += int(it) * 2 ^ i
            i += 1
        else:
            raise ValueError()
    return sum


def console_lab1():
    print("Enter a:")
    a = input()
    print("Enter b:")
    b = input()
    print("Enter c:")
    c = input()
    try:
        a = float(a)
        b = float(b)
        c = float(c)
        res = lab1(a, b, c)
        print(res)
    except ValueError:
        print("Incorrect args")


def console_b():
    print("Enter system base:")
    b = input()
    print("Enter number:")
    num = input()
    try:
        b = int(b)
        num = int(num)
        res = lab1_to_b(num, b)
        print(res)
    except ValueError:
        print("Incorrect args")


def console_dec():
    print("Enter bin:")
    number = input()
    try:
        print(lab1_from_b(number))
    except ValueError:
        print("Incorrect arg")


def max(a, b):
    if a > b:
        return a
    else:
        return b


def console_max():
    print("Enter a:")
    a = input()
    print("Enter b:")
    b = input()
    try:
        a = float(a)
        b = float(b)
        print("Max " + str(max(a,b)))
    except ValueError:
        print("Incorrect arg")


def console_menu():
    print("We have 9 command для возведения в степень")
    print("Enter command:")
    c = input()
    print("Enter number:")
    n = input()
    try:
        c = float(c)
        n = float(n)
        if 1 <= c <= 9:
            print(str(pow(n, c)))
        else:
            raise ValueError()
    except ValueError:
        print("Incorrect args")


def prod31(mass: list):
    prod = 0
    c = 0
    while c < len(mass):
        if mass[c] // 3:
            if prod == 0:
                prod = c
            else:
                prod *= c
    return prod


def prod3(mass: list):
    prod = 0
    for i in mass:
        if i // 3:
            if prod == 0:
                prod = i
            else:
                prod *= i
    return prod


if __name__ == "__main__":
    hello_user()
    print("lab1 1")
    console_lab1()
    print("lab1 2")
    console_b()
    print("lab1 3")
    console_dec()
    print("lab2 1")
    console_max()
    print("lab2 2")
    console_menu()
    print("Prod: " + str(prod3([9, 2, 3, 4])))
    pay.console_pay()
    console_ctf()
