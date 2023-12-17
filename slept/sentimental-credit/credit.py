#American Express uses 15-digit numbers \\ start with 34 or 37
#MasterCard uses 16-digit numbers \\ start with 51, 52, 53, 54, or 55
#Visa uses 13- and 16-digit numbers \\ start with 4

def check_sum(card):
    card = str(card)
    card = card[::-1]
    sum = 0
    for i in range(len(card)):
        if i % 2 == 0:
            sum += int(card[i])
        else:
            sum += int(card[i]) * 2
            if int(card[i]) * 2 > 9:
                sum -= 9
    if sum % 10 == 0:
        return True
    else:
        return False
card = input("Number: ")
if len(card) == 15:
    if card[0:2] == "34" or card[0:2] == "37":
        if check_sum(card):
            print("AMEX")
        else:
            print("INVALID")
    else:
        print("INVALID")
elif len(card) == 16:
    if card[0:2] == "51" or card[0:2] == "52" or card[0:2] == "53" or card[0:2] == "54" or card[0:2] == "55":
        if check_sum(card):
            print("MASTERCARD")
        else:
            print("INVALID")
    elif card[0] == "4":
        if check_sum(card):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")
elif len(card) == 13:
    if card[0] == "4":
        if check_sum(card):
            print("VISA")
        else:
            print("INVALID")
    else:
            print("INVALID")
else:
    print("INVALID")
