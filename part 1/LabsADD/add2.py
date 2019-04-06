import pay as pay


def score(number):
    number = round(number, 2)
    if number * 100 // 5:
        number = round((number + 0.1), 1) * 10
    else:
        number = round(number, 1) * 10
    #A = [95, 100]
    #B = [85, 95)
    #C = [75, 85)
    #D = [65, 75)
    #E = [60, 65)
    #F = [0, 60)
    dict = {10: "A", 9: "B", 8: "C", 7: "D", 6: "E"}
    if 0 <= number <= 10:
        val = dict[number]
        if val is not None:
            return val
        else:
            return "F"
    else:
        raise ValueError


def console_score():
    print("Enter score:")
    try:
        n = float(input())
        print(score(n))
    except ValueError:
        print("Bad score")


def file_row_sum():
    try:
        sum = 0
        with open("test.in", 'r') as file:
            for line in file:
                try:
                    sum += int(line)
                except ValueError:
                    continue
        with open("test.out", "w+") as file:
            file.write(str(sum))
    except FileNotFoundError:
        print("File do not found")


if __name__ == "__main__":
    pay.console_pay()
    console_score()
    file_row_sum()

