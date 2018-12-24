def pay(hours, rate):
    return round(hours * rate, 2);


def console_pay():
    print("Enter hours:")
    hours = input()  # row_input in Python3
    print("Enter rate:")
    rate = input()
    try:
        hours = float(hours)
        rate = float(rate)
        print("Pay:" + str(pay(hours, rate)))
    except ValueError:
        print("Incorrect args")